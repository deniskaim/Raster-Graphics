#include "ImageFactory.h"

#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
#include <fstream>

Image* imageFactory()
{
	MyString fileName = readString();
	MyString extension = getExtension(fileName);
	try
	{
		if (extension == "pbm")
		{
			DynamicSet* set = readBitMapPixels(fileName);
			return new PBMImage(std::move(*set), fileName); 
		}
		else if (extension == "pgm")
		{
			MyVector<uint8_t>* pixels = readGrayMapAndPixMapPixels(fileName);
			return new PGMImage(std::move(*pixels), fileName);
		}
		else if (extension == "ppm")
		{
			MyVector<uint8_t>* pixels = readGrayMapAndPixMapPixels(fileName);
			return new PPMImage(std::move(*pixels), fileName);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}
}
static DynamicSet* readBitMapPixels(const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open the PBM file!");

	MyString format = readStringFromFile(ifs);
	if (format == "P1")
		return readBitMapPixelsFromASCIIFile(ifs);
	else
		throw std::logic_error("Incorrect format for a PBM file!");
}
static DynamicSet* readBitMapPixelsFromASCIIFile(std::ifstream& ifs)
{
	int32_t columns, rows;
	ifs >> columns >> rows;

	size_t pixelsCount = columns * rows;
	DynamicSet* set = new DynamicSet(pixelsCount);

	for (int i = 0; i < pixelsCount; i++)
	{
		int16_t currentPixel = 0;
		ifs >> currentPixel;
		if (currentPixel)
			set->add(i);
	}
	ifs.close();
	return set;
}
static MyVector<uint8_t>* readGrayMapAndPixMapPixels(const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open the PGM / PPM file!");

	MyString format = readStringFromFile(ifs);
	if (format == "P2" || format == "P3")
		return readGrayMapAndPixMapPixelsFromASCIIFile(ifs);
	else
		throw std::logic_error("Incorrect formmat for a PGM / PPM file!");
}
static MyVector<uint8_t>* readGrayMapAndPixMapPixelsFromASCIIFile(std::ifstream& ifs)
{
	int32_t columns, rows;
	ifs >> columns >> rows;

	int32_t maxValueColour;
	ifs >> maxValueColour;


	size_t pixelsCount = columns * rows;
	MyVector<uint8_t>* pixels = new MyVector<uint8_t>;

	for (int i = 0; i < pixelsCount; i++)
	{
		uint8_t currentPixel;
		ifs >> currentPixel;
		pixels->pushBack(currentPixel);
	}
	ifs.close();
	return pixels;
}


static MyString getExtension(const MyString& fileName)
{
	const char* beg = fileName.c_str();
	const char* end = fileName.c_str() + fileName.getSize();
	
	const char* iter = end;
	while (iter != beg && *iter != '.')
		iter--;

	return fileName.substr(iter - beg, end - iter);
}
MyString readString()
{
	const size_t NAME_SIZE = 1024;
	char str[NAME_SIZE];

	std::cin >> str;
	
	return MyString(str);
}
static MyString readStringFromFile(std::ifstream& ifs)
{
	const size_t NAME_SIZE = 1024;
	char str[NAME_SIZE];

	ifs >> str;

	return MyString(str);
}
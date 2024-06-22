#include "ImageFactory.h"

#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
#include <fstream>

Polymorphic_ptr<TransformableImage> imageFactory(const MyString& fileName)
{
	MyString extension = getExtension(fileName);
	MyString format = getFileFormat(fileName);

	if (extension == "pbm")
	{
		return createPBM(fileName, format);
	}
	else if (extension == "pgm")
	{
		return createPGM(fileName, format);
	}
	else if (extension == "ppm")
	{
		return createPPM(fileName, format);
	}

	
	
}
static DynamicSet* readBitMapPixels(const MyString& fileName, const MyString& format)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open the PBM file!");

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

static Polymorphic_ptr<TransformableImage> createPBM(const MyString& fileName, const MyString& format)
{
	DynamicSet* set = readBitMapPixels(fileName, format);
	return new PBMImage(std::move(*set), fileName);
}

static Polymorphic_ptr<TransformableImage> createPPM(const MyString& fileName, const MyString& format)
{
	MyVector<uint8_t>* pixels = readGrayMapAndPixMapPixels(fileName);
	return new PGMImage(std::move(*pixels), fileName);
}
static Polymorphic_ptr<TransformableImage> createPGM(const MyString& fileName, const MyString& format)
{
	MyVector<Pixel>* pixels = readGrayMapAndPixMapPixels(fileName);
	return new PGMImage(std::move(*pixels), fileName);
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
static MyString getFileFormat(const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open the PBM file!");

	MyString format;
	ifs >> format;
	ifs.close();
	return format;
}
#include "ImageFactory.h"

#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
#include <fstream>

static Polymorphic_ptr<TransformableImage> createPBMImageFromASCIIFile(const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open PBM file!");

	MyString format;
	ifs >> format;

	int32_t columns, rows;
	ifs >> columns >> rows;

	size_t pixelsCount = columns * rows;
	DynamicSet set(pixelsCount);

	int bitIndex = 0;
	while (bitIndex < pixelsCount && !ifs.eof())
	{
		char ch = ifs.get();
		if (ch == '0' || ch == '1')
		{
			if (ch == '1')
				set.add(bitIndex);
			bitIndex++;
		}
	}
	ifs.close();
	return new PBMImage(std::move(set),rows, columns, fileName, format);
}
static Polymorphic_ptr<TransformableImage> createPGMImageFromASCIIFile(const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open PGM file!");

	MyString format;
	ifs >> format;

	int32_t columns, rows;
	ifs >> columns >> rows;
	

	uint32_t maxValueColour;
	ifs >> maxValueColour;

	size_t pixelsCount = columns * rows;
	MyVector<uint8_t> pixels;

	for (int i = 0; i < pixelsCount; i++)
	{
		uint32_t currentPixel;
		ifs >> currentPixel;
		pixels.pushBack(static_cast<uint8_t>(currentPixel));
	}
	ifs.close();
	return new PGMImage(std::move(pixels), rows, columns, static_cast<uint8_t>(maxValueColour), fileName, format);
}
static Polymorphic_ptr<TransformableImage> createPPMImageFromASCIIFile(const MyString& fileName)
{

	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open PPM file!");

	MyString format;
	ifs >> format;

	int32_t columns, rows;
	ifs >> columns >> rows;

	uint32_t maxValueColour;
	ifs >> maxValueColour;

	size_t pixelsCount = columns * rows;
	MyVector<Pixel> pixels;

	for (int i = 0; i < pixelsCount; i++)
	{
		Pixel currentPixel;
		ifs >> currentPixel;
		pixels.pushBack(currentPixel);
	}
	ifs.close();
	return new PPMImage(std::move(pixels), rows, columns, static_cast<int8_t>(maxValueColour), fileName, format);
}

static Polymorphic_ptr<TransformableImage> createPBM(const MyString& fileName)
{

	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open the PBM file!");

	MyString format;
	ifs >> format;
	ifs.close();

	if (format == "P1")
		return createPBMImageFromASCIIFile(fileName);
	else
		throw std::logic_error("Incorrect format for a PBM file!");
}

static Polymorphic_ptr<TransformableImage> createPGM(const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open the PGM file!");

	MyString format;
	ifs >> format;
	ifs.close();

	if (format == "P2")
		return createPGMImageFromASCIIFile(fileName);
	else
		throw std::logic_error("Incorrect format for a PGM file!");
}
static Polymorphic_ptr<TransformableImage> createPPM(const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open())
		throw std::exception("Could not open the PPM file!");

	MyString format;
	ifs >> format;
	ifs.close();

	if (format == "P3")
		return createPPMImageFromASCIIFile(fileName);
	else
		throw std::logic_error("Incorrect format for a PPM file!");
}
static MyString getExtension(const MyString& fileName)
{
	const char* beg = fileName.c_str();
	const char* end = fileName.c_str() + fileName.getSize();
	
	const char* iter = end;
	while (iter != beg && *iter != '.')
		iter--;

	return fileName.substr(iter - beg + 1, end - iter - 1);
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

Polymorphic_ptr<TransformableImage> imageFactory(const MyString& fileName)
{
	MyString extension = getExtension(fileName);

	if (extension == "pbm")
	{
		return createPBM(fileName);
	}
	else if (extension == "pgm")
	{
		return createPGM(fileName);
	}
	else if (extension == "ppm")
	{
		return createPPM(fileName);
	}
	else
		throw std::exception("Incorrect extension of the file!");
}
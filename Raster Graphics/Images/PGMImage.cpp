#include "PGMImage.h"
#include <fstream>
PGMImage::PGMImage(const MyVector<uint8_t>& pixels, int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format)
	: pixels(pixels), maxValueColour(maxValueColour),TransformableImage(height, width, fileName, format) {}

PGMImage::PGMImage(MyVector<uint8_t>&& pixels, int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format)
	: pixels(std::move(pixels)), maxValueColour(maxValueColour), TransformableImage(height, width, fileName, format) {}

void PGMImage::applyGrayscale()
{
	// empty
}
void PGMImage::applyMonochrome()
{
	if (isMonochrome)
		return;

	uint8_t middle = static_cast<uint8_t>(maxValueColour / 2);
	size_t pixelsCount = width * height;
	for (size_t i = 0; i < pixelsCount; i++)
	{
		uint8_t monoPixel = static_cast<uint8_t>(pixels[i] > middle ? maxValueColour : 0);
		pixels[i] = monoPixel;
	}
	isMonochrome = true;
}
void PGMImage::applyNegative()
{
	size_t pixelsCount = width * height;
	for (size_t i = 0; i < pixelsCount; i++)
		pixels[i] = maxValueColour - pixels[i];
}

void PGMImage::rotateLeft()
{
	MyVector<uint8_t> rotatedPixels(width * height);

	for (int column = width - 1; column >= 0; column--) 
	{
		for (int row = 0; row < height; row++) 
		{
			rotatedPixels.pushBack(pixels[row * width + column]);
		}
	}
	pixels = std::move(rotatedPixels);
	std::swap(width, height);
}
void PGMImage::rotateRight() 
{
	MyVector<uint8_t> rotatedPixels(width * height);

	for (int column = 0; column < width; column++) 
	{
		for (int row = height - 1; row >= 0; row--) 
		{
			rotatedPixels.pushBack(pixels[row * width + column]);
		}
	}

	pixels = std::move(rotatedPixels);
	std::swap(width, height); 
}
void PGMImage::serialize(const MyString& fileName) const
{
	if (format == "P2")
		serializeInASCII(fileName);
}
void PGMImage::serializeInASCII(const MyString& fileName) const
{
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open())
		throw std::exception("Could not open the file!");

	ofs << format << '\n';
	ofs << width << " " << height << '\n';
	ofs << static_cast<uint32_t> (maxValueColour) << '\n';

	size_t pixelsCount = width * height;
	for (size_t i = 0; i < pixelsCount; i++)
	{
		ofs << static_cast<uint32_t>(pixels[i]);
		if ((i + 1) % width == 0)
			ofs << '\n';
		else
			ofs << " ";
	}
	ofs.close();
}
void PGMImage::collageHorizontallyInNewFile(const TransformableImage* other, const MyString& fileName) const
{
	other->collageHorizontallyWithPGM(this, fileName);
}
void PGMImage::collageVerticallyInNewFile(const TransformableImage* other, const MyString& fileName) const
{
	other->collageVerticallyWithPGM(this, fileName);
}
void PGMImage::collageHorizontallyWithPBM(const PBMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.pgm and .pbm)");
}
void PGMImage::collageHorizontallyWithPGM(const PGMImage* other, const MyString& fileName) const
{
	if (this->height != other->height) 
		throw std::runtime_error("Images must have the same height to be collaged horizontally");
	
	if (maxValueColour != other->maxValueColour)
		throw std::runtime_error("Image must have the same max colour value to be collaged together!");

	int32_t newWidth = width + other->width;
	MyVector<uint8_t> newPixelValues;

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			newPixelValues.pushBack(pixels[i * width + j]);
		}
		for (int j = 0; j < other->width; j++) 
		{
			newPixelValues.pushBack(other->pixels[i * other->width + j]);
		}
	}

	PGMImage newImage(std::move(newPixelValues), height, newWidth, maxValueColour, fileName, format);
	newImage.save();
}
void PGMImage::collageHorizontallyWithPPM(const PPMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.pgm and .ppm)");
}


void PGMImage::collageVerticallyWithPBM(const PBMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.pgm and .pbm)");
}
void PGMImage::collageVerticallyWithPGM(const PGMImage* other, const MyString& fileName) const
{
	if (width != other->width) 
		throw std::runtime_error("Images must have the same width to be collaged vertically!");
	
	if (maxValueColour != other->maxValueColour)
		throw std::runtime_error("Image must have the same max colour value to be collaged together!");

	int32_t newHeight = height + other->height;
	MyVector<uint8_t> newPixelValues;

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			newPixelValues.pushBack(pixels[i * width + j]);
		}
	}
	for (int i = 0; i < other->height; i++) 
	{
		for (int j = 0; j < other->width; j++)
		{
			newPixelValues.pushBack(other->pixels[i * other->width + j]);
		}
	}

	PGMImage newImage(std::move(newPixelValues), newHeight, width, maxValueColour, fileName, format);
	newImage.save();
}
void PGMImage::collageVerticallyWithPPM(const PPMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.pgm and .ppm)");
}
TransformableImage* PGMImage::clone() const
{
	return new PGMImage(*this);
}

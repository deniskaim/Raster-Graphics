#include "PPMImage.h"
#include <fstream>

PPMImage::PPMImage(const MyVector<Pixel>& pixels, int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format)
	: pixels(pixels), maxValueColour(maxValueColour), TransformableImage(height, width, fileName, format) {}

PPMImage::PPMImage(MyVector<Pixel>&& pixels, int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format)
	: pixels(std::move(pixels)), maxValueColour(maxValueColour), TransformableImage(height, width, fileName, format) {}


void PPMImage::applyGrayscale()
{
	size_t countPixels = width * height;
	for (size_t i = 0; i < countPixels; i ++)
	{
		uint8_t gray = static_cast<uint8_t>(0.299 * pixels[i].getRed() + 
											0.587 * pixels[i].getGreen() +
											0.114 * pixels[i].getBlue());
		
		pixels[i].setRed(gray);
		pixels[i].setGreen(gray);
		pixels[i].setBlue(gray);
	}
}
void PPMImage::applyMonochrome()
{
	int8_t middle = static_cast<uint8_t>(maxValueColour / 2);

	size_t countPixels = width * height;
	for (size_t i = 0; i < countPixels; i ++)
	{
		uint8_t gray = static_cast<uint8_t>(0.299 * pixels[i].getRed() +
											0.587 * pixels[i].getGreen() +
											0.114 * pixels[i].getBlue());

		uint8_t mono = static_cast<uint8_t>(gray > middle ? maxValueColour : 0);
		pixels[i].setRed(mono);
		pixels[i].setGreen(mono);
		pixels[i].setBlue(mono);
	}
}
void PPMImage::applyNegative()
{
	size_t countPixels = width * height;
	for (size_t i = 0; i < countPixels; i++)
	{
		pixels[i].setRed(maxValueColour - pixels[i].getRed());
		pixels[i].setGreen(maxValueColour - pixels[i].getGreen());
		pixels[i].setBlue(maxValueColour - pixels[i].getBlue());
	}
}
void PPMImage::rotateLeft()
{
	MyVector<Pixel> rotatedPixels(width * height);

	for (int column = width - 1; column >= 0; column--) 
	{
		for (int row = 0; row < height; row++) 
		{
			rotatedPixels.pushBack(pixels[row * width + column]);
		}
	}

	pixels = std::move(rotatedPixels);
	std::swap(width, height); // Swap width and height after rotation
}
void PPMImage::rotateRight() 
{
	MyVector<Pixel> rotatedPixels(width * height);

	for (int column = 0; column < width; column++) 
	{
		for (int row = height - 1; row >= 0; row--) 
		{
			rotatedPixels.pushBack(pixels[row * width + column]);
		}
	}

	pixels = std::move(rotatedPixels);
	std::swap(width, height); // Swap width and height after rotation
}
void PPMImage::serialize(const MyString& fileName) const
{
	if (format == "P3")
		serializeInASCII(fileName);
}
void PPMImage::serializeInASCII(const MyString& fileName) const
{
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open())
		throw std::exception("Could not open the file!");

	ofs << format << '\n';
	ofs << width << " " << height << '\n';
	ofs << static_cast<int32_t>(maxValueColour) << '\n';

	size_t countPixels = width * height;
	for (size_t i = 0; i < countPixels; i++)
	{
		ofs << pixels[i] << '\n';
	}
	ofs.close();
}
TransformableImage* PPMImage::clone() const
{
	return new PPMImage(*this);
}
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
	uint8_t middle = static_cast<uint8_t>(maxValueColour / 2);
	size_t pixelsCount = width * height;
	for (size_t i = 0; i < pixelsCount; i++)
	{
		uint8_t monoPixel = static_cast<uint8_t>(pixels[i] > middle ? maxValueColour : 0);
		pixels[i] = monoPixel;
	}
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
TransformableImage* PGMImage::clone() const
{
	return new PGMImage(*this);
}

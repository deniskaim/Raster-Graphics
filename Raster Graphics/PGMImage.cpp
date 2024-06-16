#include "PGMImage.h"

PGMImage::PGMImage(const MyVector<uint8_t>& pixels, int32_t height, int32_t width, const MyString& fileName)
	: pixels(pixels), TransformableImage(height, width, fileName) {}

PGMImage::PGMImage(MyVector<uint8_t>&& pixels, int32_t height, int32_t width, const MyString& fileName)
	: pixels(std::move(pixels)), TransformableImage(height, width, fileName) {}

void PGMImage::applyGrayscale()
{
	// empty
}
void PGMImage::applyMonochrome()
{
	uint8_t middle = maxValueColour / 2;
	for (size_t i = 0; i < width * height; i++)
	{
		uint8_t monoPixel = pixels[i] > middle ? maxValueColour : 0;
		pixels[i] = monoPixel;
	}
}
void PGMImage::applyNegative()
{
	for (size_t i = 0; i < width * height; i++)
		pixels[i] = maxValueColour - pixels[i];
}
TransformableImage* PGMImage::clone() const
{
	return new PGMImage(*this);
}

#include "PPMImage.h"

PPMImage::PPMImage(const MyVector<uint8_t>& pixels, int32_t height, int32_t width, const MyString& fileName)
	: pixels(pixels), TransformableImage(height, width, fileName) {}

PPMImage::PPMImage(MyVector<uint8_t>&& pixels, int32_t height, int32_t width, const MyString& fileName)
	: pixels(std::move(pixels)), TransformableImage(height, width, fileName) {}


void PPMImage::applyGrayscale()
{
	for (size_t i = 0; i < width * height * 3; i += 3)
	{
		uint8_t gray = 0.299 * pixels[i] + 0.587 * pixels[i + 1] + 0.114 * pixels[i + 2];
		pixels[i] = pixels[i + 1] = pixels[i + 2] = gray;
	}
}
void PPMImage::applyMonochrome()
{
	int8_t middle = maxValueColour / 2;
	for (size_t i = 0; i < width * height * 3; i += 3)
	{
		uint8_t gray = 0.299 * pixels[i] + 0.587 * pixels[i + 1] + 0.114 * pixels[i + 2];
		uint8_t mono = gray > middle ? maxValueColour : 0;
		pixels[i] = pixels[i + 1] = pixels[i + 2] = mono;
	}
}
void PPMImage::applyNegative()
{
	for (size_t i = 0; i < width * height * 3; i++)
		pixels[i] = maxValueColour - pixels[i];
}
TransformableImage* PPMImage::clone() const
{
	return new PPMImage(*this);
}
#include "PBMImage.h"
#include <fstream>

PBMImage::PBMImage(const DynamicSet& pixels, int32_t height, int32_t width, const MyString& fileName, const MyString& format) 
	: pixels(pixels), TransformableImage(height, width, fileName, format)
{}
PBMImage::PBMImage(DynamicSet&& pixels, int32_t height, int32_t width, const MyString& fileName, const MyString& format) 
	: pixels(std::move(pixels)), TransformableImage(height, width, fileName, format)
{}
void PBMImage::serialize(const MyString& fileName) const
{
	if (format == "P1")
		serializeInASCII(fileName);
}
void PBMImage::serializeInASCII(const MyString& fileName) const
{
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open())
		throw std::exception("File could not open!");

	ofs << format << '\n';
	ofs << width << " " << height << '\n';
	size_t countPixels = width * height;

	for (int i = 0; i < countPixels; i++)
	{
		ofs << static_cast<uint32_t>(pixels.contains(i));
		if ((i + 1) % width == 0)
			ofs << '\n';
		else
			ofs << " ";
	}
	ofs.close();
}

void PBMImage::applyGrayscale()
{
	// empty
}

void PBMImage::applyMonochrome()
{
	// empty
}

void PBMImage::applyNegative()
{
	size_t pixelsCount = height * width;
	for (unsigned i = 0; i < pixelsCount; i++)
	{
		if (pixels.contains(i))
			pixels.remove(i);
		else
			pixels.add(i);
	}
}
void PBMImage::rotateLeft() 
{
	DynamicSet rotated(width * height);

	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			if (pixels.contains(row * width + column))
			{
				int newRow = width - 1 - column;
				int newCol = row;
				rotated.add(newRow * height + newCol);
			}
		}
	}
	pixels = std::move(rotated);
	std::swap(width, height); // Swap width and height after rotation
}
void PBMImage::rotateRight()
{
	DynamicSet rotated(width * height);

	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			if (pixels.contains(row * width + column))
			{
				int newRow = column;
				int newCol = height - 1 - row;
				rotated.add(newRow * height + newCol);
			}
		}
	}
	
	pixels = std::move(rotated);
	std::swap(width, height);
}
TransformableImage* PBMImage::clone() const
{
	return new PBMImage(*this);
}

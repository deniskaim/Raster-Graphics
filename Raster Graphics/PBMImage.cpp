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
	std::swap(width, height); 
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
void PBMImage::collageHorizontallyInNewFile(const TransformableImage* other, const MyString& fileName) const
{
	other->collageHorizontallyWithPBM(this, fileName);
}
void PBMImage::collageVerticallyInNewFile(const TransformableImage* other, const MyString& fileName) const
{
	other->collageVerticallyWithPBM(this, fileName);
}
void PBMImage::collageHorizontallyWithPBM(const PBMImage* other, const MyString& fileName) const
{
	if (this->height != other->height) 
	{
		throw std::runtime_error("Images must have the same height to be collaged horizontally!");
	}

	int32_t newWidth = this->width + other->width;
	DynamicSet newSet(height * newWidth);

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			if (pixels.contains(i * width + j)) 
			{
				newSet.add(i * newWidth + j);
			}
		}
		for (int j = 0; j < other->width; j++) 
		{
			if (other->pixels.contains(i * other->width + j)) 
			{
				newSet.add(i * newWidth + width + j);
			}
		}
	}
	PBMImage newImage(std::move(newSet),height, newWidth, fileName, format);
	newImage.save();
}
void PBMImage::collageHorizontallyWithPGM(const PGMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.pgm and .pbm");
}
void PBMImage::collageHorizontallyWithPPM(const PPMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.ppm and .pbm)");
}

void PBMImage::collageVerticallyWithPBM(const PBMImage* other, const MyString& fileName) const
{
	if (this->width != other->width)
	{
		throw std::runtime_error("Images must have the same width to be collaged vertically!");
	}

	int32_t newHeight = this->height + other->height;
	DynamicSet newSet(width * newHeight);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (pixels.contains(i * width + j))
			{
				newSet.add(i * width + j);
			}
		}
	}
	for (int i = 0; i < other->height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (other->pixels.contains(i * other->width + j))
			{
				newSet.add((height + i) * width + j);
			}
		}
	}
	PBMImage newImage(std::move(newSet), newHeight, width, fileName, format);
	newImage.save();
}
void PBMImage::collageVerticallyWithPGM(const PGMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.pgm and .pbm");
}
void PBMImage::collageVerticallyWithPPM(const PPMImage* other, const MyString& fileName) const
{
	throw std::runtime_error("Cannot make a collage from different types! (.ppm and .pbm)");
}
TransformableImage* PBMImage::clone() const
{
	return new PBMImage(*this);
}

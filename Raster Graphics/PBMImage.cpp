#include "PBMImage.h"
#include <fstream>

PBMImage::PBMImage(const DynamicSet& pixels, int32_t height, int32_t width, const MyString& fileName) : pixels(pixels), TransformableImage(height, width, fileName)
{}
PBMImage::PBMImage(DynamicSet&& pixels, int32_t height, int32_t width, const MyString& fileName) : pixels(std::move(pixels)), TransformableImage(height, width, fileName)
{}
void PBMImage::write(const MyString& fileName) const
{
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open())
		throw std::exception("File could not open!");

	ofs << width << " " << height;
	size_t count = width * height;

	for (int i = 0; i < count; i++)
	{
		ofs << pixels.contains(i) << " ";
		if ((i + 1) % width == 0)
			ofs << '\n';
	}
	ofs.close();
}

void PBMImage::applyGrayscale()
{}

void PBMImage::applyMonochrome()
{}

void PBMImage::applyNegative()
{
	for (unsigned i = 0; i < height * width; i++)
	{
		if (pixels.contains(i))
			pixels.remove(i);
		else
			pixels.add(i);
	}
}
TransformableImage* PBMImage::clone() const
{
	return new PBMImage(*this);
}

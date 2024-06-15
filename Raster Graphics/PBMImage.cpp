#include "PBMImage.h"
#include <fstream>

PBMImage::PBMImage(const DynamicSet& pixels, const MyString& fileName) : pixels(pixels), TransformableImage(fileName)
{}
PBMImage::PBMImage(DynamicSet&& pixels, const MyString& fileName) : pixels(std::move(pixels)), TransformableImage(fileName)
{}
void PBMImage::write(const MyString& fileName) const
{
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open())
		throw std::exception("File could not open!");

	ofs << columns << " " << rows;

	for (int i = 0; i < rows * columns; i++)
	{
		ofs << pixels.contains(i) << " ";
		if ((i + 1) % columns == 0)
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
	for (unsigned i = 0; i < rows * columns; i++)
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

#pragma once
#include "Image.h"
#include "DynamicSet.h"

class PBMImage : public Image
{
public:

	PBMImage(const DynamicSet& pixels, const MyString& fileName);
	PBMImage(DynamicSet&& pixels, const MyString& fileName);
	void grayscale() override;
	void monochrome() override;
	void negative() override;
	void rotate(Direction direction) override;

	// void read(const MyString& fileName) override;
	void write(const MyString& fileName) const override;
	Image* clone() const override;

private:
	int32_t rows = 0;
	int32_t columns = 0;
	DynamicSet pixels;
};
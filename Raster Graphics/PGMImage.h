#pragma once
#include "Image.h"
#include "MyVector.hpp"

class PGMImage : public Image
{
public:

	PGMImage(const MyVector<int8_t>& pixels, const MyString& fileName);
	PGMImage(MyVector<int8_t>&& pixels, const MyString& fileName);
	void grayscale() override;
	void monochrome() override;
	void negative() override;
	void rotate(Direction direction) override;

	// void read(const MyString& fileName) override;
	void write(const MyString& fileName) const override;
	Image* clone() const override;

private:
	MyVector<int8_t> pixels;
	int8_t maxValueColour = 0;
};
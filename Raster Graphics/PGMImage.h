#pragma once
#include "TransformableImage.h"
#include "MyVector.hpp"

class PGMImage : public TransformableImage
{
public:

	PGMImage(const MyVector<int8_t>& pixels, const MyString& fileName);
	PGMImage(MyVector<int8_t>&& pixels, const MyString& fileName);
	void applyGrayscale() override;
	void applyMonochrome() override;
	void applyNegative() override;
	void rotateLeft() override;
	void rotateRight() override;

	// void read(const MyString& fileName) override;
	void save(const MyString& fileName) const override;
	TransformableImage* clone() const override;

private:
	MyVector<int8_t> pixels;
	int8_t maxValueColour = 0;
};
#pragma once
#include "TransformableImage.h"
#include "MyVector.hpp"

class PPMImage : public TransformableImage
{
public:
	PPMImage(const MyVector<int8_t>& pixels, const MyString& fileName);
	PPMImage(MyVector<int8_t>&& pixels, const MyString& fileName);
	void applyGrayscale() override;
	void applyMonochrome() override;
	void applyNegative() override;
	void rotateLeft() override;
	void rotateRight() override;

	void save(const MyString& fileName) const override;
	TransformableImage* clone() const override;

private:
	MyVector<int8_t> pixels;
	int8_t maxValueColour = 0;
};
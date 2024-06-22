#pragma once
#include "TransformableImage.h"
#include "MyVector.hpp"
#include "Pixel.h"

class PPMImage : public TransformableImage
{
public:
	PPMImage(const MyVector<Pixel>& pixels,int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format);
	PPMImage(MyVector<Pixel>&& pixels, int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format);

	void applyGrayscale() override;
	void applyMonochrome() override;
	void applyNegative() override;
	void rotateLeft() override;
	void rotateRight() override;

	void serialize(const MyString& fileName) const override;
	TransformableImage* clone() const override;

private:
	MyVector<Pixel> pixels;
	uint8_t maxValueColour = 0;

	void serializeInASCII(const MyString& fileName) const override;
};
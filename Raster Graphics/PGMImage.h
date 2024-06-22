#pragma once
#include "TransformableImage.h"
#include "MyVector.hpp"

class PGMImage : public TransformableImage
{
public:

	PGMImage(const MyVector<uint8_t>& pixels, int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format);
	PGMImage(MyVector<uint8_t>&& pixels, int32_t height, int32_t width, uint8_t maxValueColour, const MyString& fileName, const MyString& format);

	void applyGrayscale() override;
	void applyMonochrome() override;
	void applyNegative() override;
	void rotateLeft() override;
	void rotateRight() override;

	void serialize(const MyString& fileName) const override;
	TransformableImage* clone() const override;

private:
	MyVector<uint8_t> pixels;
	uint8_t maxValueColour = 0;
	void serializeInASCII(const MyString& fileName) const override;
};
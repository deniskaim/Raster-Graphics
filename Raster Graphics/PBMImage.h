#pragma once
#include "TransformableImage.h"
#include "DynamicSet.h"

class PBMImage : public TransformableImage
{
public:

	PBMImage(const DynamicSet& pixels, int32_t height, int32_t width, const MyString& fileName, const MyString& format);
	PBMImage(DynamicSet&& pixels, int32_t height, int32_t width, const MyString& fileName, const MyString& format);

	void applyGrayscale() override;
	void applyMonochrome() override;
	void applyNegative() override;
	void rotateLeft() override;
	void rotateRight() override;

	// void read(const MyString& fileName) override;
	void serialize(const MyString& fileName) const override;
	TransformableImage* clone() const override;

private:
	DynamicSet pixels;
	void serializeInASCII(const MyString& filename) const override;

};
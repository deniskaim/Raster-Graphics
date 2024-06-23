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

	void serialize(const MyString& fileName) const override;
	TransformableImage* clone() const override;

	void collageHorizontallyInNewFile(const TransformableImage* other, const MyString& fileName) const override;
	void collageVerticallyInNewFile(const TransformableImage* other, const MyString& fileName) const override;

	void collageHorizontallyWithPBM(const PBMImage* other, const MyString& fileName) const override;
	void collageHorizontallyWithPGM(const PGMImage* other, const MyString& fileName) const override;
	void collageHorizontallyWithPPM(const PPMImage* other, const MyString& fileName) const override;

	void collageVerticallyWithPBM(const PBMImage* other, const MyString& fileName) const override;
	void collageVerticallyWithPGM(const PGMImage* other, const MyString& fileName) const override;
	void collageVerticallyWithPPM(const PPMImage* other, const MyString& fileName) const override;

private:
	DynamicSet pixels;
	void serializeInASCII(const MyString& filename) const override;

};
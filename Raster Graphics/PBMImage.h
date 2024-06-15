#pragma once
#include "TransformableImage.h"
#include "DynamicSet.h"

class PBMImage : public TransformableImage
{
public:

	PBMImage(const DynamicSet& pixels, const MyString& fileName);
	PBMImage(DynamicSet&& pixels, const MyString& fileName);

	void applyGrayscale() override;
	void applyMonochrome() override;
	void applyNegative() override;
	void rotateLeft() override;
	void rotateRight() override;

	// void read(const MyString& fileName) override;
	void save() override;
	void write(const MyString& fileName) const override;
	TransformableImage* clone() const override;
	
protected:
	void applyAllTransformations() override;

private:
	int32_t rows = 0;
	int32_t columns = 0;
	DynamicSet pixels;

	
};
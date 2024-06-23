#pragma once
#include "MyString.h"

class TransformableImage;
class PBMImage;
class PGMImage;
class PPMImage;

class ICollageable
{
public:
	virtual void collageInNewFile(const MyString& direction, const TransformableImage* other, const MyString& outimage)
	{
		if (direction == "horizontally")
			collageHorizontallyInNewFile(other, outimage);
		else if (direction == "vertically")
			collageVerticallyInNewFile(other, outimage);
		else 
			throw std::runtime_error("Invalid collage direction");
		
	}
	virtual void collageHorizontallyInNewFile(const TransformableImage* other, const MyString& fileName) const = 0;
	virtual void collageVerticallyInNewFile(const TransformableImage* other, const MyString& fileName) const = 0;

	virtual void collageHorizontallyWithPBM(const PBMImage* other, const MyString& fileName) const = 0;
	virtual void collageHorizontallyWithPGM(const PGMImage* other, const MyString& fileName) const = 0;
	virtual void collageHorizontallyWithPPM(const PPMImage* other, const MyString& fileName) const = 0;

	virtual void collageVerticallyWithPBM(const PBMImage* other, const MyString& fileName) const = 0;
	virtual void collageVerticallyWithPGM(const PGMImage* other, const MyString& fileName) const = 0;
	virtual void collageVerticallyWithPPM(const PPMImage* other, const MyString& fileName) const = 0;

	virtual ~ICollageable() = default;
};
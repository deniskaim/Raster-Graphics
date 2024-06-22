#pragma once
#include "Image.h"
#include "ITransformable.h"
#include "MyQueue.hpp"
#include "Polymorphic_ptr.hpp"
#include "Transformation.h"

class PBMImage;
class PGMImage;
class PPMImage;

class TransformableImage : public Image, ITransformable
{
public: 
	TransformableImage(int32_t height, int32_t width, const MyString& fileName, const MyString& format);

	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void undoLastTransformation();

	void save();
	virtual void serialize(const MyString& fileName) const = 0;

	// ICollage ?
	virtual void collageInNewFile(const MyString& direction, const TransformableImage* other, const MyString& outimage);
	virtual void collageHorizontallyInNewFile(const TransformableImage* other, const MyString& fileName) const = 0;
	virtual void collageVerticallyInNewFile(const TransformableImage* other, const MyString& fileName) const = 0;

	virtual void collageHorizontallyWithPBM(const PBMImage* other, const MyString& fileName) const;
	virtual void collageHorizontallyWithPGM(const PGMImage* other, const MyString& fileName) const;
	virtual void collageHorizontallyWithPPM(const PPMImage* other, const MyString& fileName) const;

	virtual void collageVerticallyWithPBM(const PBMImage* other, const MyString& fileName) const;
	virtual void collageVerticallyWithPGM(const PGMImage* other, const MyString& fileName) const;
	virtual void collageVerticallyWithPPM(const PPMImage* other, const MyString& fileName) const;

	virtual TransformableImage* clone() const = 0;
	virtual ~TransformableImage() = default;

protected:
	MyQueue<Polymorphic_ptr<Transformation>> pendingTranformations;
	MyString format;

	virtual void serializeInASCII(const MyString& fileName) const = 0;


private:
	void applyAllTransformations(); // called by save()
	void applyTransformation();
};
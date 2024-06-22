#pragma once
#include "Image.h"
#include "ITransformable.h"
#include "MyQueue.hpp"
#include "Polymorphic_ptr.hpp"
#include "Transformation.h"

class TransformableImage : public Image, ITransformable
{
public: 
	TransformableImage(int32_t height, int32_t width, const MyString& fileName, const MyString& format);

	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void undoLastTransformation();

	void save();
	virtual void serialize(const MyString& fileName) const = 0;

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
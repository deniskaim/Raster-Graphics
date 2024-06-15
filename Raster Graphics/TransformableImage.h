#pragma once
#include "Image.h"
#include "ITransformable.h"
#include "MyQueue.hpp"
#include "Polymorphic_ptr.h"

class Transformation;

class TransformableImage : public Image, ITransformable
{
public:
	// virtual void applyTransformation(Transformation transformation); ?

	TransformableImage(const MyString& fileName) : Image(fileName) {}

	virtual void save(const MyString& fileName) const = 0;
	virtual TransformableImage* clone() const = 0;
	virtual ~TransformableImage() = default;

protected:
	MyQueue<Polymorphic_ptr<Transformation>> pendingTranformations;

};
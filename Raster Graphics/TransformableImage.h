#pragma once
#include "Image.h"
#include "ITransformable.h"
#include "MyQueue.hpp"
#include "Polymorphic_ptr.h"
#include "Transformation.h"

class TransformableImage : public Image, ITransformable
{
public: 
	TransformableImage(const MyString& fileName) : Image(fileName) {}

	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void undoLastTransformation();

	virtual void save() = 0;
	virtual void write(const MyString& fileName) const = 0;

	virtual TransformableImage* clone() const = 0;
	virtual ~TransformableImage() = default;

protected:
	MyQueue<Polymorphic_ptr<Transformation>> pendingTranformations;
	virtual void applyAllTransformations() = 0; // called by save()
};
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

	void save();
	virtual void write(const MyString& fileName) const = 0;

	virtual TransformableImage* clone() const = 0;
	virtual ~TransformableImage() = default;

protected:
	MyQueue<Polymorphic_ptr<Transformation>> pendingTranformations;

private:
	void applyAllTransformations(); // called by save()
	void applyTransformation();
};
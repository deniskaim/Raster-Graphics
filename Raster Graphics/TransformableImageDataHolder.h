#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Polymorphic_ptr.h"
#include "Transformation.h"
#include "TransformableImage.h"
#include "ImageDataHolder.h"
class TransformableImageDataHolder : public ImageDataHolder
{
public:
	TransformableImageDataHolder() = default;
	TransformableImageDataHolder(const MyString& imageName);

	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);
	void undoLastTransformation();

	const Polymorphic_ptr<Transformation>& getTransformationAtIndex(size_t index) const;
	size_t getTransformationsCount() const;

private:
	MyString imageName;
	MyVector<Polymorphic_ptr<Transformation>> pendingTransformations;
};
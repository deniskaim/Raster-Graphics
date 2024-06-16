#pragma once
#include "MyVector.hpp"
#include "Polymorphic_ptr.h"
#include "TransformableImage.h"

class ImagesCollection : public MyVector<Polymorphic_ptr<TransformableImage>>
{
public:
	void addTransformationInCollection(const Polymorphic_ptr<Transformation>& transformation)
	{
		for (size_t i = 0; i < getSize(); i++)
		{
			Polymorphic_ptr<TransformableImage>& currentImage = operator[](i);
			currentImage->addTransformation(transformation);
		}
	}
};
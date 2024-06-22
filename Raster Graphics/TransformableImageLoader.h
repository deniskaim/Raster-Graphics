#pragma once
#include "TransformableImage.h"
#include "Polymorphic_ptr.h"
#include "TransformableImageDataHolder.h"

class TransformableImageLoader
{
public:
	TransformableImageLoader(const TransformableImageDataHolder& transformableImageData);
	Polymorphic_ptr<TransformableImage> loadTransformableImage() const;

private:
	TransformableImageDataHolder transformableImageData;
	void addTransformationsToImage(Polymorphic_ptr<TransformableImage>& image) const;
};
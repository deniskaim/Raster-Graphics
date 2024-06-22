#include "TransformableImageLoader.h"
#include "ImageFactory.h"
TransformableImageLoader::TransformableImageLoader(const TransformableImageDataHolder& imageData)
	: transformableImageData(imageData)
{}
Polymorphic_ptr<TransformableImage> TransformableImageLoader::loadTransformableImage() const
{
	Polymorphic_ptr<TransformableImage> image = imageFactory(transformableImageData.getImageName());
	addTransformationsToImage(image);
	return std::move(image); // no problem with the "image" instance since it's nullptr
}
void TransformableImageLoader::addTransformationsToImage(Polymorphic_ptr<TransformableImage>& image) const
{
	for (size_t i = 0; i < transformableImageData.getTransformationsCount(); i++)
	{
		image->addTransformation(transformableImageData.getTransformationAtIndex(i));
	}
}
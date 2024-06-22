#include "TransformableImageLoader.h"
#include "ImageFactory.h"
TransformableImageLoader::TransformableImageLoader(const TransformableImageDataHolder& imageData)
	: transformableImageData(imageData)
{}
Polymorphic_ptr<TransformableImage> TransformableImageLoader::loadTransformableImage() const
{
	Polymorphic_ptr<TransformableImage> image = imageFactory(transformableImageData.getImageName());
	addTransformationsToImage(image);
	return image; 
}/*
void TransformableImageLoader::createCollageImage(const MyString& direction, const MyString& firstImage, const MyString& secondImage) const
{
	Polymorphic_ptr<TransformableImage> image1 = imageFactory(firstImage);
	Polymorphic_ptr<TransformableImage> image2 = imageFactory(secondImage);

	if (direction == "horizontally")
		image1->combineTransformableImagesHorizontally(image2);
}*/
void TransformableImageLoader::addTransformationsToImage(Polymorphic_ptr<TransformableImage>& image) const
{
	for (size_t i = 0; i < transformableImageData.getTransformationsCount(); i++)
	{
		image->addTransformation(transformableImageData.getTransformationAtIndex(i));
	}
}
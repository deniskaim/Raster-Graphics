#include "TransformableImage.h"

TransformableImage::TransformableImage(int32_t height, int32_t width, const MyString& fileName) 
	: Image(height, width, fileName) {}

void TransformableImage::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	pendingTranformations.push(transformation);
}
void TransformableImage::serialize()
{
	applyAllTransformations();
	write(fileName);
}
void TransformableImage::undoLastTransformation()
{
	if (!pendingTranformations.empty())
		pendingTranformations.pop();
}
void TransformableImage::applyAllTransformations()
{
	while (!pendingTranformations.empty())
	{
		applyTransformation();
	}
}
void TransformableImage::applyTransformation()
{
	Type transformationType = pendingTranformations.peek()->getType();
	pendingTranformations.pop();

	switch (transformationType)
	{
	case Type::grayscale:
		applyGrayscale();
		break;

	case Type::monochrome:
		applyMonochrome();
		break;

	case Type::negative:
		applyNegative();
		break;

	case Type::rotateLeft:
		rotateLeft();
		break;

	case Type::rotateRight:
		rotateRight();
		break;
	}

}

#include "TransformableImage.h"

TransformableImage::TransformableImage(int32_t height, int32_t width, const MyString& fileName, const MyString& format) 
	: Image(height, width, fileName), format(format) {}

void TransformableImage::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	pendingTranformations.push(transformation);
}
void TransformableImage::save()
{
	applyAllTransformations();
	serialize(imageName);
}
void TransformableImage::collageInNewFile(const MyString& direction, const TransformableImage* other, const MyString& outimage)
{
	if (direction == "horizontally")
		collageHorizontallyInNewFile(other, outimage);
	else if (direction == "vertically")
		collageVerticallyInNewFile(other, outimage);
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

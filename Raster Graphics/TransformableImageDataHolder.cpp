#include "TransformableImageDataHolder.h"

TransformableImageDataHolder::TransformableImageDataHolder(const MyString& imageName)
{
	this->imageName = imageName;
}
void TransformableImageDataHolder::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	pendingTransformations.pushBack(transformation);
}
void TransformableImageDataHolder::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	pendingTransformations.pushBack(std::move(transformation));
}

const Polymorphic_ptr<Transformation>& TransformableImageDataHolder::getTransformationAtIndex(size_t index) const
{
	if (index >= pendingTransformations.getSize())
		throw std::out_of_range("There is no transformation at this index!");

	return pendingTransformations[index];
}

size_t TransformableImageDataHolder::getTransformationsCount() const
{
	return pendingTransformations.getSize();
}

#include "TransformableImageDataHolder.h"

TransformableImageDataHolder::TransformableImageDataHolder(const MyString& imageName) : ImageDataHolder(imageName)
{
	validateImageName();
	std::cout << "Image \"" << imageName << "\" added" << std::endl;
}
void TransformableImageDataHolder::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	pendingTransformations.pushBack(transformation);
}
void TransformableImageDataHolder::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	pendingTransformations.pushBack(std::move(transformation));
}

void TransformableImageDataHolder::undoLastTransformation()
{
	if (!pendingTransformations.empty())
		pendingTransformations.popBack();
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

static MyString getExtension(const MyString& fileName)
{
	const char* beg = fileName.c_str();
	const char* end = fileName.c_str() + fileName.getSize();

	const char* iter = end;
	while (iter != beg && *iter != '.')
		iter--;

	return fileName.substr(iter - beg + 1, end - iter - 1);
}
void TransformableImageDataHolder::validateImageName() const
{
	MyString extension = getExtension(imageName);
	if (!(extension == "pbm" || extension == "pgm" || extension == "ppm"))
		throw std::exception("Invalid image name!");
}



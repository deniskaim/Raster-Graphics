#include "TransformationHandler.h"

void TransformationHandler::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	transformationsInSession.pushBack(transformation);
}
void TransformationHandler::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	transformationsInSession.pushBack(std::move(transformation));
}
void TransformationHandler::executeAll(ImagesCollection& imageCollection)
{
	for (size_t i = 0; i < imageCollection.getSize(); i++)
		imageCollection[i]->serialize();

	std::cout << '\n';
}
void TransformationHandler::printTransformations() const
{
	std::cout << "Pending transformations: ";

	for (size_t i = 0; i < transformationsInSession.getSize(); i++)
	{
		transformationsInSession[i]->printType();
		std::cout << " ";
	}

}

void TransformationHandler::undoLastTransformation(MyVector<TransformableImageDataHolder>& imageCollection)
{
	if (transformationsInSession.empty())
		return;

	else
	{
		std::cout << "Removed last transformation - ";
		transformationsInSession.popBack()->printType();
		std::cout << std::endl;

		for (size_t i = 0; i < imageCollection.getSize(); i++)
			imageCollection[i].undoLastTransformation();
	}
}
/*
void TransformationHandler::close()
{
	transformationsInSession.clear();
}
*/

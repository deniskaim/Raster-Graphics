#include "TransformationExecutor.h"

void TransformationExecutor::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	transformationsInSession.pushBack(transformation);
}
void TransformationExecutor::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	transformationsInSession.pushBack(std::move(transformation));
}
void TransformationExecutor::executeAll(ImagesCollection& imageCollection)
{
	for (size_t i = 0; i < imageCollection.getSize(); i++)
		imageCollection[i]->save();
	std::cout << '\n';
}
void TransformationExecutor::printTransformations() const
{
	std::cout << "Pending transformations: ";

	for (size_t i = 0; i < transformationsInSession.getSize(); i++)
	{
		transformationsInSession[i]->printType();
		std::cout << " ";
	}

}

void TransformationExecutor::close()
{
	transformationsInSession.clear();
}

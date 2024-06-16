#include "TransformationHandler.h"

void TransformationHandler::add(const Polymorphic_ptr<Transformation>& transformation)
{
	toExecute.push(transformation);
}
void TransformationHandler::add(Polymorphic_ptr<Transformation>&& transformation)
{
	toExecute.push(std::move(transformation));
}
void TransformationHandler::execute(const ImagesCollection& imageCollection)
{
	if (toExecute.empty())
		return;

	Polymorphic_ptr<Transformation>& current = toExecute.peek();
	current->execute(); // TODO: find a proper way to make this work

	executed.pushBack(std::move(current)); // use the allocated memory
	toExecute.pop();
}
void TransformationHandler::executeAll()
{
	while (!toExecute.empty())
	{
		execute();
	}
}
void TransformationHandler::undo()
{
	if (executed.empty())
		return;

	Polymorphic_ptr<Transformation>& lastTransformation = executed.peek();
	// lastTransformation.undo(); TODO: Make this work
	executed.popBack();
}

bool TransformationHandler::isEmpty() const
{
	return toExecute.empty();
}
void TransformationHandler::clear()
{
	toExecute.clear();
	executed.clear();
}

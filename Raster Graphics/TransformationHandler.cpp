#include "TransformationExecutor.h"

void TransformationExecutor::add(const Polymorphic_ptr<Transformation>& transformation)
{
	toExecute.push(transformation);
}
void TransformationExecutor::add(Polymorphic_ptr<Transformation>&& transformation)
{
	toExecute.push(std::move(transformation));
}
void TransformationExecutor::execute()
{
	if (toExecute.empty())
		return;

	Polymorphic_ptr<Transformation>& current = toExecute.peek();
	current->execute(); // TODO: find a proper way to make this work

	executed.pushBack(std::move(current)); // use the allocated memory
	toExecute.pop();
}
void TransformationExecutor::executeAll()
{
	while (!toExecute.empty())
	{
		execute();
	}
}
void TransformationExecutor::undo()
{
	if (executed.empty())
		return;

	Polymorphic_ptr<Transformation>& lastTransformation = executed.peek();
	// lastTransformation.undo(); TODO: Make this work
	executed.popBack();
}

bool TransformationExecutor::isEmpty() const
{
	return toExecute.empty();
}
void TransformationExecutor::clear()
{
	toExecute.clear();
	executed.clear();
}

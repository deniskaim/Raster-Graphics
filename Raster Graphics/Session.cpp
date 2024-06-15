#include "Session.h"

size_t Session::sessionsCount = 1;

void Session::addImage(const Polymorphic_ptr<Image>& image)
{
	imageCollection.pushBack(image);
}
void Session::addImage(Polymorphic_ptr<Image>&& image)
{
	imageCollection.pushBack(std::move(image));
}
void Session::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	transformationExecutor.add(transformation);
}
void Session::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	transformationExecutor.add(std::move(transformation));
}

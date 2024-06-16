#include "Session.h"

size_t Session::sessionsCount = 1;

Session::Session()
{
	ID = sessionsCount++;
}
void Session::addImage(const Polymorphic_ptr<TransformableImage>& image)
{
	imageCollection.pushBack(image);
}
void Session::addImage(Polymorphic_ptr<TransformableImage>&& image)
{
	imageCollection.pushBack(std::move(image));
}
void Session::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	// transformationHandler.add(transformation);
	transformations.pushBack(transformation);
	addTransformationInTransformableImages(transformation);
}
void Session::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	// transformationHandler.add(std::move(transformation));
	transformations.pushBack(std::move(transformation));
	addTransformationInTransformableImages(transformation);
}
void Session::addTransformationInTransformableImages(const Polymorphic_ptr<Transformation>& transformation)
{
	for (size_t i = 0; i < imageCollection.getSize(); i++)
	{
		imageCollection[i]->addTransformation(transformation);
	}
}
void Session::undo()
{
	transformationHandler.undo();
}
void Session::save()
{
	//while (!transformationExecutor.isEmpty())
	//{
	//	transformationExecutor.
	//}
	
}
void Session::saveAs(const MyString& fileName)
{
	//transformationExecutor.executeAll();
	// TODO: set fileName to the first image 
}
void Session::close()
{
	reset();
}
void Session::printInfo() const
{
	printID();
	printImagesNames();
	printPendingTransformations();
}

// private 
void Session::printID() const
{
	std::cout << "Session ID = " << ID << std::endl;
}
void Session::printImagesNames() const
{
	std::cout << "Name of images in the session: ";
	// ...
	std::cout << '\n';
}
void Session::printPendingTransformations() const
{
	std::cout << "Pending transformations: ";
	// ...
}
void Session::reset()
{
	imageCollection.clear();
	transformationExecutor.clear();
}
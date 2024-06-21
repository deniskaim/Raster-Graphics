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
	transformationHandler.addTransformation(transformation);
	imageCollection.addTransformationInCollection(transformation);
}
void Session::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	transformationHandler.addTransformation(std::move(transformation));
	imageCollection.addTransformationInCollection(transformation);
}
void Session::undo()
{
	transformationHandler.undoLastTransformation();
}
void Session::save()
{
	transformationHandler.executeAll(imageCollection);
}
void Session::saveAs(const MyString& fileName)
{
	transformationHandler.executeAll(imageCollection); // TODO: add fileName
}
void Session::close()
{
	imageCollection.clear();
	transformationHandler.close();
	// just popAt() in the Application class?
}
void Session::printInfo() const
{
	printID();
	printImagesNames();
	printPendingTransformations();
}

size_t Session::getID() const
{
	return ID;
}

// private 
void Session::printID() const
{
	std::cout << "Session ID = " << ID << std::endl;
}
void Session::printImagesNames() const
{
	std::cout << "Name of images in the session: ";
	for (size_t i = 0; i < imageCollection.getSize(); i++)
		std::cout << imageCollection[i]->getFileName() << " ";

	std::cout << '\n';
}
void Session::printPendingTransformations() const
{
	transformationHandler.printTransformations();
	std::cout << '\n';
}
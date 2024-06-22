#include "Session.h"
#include "TransformableImageLoader.h"

size_t Session::sessionsCount = 1;

/*
void Session::addImage(const Polymorphic_ptr<TransformableImage>& image)
{
	imageCollection.pushBack(image);
}
void Session::addImage(Polymorphic_ptr<TransformableImage>&& image)
{
	imageCollection.pushBack(std::move(image));
}
*/
void Session::addImage(const MyString& imageName)
{
	TransformableImageDataHolder imageDataHolder(imageName);
	imageDataHolders.pushBack(imageDataHolder);
}
void Session::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	transformationHandler.addTransformation(transformation);
	//imageCollection.addTransformationInCollection(transformation);
	addTransformationInCollectionOfDataHolders(transformation);
}
void Session::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	transformationHandler.addTransformation(std::move(transformation));
	// imageCollection.addTransformationInCollection(transformation);
	addTransformationInCollectionOfDataHolders(transformation);
}
void Session::undo()
{
	transformationHandler.undoLastTransformation(imageDataHolders);
}
void Session::save()
{

	transformationHandler.executeAll(imageCollection);
}
void Session::saveAs(const MyString& fileName)
{
	imageCollection[0]->setImageName(fileName);
	transformationHandler.executeAll(imageCollection);
}
/*
void Session::close()
{
	imageCollection.clear();
	transformationHandler.close();
	// just popAt() in the Application class?
}
*/
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
void Session::initializeID()
{
	ID = getNextSessionID();
}
size_t Session::getNextSessionID()
{
	return sessionsCount++;
}

void Session::loadTransformableImage(size_t imageDataHolderIndex)
{
	if (imageDataHolderIndex >= imageDataHolders.getSize())
		throw std::out_of_range("Invalid imageDataHolder index!");

	TransformableImageLoader imageLoader(imageDataHolders[imageDataHolderIndex]);
	imageCollection.pushBack(imageLoader.loadTransformableImage());
}
void Session::loadTransformableImages()
{
	for (size_t index = 0; index < imageDataHolders.getSize(); index++)
	{
		loadTransformableImage(index);
	}
}
void Session::addTransformationInCollectionOfDataHolders(const Polymorphic_ptr<Transformation>& transformation)
{
	for (size_t i = 0; i < imageDataHolders.getSize(); i++)
	{
		imageDataHolders[i].addTransformation(transformation);
	}
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
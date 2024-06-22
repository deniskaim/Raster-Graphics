#include "Session.h"
#include "TransformableImageLoader.h"

size_t Session::sessionsCount = 1;

void Session::addImage(const MyString& imageName)
{
	TransformableImageDataHolder imageDataHolder(imageName);
	imageDataHolders.pushBack(imageDataHolder);
}
void Session::addCollage(const MyString& direction, const MyString& imageOne, const MyString& imageTwo, const MyString& outimage)
{
	size_t firstIndex = findImageDataHolderIndexByImageName(imageOne);
	size_t secondIndex = findImageDataHolderIndexByImageName(imageTwo);
	if (firstIndex == -1 || secondIndex == -1)
		throw std::exception("At least one of the two images is not present in the session!");

	TransformableImageDataHolder imageDataHolder(outimage);
	imageDataHolders.pushBack(imageDataHolder);

	loadTransformableImage(firstIndex);
	Polymorphic_ptr<TransformableImage>& firstImage = imageCollection[imageCollection.getSize() - 1];

	loadTransformableImage(secondIndex);
	Polymorphic_ptr<TransformableImage>& secondImage = imageCollection[imageCollection.getSize() - 1];

	firstImage->collageInNewFile(direction, secondImage.get(), outimage);

}
void Session::addTransformation(const Polymorphic_ptr<Transformation>& transformation)
{
	transformationHandler.addTransformation(transformation);
	addTransformationInCollectionOfDataHolders(transformation);
}
void Session::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	// important to be before the next line since the pointer will become nullptr
	addTransformationInCollectionOfDataHolders(transformation); 
	transformationHandler.addTransformation(std::move(transformation));
}
void Session::undo()
{
	transformationHandler.undoLastTransformation(imageDataHolders);
}
void Session::save()
{
	loadTransformableImages();
	transformationHandler.executeAll(imageCollection);
}
void Session::saveAs(const MyString& fileName)
{
	loadTransformableImages();
	imageCollection[0]->setImageName(fileName);
	transformationHandler.executeAll(imageCollection);
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
void Session::initializeID()
{
	ID = getNextSessionID();
	std::cout << "Session with ID: " << ID << " started!" << std::endl;
}
size_t Session::getNextSessionID()
{
	return sessionsCount++;
}

size_t Session::findImageDataHolderIndexByImageName(const MyString& imageName)
{
	for (size_t i = 0; i < imageDataHolders.getSize(); i++)
	{
		if (imageDataHolders[i].getImageName() == imageName)
			return i;
	}
	return -1;
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
void Session::printID() const
{
	std::cout << "Current session ID = " << ID << std::endl;
}
void Session::printImagesNames() const
{
	std::cout << "Name of images in the session: ";
	for (size_t i = 0; i < imageDataHolders.getSize(); i++)
		std::cout << imageDataHolders[i].getImageName() << " ";

	std::cout << '\n';
}
void Session::printPendingTransformations() const
{
	transformationHandler.printTransformations();
	std::cout << '\n';
}
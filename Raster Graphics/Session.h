#pragma once
#include "ImageCollection.h"
#include "TransformationHandler.h"
#include "TransformableImageDataHolder.h"
#include "MyString.h"

class Session
{
public:

	void addImage(const MyString& imageName);

	//void addImage(const Polymorphic_ptr<TransformableImage>& image);
	// void addImage(Polymorphic_ptr<TransformableImage>&& image);
	
	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);
	void undo();

	void save();
	void saveAs(const MyString& fileName); // only the first image under this name
	// void close();
	void printInfo() const;

	size_t getID() const;
	void initializeID();

private:
	TransformationHandler transformationHandler;
	ImageCollection imageCollection;
	MyVector<TransformableImageDataHolder> imageDataHolders;
	size_t ID = 0;
	static size_t sessionsCount; // must initialize in cpp

	void printID() const;
	void printImagesNames() const;
	void printPendingTransformations() const;
	static size_t getNextSessionID();

	void loadTransformableImage(size_t imageDataHolderIndex);
	void loadTransformableImages();
	void addTransformationInCollectionOfDataHolders(const Polymorphic_ptr<Transformation>& transformation);
};
#pragma once
#include "ImagesCollection.h"
#include "TransformationHandler.h"
#include "MyString.h"

class Session
{
public:

	Session();
	void addImage(const Polymorphic_ptr<TransformableImage>& image);
	void addImage(Polymorphic_ptr<TransformableImage>&& image);

	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);
	void undo();

	void save();
	void saveAs(const MyString& fileName); // only the first image under this name
	void close();
	void printInfo() const;

private:
	TransformationHandler transformationHandler;
	ImagesCollection imageCollection;
	
	size_t ID = 0;
	static size_t sessionsCount; // must initialize in cpp

	void printID() const;
	void printImagesNames() const;
	void printPendingTransformations() const;

};
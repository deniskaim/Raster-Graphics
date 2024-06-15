#pragma once
#include "ImagesCollection.h"
#include "TransformationExecutor.h"
#include "MyString.h"

class Session
{
public:

	// friend class Application;
	Session();
	void addImage(const Polymorphic_ptr<Image>& image);
	void addImage(Polymorphic_ptr<Image>&& image);

	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);
	void undo();

	void save();
	void saveAs(const MyString& fileName); // only the first image under this name
	void close();
	void printInfo() const;

private:
	TransformationExecutor transformationExecutor; //po-skoro TransformationExecutor ??????????
	ImagesCollection imageCollection;
	size_t ID = 0;
	static size_t sessionsCount; // must initialize in cpp

	void reset();
	void printImagesNames() const;
	void printPendingTransformations() const;
};
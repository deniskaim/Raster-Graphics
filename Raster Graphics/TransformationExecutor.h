#pragma once
#include "ImagesCollection.h"
#include "Transformation.h"
#include "MyVector.hpp"
#include "Polymorphic_ptr.h"

// The idea of this class is to store all the transformations, but apply only those to a certain image,
// which have been added after the image has been included
class TransformationExecutor
{
public:
	/*
	TransformationExecutor() = default;
	TransformationExecutor(const TransformationExecutor& other) = delete;
	TransformationExecutor& operator=(const TransformationExecutor& other) = delete;
	~TransformationExecutor() = default;*/

	// those two functions are necessary for the transformation info, however TransformableImage* 
	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);

	void undoLastTransformation();
	void close();
	/* 
	executeAll() takes a reference to the imageCollection of the Sessionand is responsible for correcly
	applying the transformations to the images in the collection
	*/
	void executeAll(ImagesCollection& imageCollection); // TODO : add executeAll when a fileName is given
	void printTransformations() const;

private:
	MyVector<Polymorphic_ptr<Transformation>> transformationsInSession; // necessery for the print function !
};
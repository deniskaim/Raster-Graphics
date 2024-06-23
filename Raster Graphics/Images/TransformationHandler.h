#pragma once
#include "ImageCollection.h"
#include "TransformableImageDataHolder.h"
#include "Transformation.h"
#include "MyVector.hpp"
#include "Polymorphic_ptr.hpp"

/*
The idea of this class is to store all the transformations, but apply only those to a certain image,
which have been added after the image has been included, or undo the last added transformation,
in other words it handles everything related to the transformations
*/

class TransformationHandler
{
public:

	// those two functions are necessary for the transformation info
	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);

	/* 
	executeAll() takes a reference to the imageCollection of the Session and is responsible for correcly
	applying the transformations to the images in the collection
	
	undoLastTransformation() removes the last transformation from the list of every image( which contains it, since
	there can be images added after the last transformation)
	*/
	void executeAll(ImageCollection& imageCollection); 
	void undoLastTransformation(MyVector<TransformableImageDataHolder>& imageHolderCollection);
	void printTransformations() const;

private:
	MyVector<Polymorphic_ptr<Transformation>> transformationsInSession; // necessary for the print function 
};
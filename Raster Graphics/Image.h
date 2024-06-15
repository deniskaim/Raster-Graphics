#pragma once
#include <iostream>
#include "ITransformable.h"
#include "MyQueue.hpp"
#include "MyString.h"
#include "Transformation.h"
/*
enum class Direction
{
	left,
	right
};
enum class Transformation
{
	grayscale,
	monochrome,
	negative,
	rotateLeft,
	rotateRight
};
*/

class Image : public ITransformable
{
public:
	// virtual void applyTransformation(Transformation transformation); ?
	
	Image(const MyString& fileName) : fileName(fileName){}

	//virtual void read(const MyString& fileName) = 0;
	virtual void write(const MyString& fileName) const = 0;
	virtual Image* clone() const = 0;
	virtual ~Image() = default;

protected:
	MyQueue<Polymorphic_ptr<Transformation>> pendingTranformations;
	MyString fileName;
};


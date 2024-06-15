#pragma once
#include <iostream>
#include "MyQueue.hpp"
#include "MyString.h"

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
class Image
{
public:
	// virtual void applyTransformation(Transformation transformation); ?
	
	Image(const MyString& fileName) : fileName(fileName){}
	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	virtual void negative() = 0;
	virtual void rotate(Direction direction) = 0;

	//virtual void read(const MyString& fileName) = 0;
	virtual void write(const MyString& fileName) const = 0;
	virtual Image* clone() const = 0;
	virtual ~Image() = default;

protected:
	MyQueue<Transformation> pendingTranformations;
	MyString fileName;
};


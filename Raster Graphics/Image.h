#pragma once
#include <iostream>
#include "MyString.h"


class Image 
{
public:
	Image(const MyString& fileName) : fileName(fileName){}
	//virtual Image* clone() const = 0;
	virtual ~Image() = default;

protected:
	MyString fileName;
};


#pragma once
#include <iostream>
#include "MyString.h"


class Image 
{
public:
	Image(const MyString& fileName) : fileName(fileName){}
	const MyString& getFileName() const { return fileName; }
	//virtual Image* clone() const = 0;
	virtual ~Image() = default;

protected:
	int32_t height = 0;
	int32_t width = 0;
	const MyString fileName;
};


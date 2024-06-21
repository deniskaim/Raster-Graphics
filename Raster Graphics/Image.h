#pragma once
#include <iostream>
#include "MyString.h"


class Image 
{
public:
	Image(int32_t height, int32_t width, const MyString& imageName) : height(height), width(width), imageName(imageName){}
	const MyString& getImageName() const { return imageName; }
	const MyString& setImageName(const MyString& newName) { imageName = newName; }
	//virtual Image* clone() const = 0;
	virtual ~Image() = default;

protected:
	int32_t height = 0;
	int32_t width = 0;
	MyString imageName;
};


#pragma once
#include "Image.h"
class ImageDataHolder
{
public:
	ImageDataHolder() = default;
	ImageDataHolder(const MyString& imageName) : imageName(imageName){}
	virtual ~ImageDataHolder() = default;	
	const MyString& getImageName() const { return imageName; }

protected:
	MyString imageName;
};
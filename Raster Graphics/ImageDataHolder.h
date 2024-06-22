#pragma once
#include "Image.h"
class ImageDataHolder
{
public:
	virtual ~ImageDataHolder() = default;	
	const MyString& getImageName() const { return imageName; }

private:
	MyString imageName;
};
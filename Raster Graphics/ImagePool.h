#pragma once
#include "Image.h"
#include "MyVector.hpp"

class ImagePool
{
public:
	ImagePool() = default;
	const Image* getAllocatedImage(const MyString& fileName);
	void releaseImage(const MyString& fileName);
	ImagePool(const ImagePool& other) = delete;
	ImagePool& operator=(const ImagePool& other) = delete;
	~ImagePool();

private:
	unsigned allocatedNewImage(const MyString& fileName);
	unsigned findAllocatedImage(const MyString& fileName) const;

	void removeRecord(unsigned index);

	struct ImageRecord
	{
		Image* image = nullptr;
		unsigned refCount = 0;
		MyString fileName;
	};
	MyVector<ImageRecord> imageRecords;
};
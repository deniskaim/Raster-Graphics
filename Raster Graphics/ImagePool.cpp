#include "ImagePool.h"
#include "ImageFactory.h"
#pragma warning (disable : 4996)

const Image* ImagePool::getAllocatedImage(const MyString& fileName)
{
	unsigned index = findAllocatedImage(fileName);

	if (index != -1)
	{
		imageRecords[index].refCount++;
		return imageRecords[index].image;
	}
	else
	{
		unsigned index = allocatedNewImage(fileName);
		imageRecords[index].refCount++;
		return imageRecords[index].image;
	}


}

void ImagePool::releaseImage(const MyString& fileName)
{
	unsigned index = findAllocatedImage(fileName);
	
	imageRecords[index].refCount--;
	if (imageRecords[index].refCount == 0)
		removeRecord(index);

}
void ImagePool::removeRecord(unsigned index)
{
	unsigned lastIndex = imageRecords.getSize() - 1;
	std::swap(imageRecords[index], imageRecords[lastIndex]);

	// delete the memory of Image* after there are no instances
	delete[] imageRecords[lastIndex].image; 
	imageRecords[lastIndex].image = nullptr;
	imageRecords[lastIndex].refCount = 0;

	imageRecords.popBack();  // size--
}

ImagePool::~ImagePool()
{
	for (int i = 0; i < imageRecords.getCapacity(); i++)
		delete imageRecords[i].image; // delete the memory of Image* (it shouldn't be necessary since we delete it in removeRecord()

}
unsigned ImagePool::allocatedNewImage(const MyString& fileName)
{
	ImageRecord newRecord;
	newRecord.fileName = fileName;
	newRecord.refCount = 0;
	newRecord.image = imageFactory(fileName); // ????
	// MUST handle the .image problem !!!

	unsigned index = imageRecords.getSize();
	imageRecords.pushBack(newRecord);

	return index;
}
unsigned ImagePool::findAllocatedImage(const MyString& fileName) const
{
	unsigned size = imageRecords.getSize();
	for (int i = 0; i < size; i++)
	{
		if (imageRecords[i].fileName == fileName)
			return i;
	}
	return -1;
}
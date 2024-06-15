#include "ImageCollection.h"

ImageCollection::ImageCollection() : capacity(8)
{
	data = new Image * [capacity] {nullptr};
}
ImageCollection::ImageCollection(const ImageCollection& other)
{
	copyFrom(other);
}
ImageCollection& ImageCollection::operator=(const ImageCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ImageCollection::ImageCollection(ImageCollection&& other) noexcept
{
	moveFrom(std::move(other));
}
ImageCollection& ImageCollection::operator=(ImageCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
ImageCollection::~ImageCollection()
{
	free();
}


void ImageCollection::addImage(Image*& image)
{
	if (size >= capacity)
		resize(capacity * 2);

	data[size++] = image;
	image = nullptr;
}
void ImageCollection::addImage(const Image& image)
{
	Image* cloned = image.clone();
	addImage(cloned);
}

void ImageCollection::free()
{
	for (int i = 0; i < size; i++)
		delete data[i]; // virt ~Image()

	delete[] data;
}
void ImageCollection::copyFrom(const ImageCollection& other)
{
	data = new Image * [other.capacity];
	for (int i = 0; i < other.size; i++)
		data[i] = other.data[i]->clone();

	size = other.size;
	capacity = other.capacity;
}
void ImageCollection::moveFrom(ImageCollection&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;
	other.size = other.capacity = 0;
}
void ImageCollection::resize(size_t newCap)
{
	Image** newArr = new Image * [newCap];
	for (int i = 0; i < size; i++)
		newArr[i] = data[i];

	delete[] data;
	data = newArr;
	capacity = newCap;
}

size_t ImageCollection::getSize() const
{
	return size;
}
const Image* ImageCollection::operator[](size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Out of range!");

	return data[index];
}
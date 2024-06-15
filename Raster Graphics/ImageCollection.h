#pragma once
#include "Image.h"

class ImageCollection
{

public:
	ImageCollection();
	ImageCollection(const ImageCollection& other);
	ImageCollection& operator=(const ImageCollection& other);
	ImageCollection(ImageCollection&& other) noexcept;
	ImageCollection& operator=(ImageCollection&& other) noexcept;
	~ImageCollection() noexcept;

	void addImage(const Image& image);
	void addImage(Image*& image);

	const Image* operator[](size_t index) const;
	size_t getSize() const;

private:
	Image** data = nullptr;
	size_t capacity = 0;
	size_t size = 0;

	void resize(size_t newCap);
	void free();
	void copyFrom(const ImageCollection& other);
	void moveFrom(ImageCollection&& other);
};
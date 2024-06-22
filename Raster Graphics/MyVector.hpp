#pragma once
#include <iostream>
template <typename T>
class MyVector
{
public:
	MyVector();
	MyVector(size_t capacity);

	MyVector(const MyVector<T>& other);
	MyVector& operator=(const MyVector<T>& other);
	MyVector(MyVector<T>&& other) noexcept;
	MyVector& operator=(MyVector<T>&& other) noexcept;
	~MyVector() noexcept;

	size_t getSize() const;
	size_t getCapacity() const;

	void pushBack(const T& element);
	void pushBack(T&& element);
	void pushAt(const T& element, size_t index);
	void pushAt(T&& element, size_t index);
	T popBack();
	T popAt(size_t index);

	bool empty() const;
	void clear();
	
	const T& operator[](size_t index) const;
	T& operator[](size_t index);

private:

	static const short INITIAL_CAPACITY = 4;

	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCap);
	void upsizeIfNeeded();
	void assertIndex(size_t index) const;

	void free();
	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other);
};

template <typename T>
void MyVector<T>::resize(size_t newCap)
{
	T* newArr = new T[newCap];

	for (int i = 0; i < size; i++)
		newArr[i] = std::move(data[i]);

	delete[] data;
	data = newArr;
	capacity = newCap;
}

template <typename T>
void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.size; i++)
		data[i] = other.data[i];

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void MyVector<T>::moveFrom(MyVector<T>&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;
	other.size = other.capacity = 0;
}


template <typename T>
MyVector<T>::MyVector() : MyVector(INITIAL_CAPACITY)
{}

template <typename T>
MyVector<T>::MyVector(size_t capacity)
{
	data = new T[capacity];
	this->capacity = capacity;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
MyVector<T>::~MyVector() noexcept
{
	free();
}

template <typename T>
size_t MyVector<T>::getSize() const
{
	return size;
}

template <typename T>
size_t MyVector<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
void MyVector<T>::upsizeIfNeeded()
{
	if (size >= capacity)
		resize(capacity * 2);
}

template<typename T>
void MyVector<T>::assertIndex(size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Out of range!");
	
}
template <typename T>
void MyVector<T>::pushBack(const T& element)
{
	upsizeIfNeeded();
	data[size++] = element;
}

template <typename T>
void MyVector<T>::pushBack(T&& element)
{
	upsizeIfNeeded();
	data[size++] = std::move(element);
}

template <typename T>
void MyVector<T>::pushAt(const T& element, size_t index)
{
	assertIndex(index);
	upsizeIfNeeded();

	for (int i = size; i > index; i--)
		data[i] = std::move(data[i - 1]);
	
	data[index] = element;
	size++;
}

template <typename T>
void MyVector<T>::pushAt(T&& element, size_t index)
{
	assertIndex(index);
	upsizeIfNeeded();

	for (int i = size; i > index; i--)
		data[i] = std::move(data[i - 1]);

	data[index] = std::move(element);
	size++;
}

template <typename T>
T MyVector<T>::popBack()
{
	if (empty())
		throw std::exception("Vector is empty!");

	return data[--size];
}

template <typename T>
T MyVector<T>::popAt(size_t index)
{
	assertIndex(index);

	T temp = data[index];
	size--;

	for (int i = index; i < size; i++)
		data[i] = std::move(data[i + 1]);

	return temp;
}

template<typename T>
bool MyVector<T>::empty() const 
{
	return size == 0;
}

template<typename T>
void MyVector<T>::clear() 
{
	size = 0;
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const 
{
	assertIndex(index);
	return data[index];
}

template<typename T>
T& MyVector<T>::operator[](size_t index)
{
	assertIndex(index);
	return data[index];
}
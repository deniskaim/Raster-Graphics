#pragma once
#include <utility>

template<typename T>
class Polymorphic_ptr {
private:
	T* ptr = nullptr;
public:
	Polymorphic_ptr() = default;
	Polymorphic_ptr(T* ptr);
	Polymorphic_ptr(const Polymorphic_ptr<T>& other);
	Polymorphic_ptr(Polymorphic_ptr<T>&& other) noexcept;
	Polymorphic_ptr<T>& operator=(const Polymorphic_ptr<T>& other);
	Polymorphic_ptr<T>& operator=(Polymorphic_ptr<T>&& other) noexcept;
	~Polymorphic_ptr();

	T* operator->();
	const T* operator->() const;
	T& operator*();
	const T& operator*() const;

	T* get();
	const T* get() const;
	void reset(T* ptr);
	T* release(); // releases the ownership of the pointer

private:
	void free();
	void copyFrom(const Polymorphic_ptr& other);
	void moveFrom(Polymorphic_ptr&& other);
};


template<typename T>
Polymorphic_ptr<T>::Polymorphic_ptr(T* ptr) : ptr(ptr)
{ }

template<typename T>
Polymorphic_ptr<T>::Polymorphic_ptr(const Polymorphic_ptr<T>& other) {
	copyFrom(other);
}

template<typename T>
Polymorphic_ptr<T>::Polymorphic_ptr(Polymorphic_ptr<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<typename T>
Polymorphic_ptr<T>& Polymorphic_ptr<T>::operator=(const Polymorphic_ptr<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Polymorphic_ptr<T>& Polymorphic_ptr<T>::operator=(Polymorphic_ptr<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
Polymorphic_ptr<T>::~Polymorphic_ptr() {
	free();
}

template<typename T>
T* Polymorphic_ptr<T>::operator->() {
	return ptr;
}

template<typename T>
const T* Polymorphic_ptr<T>::operator->() const {
	return ptr;
}

template<typename T>
T& Polymorphic_ptr<T>::operator*() {
	return *ptr;
}

template<typename T>
const T& Polymorphic_ptr<T>::operator*() const {
	return *ptr;
}

template<typename T>
T* Polymorphic_ptr<T>::get() {
	return ptr;
}

template<typename T>
const T* Polymorphic_ptr<T>::get() const {
	return ptr;
}

template<typename T>
void Polymorphic_ptr<T>::reset(T* ptr) {
	free();
	this->ptr = ptr;
}

template<typename T>
T* Polymorphic_ptr<T>::release() {
	T* temp = ptr;
	ptr = nullptr;
	return temp;
}

template<typename T>
void Polymorphic_ptr<T>::free() {
	delete ptr;
}

template<typename T>
void Polymorphic_ptr<T>::copyFrom(const Polymorphic_ptr& other) {
	ptr = other.ptr->clone();
}

template<typename T>
void Polymorphic_ptr<T>::moveFrom(Polymorphic_ptr&& other) {
	ptr = other.ptr;
	other.ptr = nullptr;
}
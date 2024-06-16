#pragma once
#include "ImagesCollection.h"
#include "Transformation.h"
#include "MyVector.hpp"
#include "Polymorphic_ptr.h"

class TransformationExecutor
{
public:
	TransformationExecutor() = default;
	TransformationExecutor(const TransformationExecutor& other) = delete;
	TransformationExecutor& operator=(const TransformationExecutor& other) = delete;
	~TransformationExecutor() = default;

	void addTransformation(const Polymorphic_ptr<Transformation>& transformation);
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);

	void close();
	void executeAll(ImagesCollection& imageCollection); // TODO : add executeAll when a fileName is given
	void printTransformations() const;

private:
	MyVector<Polymorphic_ptr<Transformation>> transformationsInSession; // necessery for the print function !
};
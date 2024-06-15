#pragma once
#include "Transformation.h"
#include "Polymorphic_ptr.h"
#include "MyQueue.hpp"
#include "MyStack.hpp"

class TransformationExecutor
{
public:
	TransformationExecutor() = default;
	TransformationExecutor(const TransformationExecutor& other) = delete;
	TransformationExecutor& operator=(const TransformationExecutor& other) = delete;
	~TransformationExecutor() = default;

	void add(const Polymorphic_ptr<Transformation>& transformation);
	void add(Polymorphic_ptr<Transformation>&& transformation);
	void execute();
	void executeAll();
	void undo();

	bool isEmpty() const;
	void clear();

private:
	MyQueue<Polymorphic_ptr<Transformation>> toExecute;
	MyStack<Polymorphic_ptr<Transformation>> executed;
};
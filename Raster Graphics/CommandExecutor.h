#pragma once
#include "Command.h"
#include "Polymorphic_ptr.h"
#include "MyQueue.hpp"
#include "MyStack.hpp"

class CommandExecutor
{
public:
	CommandExecutor() = default;
	CommandExecutor(const CommandExecutor& other) = delete;
	CommandExecutor& operator=(const CommandExecutor& other) = delete;
	~CommandExecutor() = default;

	void add(Command* command);
	void execute();
	void executeAll();
	void undo();

private:
	MyQueue<Polymorphic_ptr<Command>> toExecute;
	MyStack<Polymorphic_ptr<Command>> executed;
};
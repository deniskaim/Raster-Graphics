#pragma once

// class Application;

class Command
{
public:
	virtual void execute() const = 0;
	// no need for "undo" since it will be used to pop from the queue(,) which saves the pending transformations
	virtual Command* clone() const = 0;
	virtual ~Command() = default;
};


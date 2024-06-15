#pragma once
#include "Application.h"

enum class Commands
{
	grayscale,
	monochrome,
	negative,
	rotateLeft,
	rotateRight,
	undo,
	add,
	sessionInfo,
	switchSession,
	collage,
	load,
	close,
	save,
	saveAs,
	help,
	exit,
	ERROR

};
class Command
{
public:
	virtual void execute(Application&) const = 0;
	// no need for "undo" since it will be used to pop from the queue(,) which saves the pending transformations
	// virtual Command* clone() const = 0;
	virtual ~Command() = default;
};


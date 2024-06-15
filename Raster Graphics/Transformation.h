#pragma once
#include "Command.h"

enum class Type
{
	grayscale,
	monochrome,
	negative,
	rotateLeft,
	rotateRight
};

class Transformation : public Command
{
public:
	virtual Transformation* clone() const = 0;
	Type getType() const { return type; }
protected:

	Type type;
};
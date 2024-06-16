#pragma once
#include "Command.h"



class Transformation : public Command
{
protected:
	enum class Type
	{
		grayscale,
		monochrome,
		negative,
		rotateLeft,
		rotateRight
	};
	Type type;


public:
	virtual Transformation* clone() const = 0;
	Type getType() const { return type; }
};
#pragma once
#include "Transformation.h"

class RotateLeft : public Transformation
{
public:
	RotateLeft();
	void execute() const override;
	void printType() const override;
	Transformation* clone() const override;

};
#pragma once
#include "Transformation.h"

class RotateRight : public Transformation
{
public:
	RotateRight();
	void execute() const override;
	void printType() const override;
	Transformation* clone() const override;

};
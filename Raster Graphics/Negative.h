#pragma once
#include "Transformation.h"

class Negative : public Transformation
{
public:
	Negative();
	void execute() const override;
	void printType() const override;
	Transformation* clone() const override;
};
#pragma once
#include "Transformation.h"

class Grayscale: public Transformation
{
public:
	Grayscale();
	void execute() const override;
	void printType() const override;
	Transformation* clone() const override;
};
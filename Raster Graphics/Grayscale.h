#pragma once
#include "Transformation.h"

class Grayscale: public Transformation
{
public:
	Grayscale();
	void execute(Application& application) const override;
	Transformation* clone() const override;
};
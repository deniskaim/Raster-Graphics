#pragma once
#include "Transformation.h"

class Monochrome : public Transformation
{
public:
	Monochrome();
	void execute(Application& application) const override;
	void printType() const override;
	Transformation* clone() const override;
};
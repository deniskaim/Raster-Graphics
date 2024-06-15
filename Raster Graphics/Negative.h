#pragma once
#include "Transformation.h"

class Negative : public Transformation
{
public:
	Negative();
	void execute(Application& application) const override;
	Transformation* clone() const override;
};
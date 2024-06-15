#pragma once
#include "Transformation.h"

class Grayscale: public Transformation
{
public:
	void execute(Application& application) const override;
};
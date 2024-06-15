#pragma once
#include "Transformation.h"

class Monochrome : public Transformation
{
public:
	void execute(Application& application) const override;
};
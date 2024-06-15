#pragma once
#include "Transformation.h"

class Negative : public Transformation
{
public:
	void execute(Application& application) const override;
};
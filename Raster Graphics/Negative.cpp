#include "Negative.h"

void Negative::execute(Application& application) const
{
	application.addTransformation(this);
}
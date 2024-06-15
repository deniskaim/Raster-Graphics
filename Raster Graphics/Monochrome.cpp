#include "Monochrome.h"

void Monochrome::execute(Application& application) const
{
	application.addTransformation(this);
}

#include "Grayscale.h"

void Grayscale::execute(Application& application) const
{
	application.addTransformation(this);
}
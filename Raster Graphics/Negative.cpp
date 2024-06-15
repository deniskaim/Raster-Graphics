#include "Negative.h"

Negative::Negative()
{
	type = Type::negative;
}
void Negative::execute(Application& application) const
{
	Transformation* cloned = clone();
	Polymorphic_ptr<Transformation> transformation(cloned);
	application.addTransformation(transformation);
}
Transformation* Negative::clone() const
{
	return new Negative(*this);
}
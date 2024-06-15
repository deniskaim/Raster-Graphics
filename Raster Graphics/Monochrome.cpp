#include "Monochrome.h"

Monochrome::Monochrome()
{
	type = Type::monochrome;
}
void Monochrome::execute(Application& application) const
{
	Transformation* cloned = clone();
	Polymorphic_ptr<Transformation> transformation(cloned);
	application.addTransformation(std::move(transformation));
}
Transformation* Monochrome::clone() const
{
	return new Monochrome(*this);
}
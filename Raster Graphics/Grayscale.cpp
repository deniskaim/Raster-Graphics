#include "Grayscale.h"

Grayscale::Grayscale()
{
	type = Type::grayscale;
}
void Grayscale::execute(Application& application) const
{
	Transformation* cloned = clone();
	Polymorphic_ptr<Transformation> transformation(cloned);
	application.addTransformation(std::move(transformation));
}
Transformation* Grayscale::clone() const
{
	return new Grayscale(*this);
}
#include "Grayscale.h"
#include "Application.h"

Grayscale::Grayscale()
{
	type = Type::grayscale;
}
void Grayscale::execute(Application& application) const
{
	Polymorphic_ptr<Transformation> transformation(clone());
	application.addTransformation(std::move(transformation));
}
void Grayscale::printType() const
{
	std::cout << "grayscale";
}
Transformation* Grayscale::clone() const
{
	return new Grayscale(*this);
}
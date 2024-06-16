#include "Monochrome.h"
#include "Application.h"

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
void Transformation::printType() const
{
	std::cout << "monochrome";
}
Transformation* Monochrome::clone() const
{
	return new Monochrome(*this);
}
#include "Negative.h"
#include "Application.h"

Negative::Negative()
{
	type = Type::negative;
}
void Negative::execute(Application& application) const
{
	Polymorphic_ptr<Transformation> transformation(clone());
	application.addTransformation(transformation);
}
void Negative::printType() const
{
	std::cout << "negative";
}
Transformation* Negative::clone() const
{
	return new Negative(*this);
}
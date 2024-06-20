#include "Negative.h"
#include "Application.h"

Negative::Negative()
{
	type = Type::negative;
}
void Negative::execute() const
{
	Application& application = Application::getInstance();

	application.addTransformation(Polymorphic_ptr<Transformation>(clone()));
}
void Negative::printType() const
{
	std::cout << "negative";
}
Transformation* Negative::clone() const
{
	return new Negative(*this);
}
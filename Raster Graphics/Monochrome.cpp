#include "Monochrome.h"
#include "Application.h"

Monochrome::Monochrome()
{
	type = Type::monochrome;
}
void Monochrome::execute() const
{
	Application& application = Application::getInstance();

	application.addTransformation(Polymorphic_ptr<Transformation> (clone()));
}
void Monochrome::printType() const
{
	std::cout << "monochrome";
}
Transformation* Monochrome::clone() const
{
	return new Monochrome(*this);
}
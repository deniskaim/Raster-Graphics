#include "Grayscale.h"
#include "Application.h"

Grayscale::Grayscale()
{
	type = Type::grayscale;
}
void Grayscale::execute() const
{
	Application& application = Application::getInstance();

	application.addTransformation(Polymorphic_ptr<Transformation>(clone()));
}
void Grayscale::printType() const
{
	std::cout << "grayscale";
}
Transformation* Grayscale::clone() const
{
	return new Grayscale(*this);
}
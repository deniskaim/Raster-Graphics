#include "RotateLeft.h"
#include "Application.h"

RotateLeft::RotateLeft()
{
	type = Type::rotateLeft;
}
void RotateLeft::execute() const
{
	Application& application = Application::getInstance();
	application.addTransformation(Polymorphic_ptr<Transformation>(clone()));
}
void RotateLeft::printType() const
{
	std::cout << "rotate left";
}
Transformation* RotateLeft::clone() const
{
	return new RotateLeft(*this);
}
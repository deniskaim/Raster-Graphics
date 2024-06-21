#include "RotateRight.h"
#include "Application.h"

RotateRight::RotateRight()
{
	type = Type::rotateLeft;
}
void RotateRight::execute() const
{
	Application& application = Application::getInstance();
	application.addTransformation(Polymorphic_ptr<Transformation>(clone()));
}
void RotateRight::printType() const
{
	std::cout << "rotate left";
}
Transformation* RotateRight::clone() const
{
	return new RotateRight(*this);
}
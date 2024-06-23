#include "SaveCommand.h"
#include "Application.h"

void SaveCommand::execute() const
{
	Application& application = Application::getInstance();
	application.save();
}
Command* SaveCommand::clone() const
{
	return new SaveCommand(*this);
}
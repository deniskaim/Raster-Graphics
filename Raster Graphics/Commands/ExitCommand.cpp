#include "ExitCommand.h"
#include "Application.h"

void ExitCommand::execute() const
{
	Application& application = Application::getInstance();
	application.exit();
}
Command* ExitCommand::clone() const
{
	return new ExitCommand(*this);
}
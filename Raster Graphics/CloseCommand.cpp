#include "CloseCommand.h"
#include "Application.h"

void CloseCommand::execute() const
{
	Application& application = Application::getInstance();
	application.close();
}
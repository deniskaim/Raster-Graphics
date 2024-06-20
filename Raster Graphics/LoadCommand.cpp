#include "LoadCommand.h"
#include "Application.h"

void LoadCommand::execute() const
{
	Application& application = Application::getInstance();
	application.loadSession(SessionFactory());
}
Command* LoadCommand::clone() const
{
	return new LoadCommand(*this);
}
#include "LoadCommand.h"
#include "Application.h"

LoadCommand::LoadCommand(const MyVector<MyString>& imagesNames) : imagesNames(imagesNames)
{}

void LoadCommand::execute() const
{
	Application& application = Application::getInstance();
	application.loadSession(imagesNames);
}
Command* LoadCommand::clone() const
{
	return new LoadCommand(*this);
}
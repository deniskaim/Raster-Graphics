#include "SaveAsCommand.h"
#include "Application.h"

SaveAsCommand::SaveAsCommand(const MyString& fileName) : fileName(fileName)
{}

void SaveAsCommand::execute() const
{
	Application& application = Application::getInstance();
	application.saveAs(fileName);
}

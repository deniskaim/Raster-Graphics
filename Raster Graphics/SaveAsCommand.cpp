#include "SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(const MyString& fileName) : fileName(fileName)
{}

void SaveAsCommand::execute(Application& application) const
{
	application.saveAs(fileName);
}

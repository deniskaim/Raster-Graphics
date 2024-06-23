#include "UndoCommand.h"
#include "Application.h"

void UndoCommand::execute() const
{
	Application& application = Application::getInstance();
	application.undo();
}
Command* UndoCommand::clone() const
{
	return new UndoCommand(*this);
}
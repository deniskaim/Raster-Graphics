#include "ExitCommand.h"
#include "Application.h"

void ExitCommand::execute(Application& application) const
{
	application.exit();
}
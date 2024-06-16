#include "CloseCommand.h"
#include "Application.h"

void CloseCommand::execute(Application& application) const
{
	application.close();
}
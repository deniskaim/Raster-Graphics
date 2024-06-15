#include "CloseCommand.h"

void CloseCommand::execute(Application& application) const
{
	application.close();
}
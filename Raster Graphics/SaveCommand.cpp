#include "SaveCommand.h"
#include "Application.h"

void SaveCommand::execute(Application& application) const
{
	application.save();
}
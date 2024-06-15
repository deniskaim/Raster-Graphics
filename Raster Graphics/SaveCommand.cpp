#include "SaveCommand.h"

void SaveCommand::execute(Application& application) const
{
	Session& currentSession = application.getCurrentSession();
	currentSession.save();
}
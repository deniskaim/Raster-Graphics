#include "LoadCommand.h"
#include "Application.h"

void LoadCommand::execute(Application& application) const
{
	Session newSession;
	// TODO: check if there is atleast one image to load/add in the session
	while (true)
	{
		newSession.addImage(ImageFactory());
	}
	application.loadNewSession(newSession);
}
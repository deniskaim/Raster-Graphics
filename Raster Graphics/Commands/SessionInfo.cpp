#include "SessionInfo.h"
#include "Application.h"

void SessionInfo::execute() const
{
	Application& application = Application::getInstance();
	application.getCurrentSessionInfo();
}
Command* SessionInfo::clone() const
{
	return new SessionInfo(*this);
}
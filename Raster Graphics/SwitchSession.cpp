#include "SwitchSession.h"
#include "Application.h"
SwitchSession::SwitchSession(size_t sessionIndex) : sessionIndex(sessionIndex)
{}

void SwitchSession::execute() const
{
	Application& application = Application::getInstance();
	application.switchSession(sessionIndex);
}
Command* SwitchSession::clone() const
{
	return new SwitchSession(*this);
}
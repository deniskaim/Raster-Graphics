#include "SwitchSession.h"
#include "Application.h"
SwitchSession::SwitchSession(size_t sessionIndex) : sessionIndex(sessionIndex)
{}

void SwitchSession::execute() const
{
	Application& application = Application::getInstance();
	application.switchSession(sessionIndex);

	std::cout << "You have successfully switched the session!" << std::endl;
	application.getCurrentSessionInfo();
}
Command* SwitchSession::clone() const
{
	return new SwitchSession(*this);
}
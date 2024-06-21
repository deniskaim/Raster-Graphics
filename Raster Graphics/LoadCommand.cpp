#include "LoadCommand.h"
#include "Application.h"
/*
LoadCommand::LoadCommand(Session* ptr) 
{
	sessionPtr = ptr;
}
LoadCommand::LoadCommand(const LoadCommand& other) : Command(other)
{
	copyFrom(other);
}
LoadCommand& LoadCommand::operator=(const LoadCommand& other)
{
	if (this != &other)
	{
		free();
		Command::operator=(other);
		copyFrom(other);
	}
	return *this;
}
LoadCommand::LoadCommand(LoadCommand&& other) : Command(std::move(other))
{
	moveFrom(std::move(other));
}
LoadCommand& LoadCommand::operator=(LoadCommand&& other)
{
	if (this != &other)
	{
		free();
		Command::operator=(std::move(other));
		moveFrom(std::move(other));
	}
	return *this;
}
LoadCommand::~LoadCommand()
{
	free();
}
void LoadCommand::free()
{
	delete sessionPtr;
}
void LoadCommand::copyFrom(const LoadCommand& other)
{
	sessionPtr = new Session(*other.sessionPtr);
}
void LoadCommand::moveFrom(LoadCommand&& other)
{
	sessionPtr = other.sessionPtr;
	other.sessionPtr = nullptr;
}
LoadCommand::LoadCommand(const MyVector<MyString>& imagesNames)
{
}
*/

LoadCommand::LoadCommand(const MyVector<MyString>& imagesNames) : imagesNames(imagesNames)
{}

void LoadCommand::execute() const
{
	Application& application = Application::getInstance();
	application.loadSession(imagesNames);
}
Command* LoadCommand::clone() const
{
	return new LoadCommand(*this);
}
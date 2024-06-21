#pragma once
#include "Command.h"
#include "Polymorphic_ptr.h"

class CommandFactory
{
public:
	static Polymorphic_ptr<Command> createCommand();

private:
	static Polymorphic_ptr<Command> createLoadCommand();
	static Polymorphic_ptr<Command> createSaveAsCommand();
	static Polymorphic_ptr<Command> createRotateCommand();
	static Polymorphic_ptr<Command> createAddCommand();
	static Polymorphic_ptr<Command> createSessionInfoCommand();
	static Polymorphic_ptr<Command> createCollageCommand();
};
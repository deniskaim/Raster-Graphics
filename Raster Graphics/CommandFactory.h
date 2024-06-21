#pragma once
#include "Command.h"
// #include "Polymorphic_ptr.h"

class CommandFactory
{
public:
	static Command* createCommand();

private:
	static Command* createLoadCommand();
	static Command* createSaveAsCommand();
	static Command* createAddCommand();
	static Command* createSessionInfoCommand();
	static Command* createCollageCommand();
};
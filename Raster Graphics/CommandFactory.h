#pragma once
#include "Command.h"
#include "Polymorphic_ptr.hpp"
#include <fstream>

class CommandFactory
{
public:
	static Polymorphic_ptr<Command> createCommand();

private:
	static Polymorphic_ptr<Command> createLoadCommand(std::stringstream& ss);
	static Polymorphic_ptr<Command> createSaveAsCommand(std::stringstream& ss);
	static Polymorphic_ptr<Command> createRotateCommand(std::stringstream& ss);
	static Polymorphic_ptr<Command> createAddCommand(std::stringstream& ss);
	static Polymorphic_ptr<Command> createSessionInfoCommand(std::stringstream& ss);
	static Polymorphic_ptr<Command> createSwitchSessionCommand(std::stringstream& ss);
	// static Polymorphic_ptr<Command> createCollageCommand(std::stringstream& ss);

};
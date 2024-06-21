#include "CommandFactory.h"
#include "SessionFactory.h" // necessary for the loadCommand
#include <sstream>

#include "LoadCommand.h"
#include "CloseCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "HelpCommand.h"
#include "ExitCommand.h"

#include "Grayscale.h"
#include "Monochrome.h"
#include "Negative.h"

Polymorphic_ptr<Command> CommandFactory::createCommand()
{
	printCommandKey();

	MyString commandString;
	std::cin >> commandString;

	if (commandString == "load")
		return createLoadCommand();

	else if (commandString == "close")
		return new CloseCommand;

	else if (commandString == "save")
		return new SaveCommand;

	else if (commandString == "saveas")
		return createSaveAsCommand();

	else if (commandString == "help")
		return new HelpCommand;

	else if (commandString == "exit")
		return new ExitCommand;

	else if (commandString == "grayscale")
		return new Grayscale;

	else if (commandString == "monochrome")
		return new Monochrome;

	else if (commandString == "negative")
		return new Negative;

	else if (commandString == "rotate")
	{
		return createRotateCommand();
		/*
		if (commandLine == "rotate left")
			return new RotateLeft;

		else if (commandLine == "rotate right")
			return new RotateRight;*/
	}
	else if (commandString == "undo")
		return new UndoCommand;

	else if (commandString == "add")
		return createAddCommand();

	else if (commandLine == "session info")
		return new SessionInfoCommand();

	else if (commandString == "switch")
		return new createSwitchSessionCommand();

	else if (commandString == "collage")
		return new createCollageCommand();

}
Polymorphic_ptr<Command> CommandFactory::createLoadCommand()
{
	Session* sessionPtr = createSession();
	return new LoadCommand(sessionPtr);
}
static void printCommandKey()
{
	std::cout << "> ";
}
static MyString getLine()
{
	const size_t NAME_SIZE = 1024;
	char str[NAME_SIZE];

	std::cin.getline(str, NAME_SIZE);
	
	return MyString(str);
}

#include "CommandFactory.h"
#include "SessionFactory.h" // necessary for the loadCommand
#include <sstream>

#include "LoadCommand.h"
#include "CloseCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "HelpCommand.h"
#include "ExitCommand.h"
#include "UndoCommand.h"
#include "SessionInfo.h"
#include "SwitchSession.h"

#include "Grayscale.h"
#include "Monochrome.h"
#include "Negative.h"
#include "RotateLeft.h"
#include "RotateRight.h"

Polymorphic_ptr<Command> CommandFactory::createCommand()
{
	printCommandKey();

	MyString commandString;
	std::cin >> commandString;

	if (commandString == "load")
		return createLoadCommand();

	else if (commandString == "close" && !hasMoreInput())
		return new CloseCommand;

	else if (commandString == "save" && !hasMoreInput())
		return new SaveCommand;

	else if (commandString == "saveas" && !hasMoreInput())
		return createSaveAsCommand();

	else if (commandString == "help" && !hasMoreInput())
		return new HelpCommand;

	else if (commandString == "exit" && !hasMoreInput())
		return new ExitCommand;

	else if (commandString == "grayscale" && !hasMoreInput())
		return new Grayscale;

	else if (commandString == "monochrome" && !hasMoreInput())
		return new Monochrome;

	else if (commandString == "negative" && !hasMoreInput())
		return new Negative;

	else if (commandString == "rotate")
		return createRotateCommand();

	else if (commandString == "undo" && !hasMoreInput())
		return new UndoCommand;

	else if (commandString == "add")
		return createAddCommand();

	else if (commandString == "session")
		return createSessionInfoCommand();
	
	else if (commandString == "switch")
		return new createSwitchSessionCommand();

	else if (commandString == "collage")
		return new createCollageCommand();


	return nullptr;

}
Polymorphic_ptr<Command> CommandFactory::createLoadCommand()
{
	Session* sessionPtr = createSession();
	return new LoadCommand(sessionPtr);
}
Polymorphic_ptr<Command> CommandFactory::createRotateCommand()
{
	MyString type;
	std::cin >> type;
	bool hasExtraSymbols = hasMoreInput();
	if (type == "left" && !hasExtraSymbols)
		return new RotateLeft;
	else if (type == "right" && !hasExtraSymbols)
		return new RotateRight;
	else
		return nullptr;
}
Polymorphic_ptr<Command> CommandFactory::createSessionInfoCommand()
{
	MyString nextWord;
	std::cin >> nextWord;
	bool extraSymbols = hasMoreInput();
	if (nextWord == "info" && !extraSymbols)
		return new SessionInfo;
	else
		return nullptr;
}
Polymorphic_ptr<Command> CommandFactory::createSwitchSessionCommand()
{
	int index;
	std::cin >> index;
	
	if (!hasMoreInput())
		return new SwitchSession(index);
	else
		return nullptr;
}
static void printCommandKey()
{
	std::cout << "> ";
}
static bool hasMoreInput() 
{
	if (std::cin.peek() != '\n' && std::cin.peek() != EOF) 
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}
	// Clear the newline character from the input buffer
	std::cin.ignore();
	return false;
}

static MyString getLine()
{
	const size_t NAME_SIZE = 1024;
	char str[NAME_SIZE];

	std::cin.getline(str, NAME_SIZE);
	
	return MyString(str);
}

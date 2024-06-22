#include "CommandFactory.h"
#include <sstream>
#include <iostream> 

#include "LoadCommand.h"
#include "CloseCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "HelpCommand.h"
#include "ExitCommand.h"
#include "UndoCommand.h"
#include "SessionInfo.h"
#include "SwitchSession.h"
#include "AddImage.h"

#include "Grayscale.h"
#include "Monochrome.h"
#include "Negative.h"
#include "RotateLeft.h"
#include "RotateRight.h"

static void printCommandKey()
{
	std::cout << "> ";
}
Polymorphic_ptr<Command> CommandFactory::createCommand()
{
	printCommandKey();

	const size_t BUFFSIZE = 1024;
	char buff[BUFFSIZE];
	std::cin.getline(buff, BUFFSIZE);
	std::stringstream ss(buff);

	MyString commandString;
	ss >> commandString;

	if (commandString == "load")
		return createLoadCommand(ss);

	else if (commandString == "close" && ss.eof())
		return new CloseCommand;

	else if (commandString == "save" && ss.eof())
		return new SaveCommand;

	else if (commandString == "saveas" && ss.eof())
		return createSaveAsCommand(ss);

	else if (commandString == "help" && ss.eof())
		return new HelpCommand;

	else if (commandString == "exit" && ss.eof())
		return new ExitCommand;

	else if (commandString == "grayscale" && ss.eof())
		return new Grayscale;

	else if (commandString == "monochrome" && ss.eof())
		return new Monochrome;

	else if (commandString == "negative" && ss.eof())
		return new Negative;

	else if (commandString == "rotate")
		return createRotateCommand(ss);

	else if (commandString == "undo" && ss.eof())
		return new UndoCommand;

	else if (commandString == "add")
		return createAddCommand(ss);

	else if (commandString == "session")
		return createSessionInfoCommand(ss);
	
	else if (commandString == "switch")
		return createSwitchSessionCommand(ss);

	// else if (commandString == "collage")
		// return createCollageCommand(ss);


	throw std::exception("Invalid try for creating a command!");

}
Polymorphic_ptr<Command> CommandFactory::createSaveAsCommand(std::stringstream& ss)
{
	MyString imageName;
	ss >> imageName;

	if (ss.eof())
		return new SaveAsCommand(imageName);

	else
		throw std::exception("Invalid try for creating a save as command!");
}
Polymorphic_ptr<Command> CommandFactory::createAddCommand(std::stringstream& ss)
{
	MyString imageName;
	ss >> imageName;
	
	if (ss.eof())
		return new AddImage(imageName);
	else
		throw std::exception("Invalid try for creating an add image command!");
}
Polymorphic_ptr<Command> CommandFactory::createLoadCommand(std::stringstream& ss)
{
	MyVector<MyString> imagesNames;
	while (!ss.eof())
	{
		MyString imageName;
		ss >> imageName;
		imagesNames.pushBack(imageName);
	}
	return new LoadCommand(imagesNames);
}
Polymorphic_ptr<Command> CommandFactory::createRotateCommand(std::stringstream& ss)
{
	MyString type;
	ss >> type;
	if (type == "left" && ss.eof())
		return new RotateLeft;

	else if (type == "right" && ss.eof())
		return new RotateRight;

	else
		throw std::exception("Invalid try for creating a rotate command!");
}
Polymorphic_ptr<Command> CommandFactory::createSessionInfoCommand(std::stringstream& ss)
{
	MyString nextWord;
	ss >> nextWord;
	if (nextWord == "info" && ss.eof())
		return new SessionInfo;

	else
		throw std::exception("Invalid try for creating a session info command!");
}
Polymorphic_ptr<Command> CommandFactory::createSwitchSessionCommand(std::stringstream& ss)
{
	int index;
	ss >> index;
	
	if (!ss.fail() && ss.eof())
		return new SwitchSession(index);

	else
		throw std::exception("Invalid try for creating a switch session command!");
}

/*
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
*/

/*
static MyString getLine()
{
	const size_t NAME_SIZE = 1024;
	char str[NAME_SIZE];

	std::cin.getline(str, NAME_SIZE);
	
	return MyString(str);
}
*/

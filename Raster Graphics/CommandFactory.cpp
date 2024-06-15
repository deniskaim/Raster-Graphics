#include "CommandFactory.h"
#include "ImageFactory.h"

#include "LoadCommand.h"
Command* commandFactory()
{
	// Directly put the desired command

	/*try
	{
		checkCommandKey();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}*/

	
	const MyString commandString = readString();
	
	if (commandString == "load")
		return new LoadCommand;

	else if (commandString == "close")
		return new Close;

	else if (commandString == "exit")
		return new Exit;

	else if (commandString == "help")
		return new Help;

	else if (commandString == "save")
		return new Save;

	else if (commandString == "save as")
		return new SaveAs;

	else if (commandString == )
}
//static void checkCommandKey()
//{
//	char ch;
//	std::cin >> ch;
//	if (ch != '>')
//		throw std::exception("Incorrect way to enter a command!");
//}
static MyString getLine()
{
	const size_t NAME_SIZE = 1024;
	char str[NAME_SIZE];

	std::cin.getline(str, NAME_SIZE);
	
	return MyString(str);
}
/*
Commands commandFactory()
{
	MyString input = readFileName();

	if (input == "grayscale")
		return Commands::grayscale;

	else if (input == "monochrome")
		return Commands::monochrome;

	else if (input == "negative")
		return Commands::negative;

	else if (input == "rotate left")
		return Commands::rotateLeft;

	else if (input == "rotate right")
		return Commands::rotateRight;

	else if (input == "undo")
		return Commands::undo;

	else if (input == "add")
		return Commands::add;

	else if (input == "session info")
		return Commands::sessionInfo;

	else if (input == "switch")
		return Commands::switchSession;

	else if (input == "collage")
		return Commands::collage;

	else if (input == "help")
		return Commands::help;

	else if (input == "close")
		return Commands::close;

	else if (input == "exit")
		return Commands::exit;

	else if (input == "load")
		return Commands::load;

	else if (input == "save")
		return Commands::save;

	else if (input == "save as")
		return Commands::saveAs;

	else
		return Commands::ERROR;
}
*/
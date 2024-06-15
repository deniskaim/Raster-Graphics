#include "Application.h"

/*
void Application::executeCommand(Commands toExecute)
{
	switch (toExecute)
	{
	case Commands::close:
		return close();

	case Commands::exit:
		return exit();

	case Commands::grayscale:
		return addTransformation(Transformation::grayscale);

	case Commands::monochrome:
		return addTransformation(Transformation::monochrome);

	case Commands::negative:
		return addTransformation(Transformation::negative);

	case Commands::rotateLeft:
		return addTransformation(Transformation::rotateLeft);

	case Commands::rotateRight:
		return addTransformation(Transformation::rotateRight);

	case Commands::help:
		return help();

	case Commands::load:
		return loadSession(); // TODO: read the images and put them as arguments
		
	case Commands::save:
		return save();

	case Commands::saveAs:
		return saveAs(); // TODO: read the file path and put it as an argument

	case Commands::sessionInfo:
		return getCurrentSessionInfo();

	case Commands::switchSession:
		return switchSession(); // TODO: add the index as an argument

	case Commands::undo:
		return undo();

	default:
		throw std::logic_error("Invalid command!");
	}
} */

void Application::executeCommand(const Command* command)
{
	command->execute(*this);
}
void Application::loadSession(const Session& newSession)
{
	sessions.pushBack(newSession);
}
void Application::loadSession(Session&& newSession)
{
	sessions.pushBack(std::move(newSession));
}
void Application::save()
{
	sessions[currentSessionIndex].save();
}
void Application::saveAs(const MyString& fileName)
{
	sessions[currentSessionIndex].saveAs(fileName);
}
void Application::close()
{
	sessions[currentSessionIndex].close();
}
void Application::help()
{
	std::cout << "Available commands:\n";
	std::cout << "1. load <filename> ...\n";
	std::cout << "   - Starts a new session and loads the specified image(s).\n";
	std::cout << "     Example: load image1.ppm image2.pgm\n";
	std::cout << "     Output: Session with ID: <id> started\n\n";

	std::cout << "2. add <image>\n";
	std::cout << "   - Adds the specified image to the current session.\n";
	std::cout << "     Example: add image3.ppm\n\n";

	std::cout << "3. save\n";
	std::cout << "   - Saves all images in the current session, applying all pending transformations.\n\n";

	std::cout << "4. saveas <filename>\n";
	std::cout << "   - Saves the first loaded image in the current session under a new name, applying all pending transformations.\n";
	std::cout << "     Example: saveas new_image.ppm\n\n";

	std::cout << "5. close\n";
	std::cout << "   - Closes the current session without saving.\n\n";

	std::cout << "6. exit\n";
	std::cout << "   - Exits the application.\n\n";

	std::cout << "7. help\n";
	std::cout << "   - Displays this help message.\n\n";

	std::cout << "8. grayscale\n";
	std::cout << "   - Applies a grayscale transformation to all color images in the current session.\n\n";

	std::cout << "9. monochrome\n";
	std::cout << "   - Converts all images in the current session to monochrome (black and white).\n\n";

	std::cout << "10. negative\n";
	std::cout << "    - Applies a negative transformation to all images in the current session.\n\n";

	std::cout << "11. rotate <direction>\n";
	std::cout << "    - Rotates all images in the current session 90 degrees in the specified direction (left or right).\n";
	std::cout << "      Example: rotate left\n\n";

	std::cout << "12. undo\n";
	std::cout << "    - Reverts the last transformation applied in the current session.\n\n";

	std::cout << "13. session info\n";
	std::cout << "    - Displays information about the current session, including session ID, loaded images, and pending transformations.\n\n";

	std::cout << "14. switch <session>\n";
	std::cout << "    - Switches to the specified session by its ID. If the session does not exist, an error message is displayed.\n";
	std::cout << "      Example: switch 2\n\n";

	std::cout << "15. collage <direction> <image1> <image2> <outimage>\n";
	std::cout << "    - Creates a collage of two images from the current session in the specified direction (horizontal or vertical) and saves it as a new image.\n";
	std::cout << "      Example: collage horizontal image1.ppm image2.ppm output_collage.ppm\n";
}
void Application::exit()
{

}
void Application::switchSession(size_t newSessionIndex) const
{
	if (newSessionIndex > sessions.getSize())
		throw std::out_of_range("Invalid session index!");

	currentSessionIndex = newSessionIndex;
}
void Application::getCurrentSessionInfo() const
{
	sessions[currentSessionIndex].printInfo();
}
void Application::addImageToCurrentSession(const Image& image)
{
	sessions[currentSessionIndex].addImage(image);
}
void Application::addImageToCurrentSession(Image*& image)
{
	sessions[currentSessionIndex].addImage(image);
}
void Application::undo()
{
	sessions[currentSessionIndex].undo();
}
void Application::addTransformation(const Command* transformation) // should be Transformation*
{
	sessions[currentSessionIndex].addTransformation(transformation);
}


/*
	const Session& Application::getCurrentSession() const
	{
		return sessions[currentSessionIndex];
	}

	Session& Application::getCurrentSession()
	{
		return sessions[currentSessionIndex];
	}

	void Application::loadNewSession(const Session& newSession)
	{
		sessions.pushBack(newSession);
	}
*/
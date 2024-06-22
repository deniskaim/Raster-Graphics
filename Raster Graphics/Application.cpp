#include "Application.h"
#include "CommandFactory.h" // necessary for the run function 
#include "ImageFactory.h"

Application& Application::getInstance()
{
	static Application instance;
	return instance;
}
void Application::run()
{
	while (runApp)
	{
		try
		{
			Polymorphic_ptr<Command> currentCommand(CommandFactory::createCommand()); // use the already allocated memory
			currentCommand->execute();
		}
		catch (const std::logic_error& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
/*
void Application::loadSession(const Session& newSession)
{
	sessions.pushBack(newSession);
}
void Application::loadSession(Session&& newSession)
{
	sessions.pushBack(std::move(newSession));
}*/
void Application::loadSession(const MyVector<MyString>& imagesNames)
{
	Session newSession;
	newSession.initializeID();
	sessions.pushBack(newSession);
	switchSession(newSession.getID()); // shouldn't throw an exception

	for (size_t i = 0; i < imagesNames.getSize(); i++)
	{
		addImageToCurrentSession(imagesNames[i]);
	}
}
void Application::save()
{
	checkForActiveSession();
	Session& activeSession = getActiveSession();
	activeSession.save();
	close();
}
void Application::saveAs(const MyString& fileName)
{
	checkForActiveSession();
	Session& activeSession = getActiveSession();
	activeSession.saveAs(fileName);
	close();
}
void Application::close()
{
	// important to check in the other functions if the index is valid
	size_t indexCurrentSession = findSessionIndexByID(currentSessionID);
	sessions.popAt(indexCurrentSession);
	currentSessionID = -1;
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
	runApp = false;
}
void Application::switchSession(size_t newSessionIndex) const
{
	for (size_t i = 0; i < sessions.getSize(); i++)
	{
		if (sessions[i].getID() == newSessionIndex)
		{
			currentSessionID = newSessionIndex;
			return;
		}
	}

	throw std::out_of_range("Invalid session index!");
}
void Application::getCurrentSessionInfo() const
{
	checkForActiveSession();
	const Session& activeSession = getActiveSession();
	activeSession.printInfo();
}
//void Application::addImageToCurrentSession(const Polymorphic_ptr<TransformableImage>& image)
//{
//	checkForActiveSession();
//	sessions[currentSessionIndex].addImage(image);
//}
//void Application::addImageToCurrentSession(Polymorphic_ptr<TransformableImage>&& image)
//{
//	checkForActiveSession();
//	sessions[currentSessionIndex].addImage(std::move(image));
//}
void Application::addImageToCurrentSession(const MyString& imageName)
{
	checkForActiveSession();
	Session& activeSession = getActiveSession();
	activeSession.addImage(imageName);
}
void Application::undo()
{
	checkForActiveSession();
	Session& activeSession = getActiveSession();
	activeSession.undo();
}
void Application::addTransformation(const Polymorphic_ptr<Transformation>& transformation) // should be Transformation*
{
	checkForActiveSession();
	Session& activeSession = getActiveSession();
	activeSession.addTransformation(transformation);
}
void Application::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	checkForActiveSession();
	Session& activeSession = getActiveSession();
	activeSession.addTransformation(std::move(transformation));
}

bool Application::checkForActiveSession() const
{
	if (currentSessionID == -1)
		throw std::logic_error("No current session");
}
Session& Application::getActiveSession()
{
	for (size_t i = 0; i < sessions.getSize(); i++)
	{
		if (sessions[i].getID() == currentSessionID)
			return sessions[i];
	}
	throw std::exception("There is no session with this ID!");
}
const Session& Application::getActiveSession() const
{
	for (size_t i = 0; i < sessions.getSize(); i++)
	{
		if (sessions[i].getID() == currentSessionID)
			return sessions[i];
	}
	throw std::exception("There is no session with this ID!");
}
size_t Application::findSessionIndexByID(size_t ID) const
{
	for (size_t i = 0; i < sessions.getSize(); i++)
	{
		if (sessions[i].getID() == ID)
			return i;
	}
	throw std::exception("There is no session with this ID!");
}
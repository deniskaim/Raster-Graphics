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
	switchSession(newSession.getID()); // shouldn't throw an exception
	for (size_t i = 0; i < imagesNames.getSize(); i++)
	{
		addImageToCurrentSession(imagesNames[i]);
	}
}
void Application::save()
{
	checkForActiveSession();
	sessions[currentSessionIndex].save();
}
void Application::saveAs(const MyString& fileName)
{
	checkForActiveSession();
	sessions[currentSessionIndex].saveAs(fileName);
}
void Application::close()
{
	// important to check in the other functions if the index is valid
	sessions.popAt(currentSessionIndex - 1);
	currentSessionIndex = -1;
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
	if (newSessionIndex > sessions.getSize())
		throw std::out_of_range("Invalid session index!");

	currentSessionIndex = newSessionIndex;
}
void Application::getCurrentSessionInfo() const
{
	checkForActiveSession();
	sessions[currentSessionIndex].printInfo();
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
	checkForActiveSession();/*
	Polymorphic_ptr<TransformableImage> image(imageFactory(fileName));
	addImageToCurrentSession(std::move(image));*/
	sessions[currentSessionIndex].addImage(imageName);
}
void Application::undo()
{
	checkForActiveSession();
	sessions[currentSessionIndex].undo();
}
void Application::addTransformation(const Polymorphic_ptr<Transformation>& transformation) // should be Transformation*
{
	checkForActiveSession();
	sessions[currentSessionIndex].addTransformation(transformation);
}
void Application::addTransformation(Polymorphic_ptr<Transformation>&& transformation)
{
	checkForActiveSession();
	sessions[currentSessionIndex].addTransformation(std::move(transformation));
}

bool Application::checkForActiveSession() const
{
	if (currentSessionIndex == -1)
		throw std::logic_error("No current session");
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
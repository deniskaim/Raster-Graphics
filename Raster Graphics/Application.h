#pragma once
#include "Session.h"
#include "Command.h" // necessary for the commands
#include "MyVector.hpp"

class Application
{
public:
	// void executeCommand(const Command* command); // not const since the command will change the application class
	
	static Application& getInstance();
	Application(const Application& other) = delete;
	Application& operator=(const Application& other) = delete;

	void run();

	// void loadSession(const Session& newSession);
	// void loadSession(Session&& newSession);
	void loadSession(const MyVector<MyString>& imagesNames);
	void save(); // images in current session
	void saveAs(const MyString& fileName); // images in current session

	void close();
	void help();
	void exit();

	void getCurrentSessionInfo() const;
	void switchSession(size_t sessionIndex) const;
	//void collage(Direction idk, Image* first, Image* second); //?

	void addImageToCurrentSession(const Polymorphic_ptr<TransformableImage>& image); // for convenience
	void addImageToCurrentSession(Polymorphic_ptr<TransformableImage>&& image); // for convenience
	void addImageToCurrentSession(const MyString& fileName);

	void undo(); // 1
	void addTransformation(const Polymorphic_ptr<Transformation>& transformation); // transformation nasledqva komanda ()()()()()
	void addTransformation(Polymorphic_ptr<Transformation>&& transformation);


private:
	Application() = default;
	MyVector<Session> sessions;
	mutable size_t currentSessionID = -1;
	bool runApp = true;

	Session& getActiveSession();
	const Session& getActiveSession() const;
		
	bool checkForActiveSession() const;
	size_t findSessionIndexByID(size_t ID) const;
	/*
	void loadSession(const Image* const* images, size_t count);
	void save(); // images in current session
	void saveAs(const MyString& fileName); // images in current session

	void close();
	void help();
	void exit();

	void getCurrentSessionInfo() const;
	void switchSession(size_t sessionIndex) const;
	void collage(Direction idk, Image* first, Image* second); //?

	void addImageToCurrentSession(const Image* image);
	void undo();
	void addTransformation(Transformation transfortmation);
	*/
};
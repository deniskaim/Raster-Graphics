#pragma once
#include "Session.h"
#include "MyVector.hpp"

class Application
{
public:
	static Application& getInstance();
	Application(const Application& other) = delete;
	Application& operator=(const Application& other) = delete;

	void run();

	void loadSession(const MyVector<MyString>& imagesNames);
	void save(); // images in current session
	void saveAs(const MyString& fileName); // images in current session, fileName is the new name of the first image

	void close();
	void help();
	void exit();

	void getCurrentSessionInfo() const;
	void switchSession(size_t sessionIndex) const;
	void addCollageToCurrentSession(const MyString& direction, const MyString& imageOne, const MyString& imageTwo, const MyString& outimage); 

	void addImageToCurrentSession(const MyString& fileName);

	void undo(); 
	void addTransformation(const Polymorphic_ptr<Transformation>& transformation); 
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
	
};
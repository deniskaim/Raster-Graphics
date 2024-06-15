#pragma once
#include "ImageCollection.h"
#include "CommandExecutor.h"
#include "MyString.h"

class Session
{
public:

	// friend class Application;

	void addImage(const Image& image);
	void addImage(Image*& image);

	//void addCommand(const Command& command); // ?
	//void addCommand(Command*&& command); // ?

	void addTransformation(Transformation transformation);

	void save();
	void saveAs(const MyString& fileName); // only the first image under this name
	void close();
	void printInfo() const;

private:
	CommandExecutor commandsExecutor; //po-skoro TransformationExecutor ??????????
	ImageCollection imageCollection;
	size_t ID = 0;
	static size_t sessionsCount; // must initialize in cpp


};
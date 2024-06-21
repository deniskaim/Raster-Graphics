#include "AddImage.h"
#include "Application.h"

AddImage::AddImage(const MyString& imageName) : imageName(imageName)
{}
void AddImage::execute() const
{
	Application& application = Application::getInstance();
	application.addImageToCurrentSession(imageName);
}
Command* AddImage::clone() const
{
	return new AddImage(*this);
}

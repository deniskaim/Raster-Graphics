#include "Collage.h"
#include "Application.h"

Collage::Collage(const MyString& direction, const MyString& image1, const MyString& image2, const MyString& outimage)
	:direction(direction), image1(image1), image2(image2), outimage(outimage)
{}
void Collage::execute() const
{
	Application& application = Application::getInstance();
	application.addCollage(direction, image1, image2, outimage);
}
Command* Collage::clone() const
{
	return new Collage(*this);
}
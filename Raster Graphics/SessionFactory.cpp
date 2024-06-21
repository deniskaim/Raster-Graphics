#include "SessionFactory.h"
#include "ImageFactory.h"
#include "TransformableImage.h"
#include <sstream>
Session* createSession()
{
	const size_t BUFFSIZE = 1024;
	char buff[BUFFSIZE];
	std::cin.getline(buff, BUFFSIZE);
	std::stringstream ss(buff);

	Session* sessionPtr = new Session;

	while (!ss.eof())
	{
		MyString fileName;
		ss >> fileName;
		Polymorphic_ptr<TransformableImage> image = imageFactory(fileName);

		if (image.get())
		{
			sessionPtr->addImage(std::move(image));
			std::cout << "Image " << fileName << " added" << std::endl;
		}
		else
			std::cout << fileName << "not loaded" << std::endl;
	}
	return sessionPtr;
}

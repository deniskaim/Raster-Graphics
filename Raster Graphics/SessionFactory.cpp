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
		sessionPtr->addImage(imageFactory(fileName));
	}
	return sessionPtr;
}

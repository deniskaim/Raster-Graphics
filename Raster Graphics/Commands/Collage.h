#pragma once
#include "Command.h"
#include "MyString.h"

class Collage : public Command
{
public:
	Collage(const MyString& direction, const MyString& image1, const MyString& image2, const MyString& outimage);
	void execute() const override;
	Command* clone() const override;

private:
	MyString direction;
	MyString image1;
	MyString image2;
	MyString outimage;
};
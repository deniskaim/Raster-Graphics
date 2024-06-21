#pragma once
#include "Command.h"
#include "Polymorphic_ptr.h"
#include "TransformableImage.h"

class AddImage : public Command
{
public:
	AddImage(const MyString& imageName);

	void execute() const override;
	Command* clone() const override;

private:
	MyString imageName;
};
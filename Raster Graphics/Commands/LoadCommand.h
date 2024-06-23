#pragma once
#include "Command.h"
#include "MyVector.hpp"
#include "MyString.h"


class LoadCommand : public Command
{
public:
	LoadCommand(const MyVector<MyString>& imagesNames);
	void execute() const override;
	Command* clone() const override;

private:
	const MyVector<MyString> imagesNames;
};
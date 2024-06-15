#pragma once
#include "Command.h"

class SaveAsCommand : public Command
{
public:
	SaveAsCommand(const MyString& fileName);
	void execute(Application& application) const override;

private:
	const MyString fileName;
};
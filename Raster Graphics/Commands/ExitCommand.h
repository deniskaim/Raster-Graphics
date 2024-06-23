#pragma once
#include "Command.h"

class ExitCommand : public Command
{
public:
	void execute() const override;
	Command* clone() const override;
};
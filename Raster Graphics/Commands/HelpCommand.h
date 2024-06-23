#pragma once
#include "Command.h"
class HelpCommand : public Command
{
public:
	void execute() const override;
	Command* clone() const override;
};
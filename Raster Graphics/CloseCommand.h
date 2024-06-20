#pragma once
#include "Command.h"

class CloseCommand : public Command
{
public:
	void execute() const override;
	Command* clone() const override;
};
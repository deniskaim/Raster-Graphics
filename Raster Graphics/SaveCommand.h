#pragma once
#include "Command.h"

class SaveCommand : public Command
{
public:
	void execute() const override;
	Command* clone() const override;
};
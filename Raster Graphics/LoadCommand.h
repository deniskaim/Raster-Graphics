#pragma once
#include "Command.h"
class LoadCommand : public Command
{
public:
	void execute() const override;
	Command* clone() const override;
};
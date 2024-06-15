#pragma once
#include "Command.h"
class HelpCommand : public Command
{
public:
	void execute(Application&) const override;
};
#pragma once
#include "Command.h"

class SaveCommand : public Command
{
public:
	void execute(Application&) const override;
};
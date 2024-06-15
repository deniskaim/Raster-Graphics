#pragma once
#include "Command.h"

class CloseCommand : public Command
{
public:
	void execute(Application& application) const override;
};
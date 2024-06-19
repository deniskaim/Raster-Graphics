#pragma once
#include "Command.h"

class ExitCommand : public Command
{
public:
	void execute(Application& application) const override;

};
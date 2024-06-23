#pragma once
#include "Command.h"

class SessionInfo : public Command
{
public:
	void execute() const override;
	Command* clone() const override;
};
#pragma once
#include "Command.h"

class SwitchSession : public Command
{
public:
	SwitchSession(size_t sessionIndex);
	void execute() const override;
	Command* clone() const override;

private:
	size_t sessionIndex;
};
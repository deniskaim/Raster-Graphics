#pragma once
#include "Command.h"

class UndoCommand : public Command
{
public:
	void execute() const override;
	Command* clone() const override;
};
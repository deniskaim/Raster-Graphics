#pragma once
#include "Command.h"
class LoadCommand : public Command
{
public:
	void execute(Application& application) const override;

};
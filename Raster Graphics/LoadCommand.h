#pragma once
#include "Command.h"

class Session;
class LoadCommand : public Command
{
public:
	LoadCommand(Session* sessionPtr);
	LoadCommand(const LoadCommand& other);
	LoadCommand& operator=(const LoadCommand& other);
	LoadCommand(LoadCommand&& other) noexcept;
	LoadCommand& operator=(LoadCommand&& other) noexcept;
	~LoadCommand();

	void execute() const override;
	Command* clone() const override;

private:
	Session* sessionPtr = nullptr;

	void free();
	void copyFrom(const LoadCommand& other);
	void moveFrom(LoadCommand&& other);
};
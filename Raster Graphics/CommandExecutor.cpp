#include "CommandExecutor.h"

void CommandExecutor::add(Command* command)
{
	Polymorphic_ptr<Command>* obj = new Polymorphic_ptr<Command>(command); // wrap the command
	toExecute.push(std::move(*obj)); // add the command in the queue as an rvalue
}
void CommandExecutor::execute()
{
	if (toExecute.empty())
		return;

	Polymorphic_ptr<Command>& current = toExecute.peek();
	current->execute();

	executed.pushBack(std::move(current));
	toExecute.pop();
}
void CommandExecutor::executeAll()
{
	while (!toExecute.empty())
	{
		execute();
	}
}
void CommandExecutor::undo()
{
	if (executed.empty())
		return;

	Polymorphic_ptr<Command>& command = executed.peek();
	command->undo();
	executed.popBack();

}

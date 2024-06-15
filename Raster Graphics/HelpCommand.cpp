#include "HelpCommand.h"

void HelpCommand::execute(Application& application) const
{
    application.help();
}

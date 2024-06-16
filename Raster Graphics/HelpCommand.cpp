#include "HelpCommand.h"
#include "Application.h"

void HelpCommand::execute(Application& application) const
{
    application.help();
}

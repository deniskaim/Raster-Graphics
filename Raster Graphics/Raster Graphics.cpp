
#include <iostream>
#include "Application.h"

int main()
{
    Application& application = Application::getInstance();
    application.run();
}

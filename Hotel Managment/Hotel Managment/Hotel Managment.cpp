#include <iostream>
#include "Manager.h"
#include "UserInterfaceCLI.h"
#define HOTEL_NAME "Hotel California"

int main()
{
    std::cout << "================================================================" << std::endl;
    std::cout << "                 Welcome to " << HOTEL_NAME << " Managment CLI" << std::endl;
    std::cout << "================================================================" << std::endl;

    UserInterface::ChoiceSelector();
}

// I hate my life
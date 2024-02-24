#include "UserInterfaceCLI.h"

std::string UserInterface::Temp_input(const std::string text_to_print)
{
    std::string temp;
    std::cout << text_to_print;
    std::cin >> temp;
    return temp;
}

int UserInterface::ChoiceSelector()
{
    std::string username;
    short choice = 999;

    std::unique_ptr<Manager> manager_handler;
    std::cout << "Enter Manager name: ";
    std::cin >> username;
    manager_handler = std::make_unique<Manager>(username.c_str());


    while (choice != MenuOptions::EXIT_SYSTEM)
    {
        std::cout << std::endl;
        Print_MainMenu();
        std::cout << "Enter Choice: ";
        std::cin >> choice;
        
        try
        {

            switch (choice)
            {
            case MenuOptions::BOOK_ROOM:
                manager_handler->Book_a_room(std::stoi(Temp_input("Enter Room Number: ")),
                    Temp_input("Enter Customer Name: "),
                    std::stoi(Temp_input("Enter Days to book: ")));
                break;

            case MenuOptions::REMOVE_ROOM_BOOK:
                manager_handler->Remove_a_room(std::stoi(Temp_input("Enter Room Number To remove: ")));
                break;

            case MenuOptions::SHOW_ROOM_LIST:
                manager_handler->Print_all_booked_rooms();
                break;

            case MenuOptions::GET_ROOM_INFORMATION:
                std::cout << manager_handler->GetRoomInformation_Formated(std::stoi(Temp_input("Enter Room Number: "))) << std::endl;
                break;

            case MenuOptions::EXIT_SYSTEM:
                std::cout << "Exiting...";
                break;

            case MenuOptions::EXPORT_BOOK:
                manager_handler->Export_To_File();
                break;

            case MenuOptions::IMPORT_BOOK:
                manager_handler->Import_From_File();
                break;

            default:
                std::cout << "Unknown input" << std::endl;
                break;
            }
        }
        catch (std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Unknown error" << std::endl;
        }
    }
    return 0;
}

void UserInterface::Print_MainMenu()
{
    std::cout << MenuOptions::BOOK_ROOM << " - Book new room" << std::endl
        << MenuOptions::SHOW_ROOM_LIST << " - Show Book List" << std::endl
        << MenuOptions::REMOVE_ROOM_BOOK << " - Remove Room from list" << std::endl
        << MenuOptions::GET_ROOM_INFORMATION << " - Get Room information" << std::endl
        << MenuOptions::EXPORT_BOOK << " - Export book to file" << std::endl
        << MenuOptions::IMPORT_BOOK << " - Import book to file" << std::endl
        // Add new options here
        << MenuOptions::EXIT_SYSTEM << " - Exit" << std::endl;
}

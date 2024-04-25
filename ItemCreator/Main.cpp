// TEST!

#include <iostream>
#include "Item.hpp"
#include "Color.hpp"

int main(int argn, char* argv[])
{
    Item tester("Iron");
    std::cout
        << "=====================================" << std::endl
        << "Item: " << tester.Get_id() << std::endl
        << "Durability: " << tester.GetDurabilty() << std::endl
        << "Quality: "<< (int)tester << std::endl
        << "Color: " << (std::string)tester.GetItemColor() << std::endl
        << "=====================================" << std::endl;

    tester = Item("Wood");
    std::cout
        << "=====================================" << std::endl
        << "Item: " << tester.Get_id() << std::endl
        << "Durability: " << tester.GetDurabilty() << std::endl
        << "Quality: "<< (int)tester << std::endl
        << "Color: " << (std::string)tester.GetItemColor() << std::endl
        << "=====================================" << std::endl;

    tester = Item("Copper");
    std::cout 
        << "=====================================" << std::endl
        << "Item: " << tester.Get_id() << std::endl
        << "Durability: " << tester.GetDurabilty() << std::endl
        << "Quality: "<< (int)tester << std::endl
        << "Color: " << (std::string)tester.GetItemColor() << std::endl
        << "=====================================" << std::endl;

    tester = Item("Diamond");
    std::cout 
        << "=====================================" << std::endl
        << "Item: " << tester.Get_id() << std::endl
        << "Durability: " << tester.GetDurabilty() << std::endl
        << "Quality: "<< (int)tester << std::endl
        << "Color: " << (std::string)tester.GetItemColor() << std::endl
        << "=====================================" << std::endl;

        
}
#pragma once

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

#include "Color.hpp"
#include "Items_dictonary.hpp"

class Item
{
protected:
    Item_Stats stats;

public:
    Item(std::string item_id, hex_color item_color);
    Item (std::string item_id);

    std::string Get_id() { return stats.item_id; }
    hex_color GetItemColor() { return stats.item_color; }
    operator int() { return stats.quality; }
    uint16_t GetDurabilty() { return stats.durabilty; }
};
#endif
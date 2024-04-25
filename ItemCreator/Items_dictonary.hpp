#pragma once

#ifndef ITEM_DICTONARY_HPP
#define ITEM_DICTONARY_HPP

#include <map>
#include <iostream>
#include <string>
#include "Color.hpp"

typedef struct Item_Stats
{
    Item_Stats(std::string id, uint8_t str, uint16_t qul, hex_color color, bool is_material) : item_color(color), item_id(id)
    {
        this->strength = str;
        this->quality = qul;
        this->is_material = is_material;
    }

    std::string item_id;

    uint8_t strength = 1;
    uint16_t quality = 100;
    uint16_t durabilty = 255; // 255 is max durabilty

    hex_color item_color;
    bool is_material = false;
} Item_Stats;

namespace items_dict
{
    const std::map<std::string, Item_Stats> item_dict =
        {
            {"Iron", Item_Stats("Iron", 4, 15, hex_color(10, 3, 12), true)},
            {"Copper", Item_Stats("Copper", 2, 13, hex_color(105, 113, 120), true)},
            {"Wood", Item_Stats("Wood", 3, 10, hex_color(138, 86, 32), true)},
            {"Diamond", Item_Stats("Diamond", 8, 110, hex_color(213, 219, 224), true)}

        };
}

#endif
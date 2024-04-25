#include "Item.hpp"

Item::Item(std::string item_id, hex_color item_color) : stats(items_dict::item_dict.find(item_id)->second)
{
    this->stats.item_color = item_color;
}

Item::Item(std::string item_id) : stats(items_dict::item_dict.find(item_id)->second)
{
}

#include "TetraLine.h"

std::vector<std::pair<uint8_t, uint8_t>> TetraLine::Get_Next_Rotate()
{
    return std::vector<std::pair<uint8_t, uint8_t>>();
}

void TetraLine::rotate()
{
}

std::vector<std::pair<uint8_t, uint8_t>> TetraLine::Get_current_Shape()
{
    return this->rotations[this->current_Shape_state];
}

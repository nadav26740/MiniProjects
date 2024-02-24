#include "TetraLine.h"

std::vector<std::pair<uint8_t, uint8_t>> TetraLine::Get_Next_Rotate()
{
    return this->rotations[(this->current_Shape_state + 1) % this->rotations.size()];
}

void TetraLine::rotate()
{
    this->current_Shape_state = (this->current_Shape_state + 1) % this->rotations.size();
}

std::vector<std::pair<uint8_t, uint8_t>> TetraLine::Get_current_Shape()
{
    return this->rotations[this->current_Shape_state];
}

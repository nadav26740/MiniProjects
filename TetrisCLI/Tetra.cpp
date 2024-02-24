#include "Tetra.h"

std::vector<std::pair<uint8_t, uint8_t>> Tetra::Get_Next_Rotate()
{
    return this->rotations[(this->current_Shape_state + 1) % this->rotations.size()];
}

void Tetra::rotate()
{
    this->current_Shape_state = (this->current_Shape_state + 1) % this->rotations.size();
}

std::vector<std::pair<uint8_t, uint8_t>> Tetra::Get_current_Shape()
{
	return this->rotations[this->current_Shape_state];
}

#pragma once
#include "Tetra.h"
class TetraLine :
    public Tetra
{
private:
	char current_Shape_state = 0;
	const std::vector<std::vector<std::pair<uint8_t, uint8_t>>> rotations = { {{0,0}, {0,1}, {0,2}, {0,3}},
																				{{0,0}, {1,0},{2,0},{3,0}} };

public:
	virtual std::vector<std::pair<uint8_t, uint8_t>> Get_Next_Rotate();
	virtual void rotate();
	virtual std::vector<std::pair<uint8_t, uint8_t>> Get_current_Shape();
};


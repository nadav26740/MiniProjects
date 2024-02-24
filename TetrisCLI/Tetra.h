#pragma once
#include <iostream>
#include <vector>


class Tetra
{
protected:
	char current_Shape_state = 0;
	std::vector<std::vector<std::pair<uint8_t, uint8_t>>> rotations;

public:
	virtual std::vector<std::pair<uint8_t, uint8_t>> Get_Next_Rotate();
	virtual void rotate();
	virtual std::vector<std::pair<uint8_t, uint8_t>> Get_current_Shape();
};


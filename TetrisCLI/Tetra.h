#pragma once
#include <iostream>
#include <vector>


class Tetra
{
public:
	virtual std::vector<std::pair<uint8_t, uint8_t>> Get_Next_Rotate() = 0;
	virtual void rotate() = 0;
	virtual std::vector<std::pair<uint8_t, uint8_t>> Get_current_Shape() = 0;
};


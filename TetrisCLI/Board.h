#pragma once
#include <iostream>
#include "RenderSystem.h"
#include "Tetra.h"

class Board
{
private:
	uint8_t m_matrix[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
	std::unique_ptr<Tetra> m_current_block_handler;
	std::unique_ptr<Tetra> m_next_block_handler;

public:
	void update();
	Board();
};


#pragma once
#include <iostream>
#include "RenderSystem.h"
#include "Tetra.h"
#include "TetraLine.h"

class Board
{
private:
	uint8_t m_matrix[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
	std::unique_ptr<Tetra> m_current_block_handler;
	std::unique_ptr<Tetra> m_next_block_handler;
	uint8_t current_cords[2];

	bool Next_Move_legal(uint8_t new_cords[2]);
	bool Next_Move_legal(std::vector<std::pair<uint8_t, uint8_t>> new_shape);
	void Create_new_Block();

public:
	/// Main game engine 
	void update();
	char* GetBoard();
	Board();
	
	// Controls
	void Move_Left();
	void Move_Right();
	void Rotate();

};


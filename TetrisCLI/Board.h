#pragma once
#include <iostream>
#include "RenderSystem.h"
#include "Tetra.h"
#include "TetraLine.h"
#include "TetraBlock.h"
#include "TetraL.h"

class Board
{
private:
	uint8_t m_matrix[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
	std::unique_ptr<Tetra> m_current_block_handler;
	std::unique_ptr<Tetra> m_next_block_handler;
	uint8_t current_cords[2];

	/// <summary>
	/// Checking if the next move is possible
	/// </summary>
	/// <param name="new_cords">Getting the new cords of after the move</param>
	/// <returns>If it possible or not</returns>
	bool Next_Move_legal(uint8_t new_cords[2]);

	/// <summary>
	/// Checking if the next move is possible
	/// </summary>
	/// <param name="new_cords">Getting the new cords of after the move</param>
	/// <returns>If it possible or not</returns>
	bool Next_Move_legal(std::vector<std::pair<uint8_t, uint8_t>> new_shape);
	
	/// <summary>
	/// Creating a new blockk into the m_current_block_handler
	/// </summary>
	void Create_new_Block();

	void CheckForComplatedLines();

	uint32_t Score = 0;

public:
	/// Main game engine 
	void update();

	/// <summary>
	/// Creating a matrix that represent the board with the current block on it
	/// </summary>
	/// <returns>matrix ready to get rendered</returns>
	char* GetBoard();
	uint32_t Get_score();
	Board();
	
	// Controls
	/// Checking if possible to move/rotate and if possible doing it
	void Move_Left();
	void Move_Right();
	void Rotate();

};


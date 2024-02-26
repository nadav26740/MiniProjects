#pragma once
#include <iostream>
#include <string>

#define BOARD_BORDER_SIDES '|'
#define BOARD_BORDER_GROUND "==="
#define BLOCK_SYMBOL		"[ ]"
#define EMPTY_PLACE			". ."
#define UNKNOWN_SYMBOL		"###"

#define BOARD_MAX_HEIGHT 24
#define BOARD_MAX_WIDTH 12

#define WINDOW_HEIGHT
#define WINDOW_WIDTH

namespace RenderSystem
{
	enum PLACES_DEFINER
	{
		EMPTY,
		CATCHED_PLACE,
		CATCHED_PLACE_YEL,
		CATCHED_PLACE_RED,
		CATCHED_PLACE_BLUE,
		CATCHED_PLACE_GRN,
		CATCHED_PLACE_PUR
	};

	/// <summary>
	/// Getting matrix and rendering the board by it
	/// </summary>
	/// <param name="metrix">Getting board repressented by defines PLACES_DEFINER</param>
	void Render_By_Metrix(uint8_t* metrix);

	std::string Matrix_To_String(uint8_t* matrix);
	void Render_System2(uint8_t* matrix, int Score);
};


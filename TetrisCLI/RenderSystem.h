#pragma once
#include <iostream>
#include <string>

#define BOARD_BORDER_SIDES '|'
#define BOARD_BORDER_GROUND "==="
#define BLOCK_SYMBOL		"[ ]"
#define EMPTY_PLACE			". ."
#define UNKNOWN_SYMBOL		"###"

#define BOARD_MAX_HEIGHT 16
#define BOARD_MAX_WIDTH 8

#define WINDOW_HEIGHT
#define WINDOW_WIDTH

namespace RenderSystem
{
	enum PLACES_DEFINER
	{
		EMPTY,
		CATCHED_PLACE 
	};

	/// <summary>
	/// Getting matrix and rendering the board by it
	/// </summary>
	/// <param name="metrix">Getting board repressented by defines PLACES_DEFINER</param>
	void Render_By_Metrix(uint8_t *metrix);
};


#include "RenderSystem.h"

void RenderSystem::Render_By_Metrix(uint8_t *metrix)
{
	for (int i = 0; i < BOARD_MAX_HEIGHT; i++)
	{
		std::cout << "|";
		for (int j = 0; j < BOARD_MAX_WIDTH; j++)
		{
			switch (metrix[(i * BOARD_MAX_WIDTH) + j])
			{
			case PLACES_DEFINER::CATCHED_PLACE:
				std::cout << BLOCK_SYMBOL;
				break;

			case PLACES_DEFINER::EMPTY:
				std::cout << EMPTY_PLACE;
				break;

			default:
				std::cout << UNKNOWN_SYMBOL;
				break;
			}
		}
		std::cout << "|" << std::endl;
	}

	std::cout << "|";
	for (int i = 0; i < BOARD_MAX_WIDTH; i++)
	{
		std::cout << BOARD_BORDER_GROUND;
	}
	std::cout << "|" << std::endl;
}

std::string RenderSystem::Matrix_To_String(uint8_t* matrix)
{
	std::string output = "";
	for (int i = 0; i < BOARD_MAX_HEIGHT; i++)
	{
		output += "|";
		for (int j = 0; j < BOARD_MAX_WIDTH; j++)
		{
			switch (matrix[(i * BOARD_MAX_WIDTH) + j])
			{
			case PLACES_DEFINER::CATCHED_PLACE:
				 output += BLOCK_SYMBOL;
				break;

			case PLACES_DEFINER::EMPTY:
				output += EMPTY_PLACE;
				break;

			default:
				output += UNKNOWN_SYMBOL;
				break;
			}
		}
		output += "|\n";
	}

	output += "|\n";
	for (int i = 0; i < BOARD_MAX_WIDTH; i++)
	{
		output += BOARD_BORDER_GROUND;
	}
	output += "|\n";
	return output;
}

void RenderSystem::Render_System2(uint8_t* matrix, int Score)
{
	// TODO:::
}


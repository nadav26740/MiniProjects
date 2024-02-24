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

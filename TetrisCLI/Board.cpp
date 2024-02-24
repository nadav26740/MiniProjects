#include "Board.h"

Board::Board()
{
    for (int i = 0; i < BOARD_MAX_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_MAX_WIDTH; j++)
        {
            this->m_matrix[i][j] = RenderSystem::PLACES_DEFINER::EMPTY;
        }
    }

}

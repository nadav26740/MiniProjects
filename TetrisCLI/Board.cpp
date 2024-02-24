#include "Board.h"

bool Board::Next_Move_legal(uint8_t new_cords[2])
{
    std::vector<std::pair<uint8_t, uint8_t>> tetrashape = m_current_block_handler->Get_current_Shape();

    for (int i = 0; i < 4; i++)
    {
        if (tetrashape[i].first + new_cords[0] >= BOARD_MAX_HEIGHT || tetrashape[i].first + new_cords[0] < 0
            || tetrashape[i].second + new_cords[1] >= BOARD_MAX_WIDTH || tetrashape[i].second + new_cords[1] < 0)
            return false;
        if (this->m_matrix[tetrashape[i].first + new_cords[0]][tetrashape[i].second + new_cords[1]] 
            == RenderSystem::PLACES_DEFINER::CATCHED_PLACE)
            return false;
    }
    return true;
}

bool Board::Next_Move_legal(std::vector<std::pair<uint8_t, uint8_t>> new_shape)
{
    for (int i = 0; i < 4; i++)
    {
        if (new_shape[i].first + this->current_cords[0] >= BOARD_MAX_HEIGHT || new_shape[i].first + this->current_cords[0] < 0
            || new_shape[i].second + this->current_cords[1] >= BOARD_MAX_WIDTH || new_shape[i].second + this->current_cords[1] < 0)
            return false;
        if (this->m_matrix[new_shape[i].first + this->current_cords[0]][new_shape[i].second + this->current_cords[1]]
            == RenderSystem::PLACES_DEFINER::CATCHED_PLACE)
            return false;
    }

    return true;
}

void Board::Create_new_Block()
{
    this->m_current_block_handler = std::make_unique<TetraLine>();
    current_cords[1] = BOARD_MAX_WIDTH / 2;
    current_cords[0] = 0;
}

void Board::CheckForComplatedLines()
{
    int Complated_Lines_in_row = 0;
    int j = 0;
    for (int i = 0; i < BOARD_MAX_HEIGHT; i++)
    {
        // checking if part of the line empty
        for (j = 0; j < BOARD_MAX_WIDTH; j++)
        {
            if (this->m_matrix[i][j] == RenderSystem::PLACES_DEFINER::EMPTY)
                break;
        }

        // if complated line has found
        if (j == BOARD_MAX_WIDTH)
        {
            // TODO: optimize

            // remvoing the line
            for (j = 0; j < BOARD_MAX_WIDTH; j++)
            {
                this->m_matrix[i][j] = RenderSystem::PLACES_DEFINER::EMPTY;
            }

            // getting all the lines above one down
            for (j = 0; j < BOARD_MAX_WIDTH; j++)
            {
                for (int x = i; x > 0; x--)
                {
                    this->m_matrix[x][j] = this->m_matrix[x - 1][j];
                }
            }

            // checking the new line
            Complated_Lines_in_row *= 1.25;
            Complated_Lines_in_row += 100;
            i--;
        }
    }
    this->Score += Complated_Lines_in_row;
}

void Board::update()
{
    uint8_t new_cords[2];
    new_cords[1] = current_cords[1];
    new_cords[0] = current_cords[0] + 1;

    if (Next_Move_legal(new_cords))
    {
        current_cords[0] += 1;
    }
    else
    {
        std::vector<std::pair<uint8_t, uint8_t>> tetrashape = m_current_block_handler->Get_current_Shape();

        for (int i = 0; i < 4; i++)
        {
            this->m_matrix[tetrashape[i].first + current_cords[0]][tetrashape[i].second + current_cords[1]] = RenderSystem::PLACES_DEFINER::CATCHED_PLACE;
        }
        Create_new_Block();
        CheckForComplatedLines();
    }
}

char* Board::GetBoard()
{
    static char rendered_matrix[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
    std::memcpy(rendered_matrix, this->m_matrix, (BOARD_MAX_WIDTH * BOARD_MAX_HEIGHT));

    std::vector<std::pair<uint8_t, uint8_t>> tetrashape = m_current_block_handler->Get_current_Shape();

    for (int i = 0; i < 4; i++)
    {
        rendered_matrix[tetrashape[i].first + current_cords[0]][tetrashape[i].second + current_cords[1]] = RenderSystem::PLACES_DEFINER::CATCHED_PLACE;
    }
    return (char*)rendered_matrix;
}

uint32_t Board::Get_score()
{
    return this->Score;
}

Board::Board()
{
    Create_new_Block();
    for (int i = 0; i < BOARD_MAX_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_MAX_WIDTH; j++)
        {
            this->m_matrix[i][j] = RenderSystem::PLACES_DEFINER::EMPTY;
        }
    }

}

void Board::Move_Left()
{
    uint8_t new_cords[2];
    new_cords[0] = current_cords[0];    
    new_cords[1] = current_cords[1] - 1;
    if (Next_Move_legal(new_cords))
        current_cords[1] -= 1;
}

void Board::Move_Right()
{
    uint8_t new_cords[2];
    new_cords[0] = current_cords[0];
    new_cords[1] = current_cords[1] + 1;
    if (Next_Move_legal(new_cords))
    current_cords[1] += 1;
}

void Board::Rotate()
{
    if (Next_Move_legal(m_current_block_handler->Get_Next_Rotate()))
    {
        m_current_block_handler->rotate();
    }
}

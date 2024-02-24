// TetrisCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "RenderSystem.h"

int main()
{
    char keyboard_input_buffer;
    uint8_t matrix[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
    for (int i = 0; i < BOARD_MAX_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_MAX_WIDTH; j++)
        {
            matrix[i][j] = RenderSystem::PLACES_DEFINER::EMPTY;
        }
    }
    
    RenderSystem::Render_By_Metrix(matrix);
    
    // getting keyboard input
    while (true)
    {
        keyboard_input_buffer = _getch();
        if (keyboard_input_buffer <= 0)
            keyboard_input_buffer = _getch();

        std::cout << (int)keyboard_input_buffer << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
    
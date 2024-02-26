// TetrisCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <conio.h>
#include <mutex>
#include "RenderSystem.h"
#include "Board.h"
#include "ticker.hpp"

#define ESCAPE_BUTTON 27
#define LFET_ARROW 75
#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77

#define START_TIME_PER_FRAME 600
#define PRIME_DIFFICULTY_DEFINER 1000

Board game_Board;
std::mutex Render_locker;

void main_update(DEFAULT_TIME_TYPE_TICKER delta_time);
void Render_Screen();
Ticker main_ticker(std::chrono::milliseconds(START_TIME_PER_FRAME));

bool GameRunning;

int main()
{

    system("color a");
    char keyboard_input_buffer = NULL;
    uint8_t matrix[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
 
    GameRunning = true;
    for (int i = 0; i < BOARD_MAX_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_MAX_WIDTH; j++)
        {
            matrix[i][j] = RenderSystem::PLACES_DEFINER::EMPTY;
        }
    }
    
    main_ticker.AddFunction(&main_update);
    main_ticker.Start();
    
    // getting keyboard input
    while (keyboard_input_buffer != ESCAPE_BUTTON && GameRunning)
    {
        keyboard_input_buffer = _getch();
        if (keyboard_input_buffer <= 0)
            keyboard_input_buffer = _getch();

        //std::cout << (int)keyboard_input_buffer << std::endl;
        switch (keyboard_input_buffer)
        {
        case (LFET_ARROW):
            game_Board.Move_Left();
            break;

        case (RIGHT_ARROW):
            game_Board.Move_Right();
            break;

        case(UP_ARROW):
            game_Board.Rotate();
            break;

        case (DOWN_ARROW):
            game_Board.SuperFall();
            break;

        default:
            continue;
        }
        Render_Screen();
        //std::cout << "Key Pressed: " << keyboard_input_buffer << std::endl;
    }
    main_ticker.Stop();

}

void main_update(DEFAULT_TIME_TYPE_TICKER delta_time)
{
    try
    {
        game_Board.update();
        Render_Screen();

        if (game_Board.Check_If_lose())
        {
            main_ticker.async_stop();
            GameRunning = false;
            std::cout << "Game Over" << std::endl << "Score: " << game_Board.Get_score() << std::endl;
        }

    }
    catch (std::exception &e)
    {
        std::cerr << "Main Update Failure: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Failure in main update" << std::endl;
    }
}

void Render_Screen()
{
    Render_locker.lock();
    system("cls");
    RenderSystem::Render_By_Metrix((uint8_t*)game_Board.GetBoard());
    std::cout << "Score: " << game_Board.Get_score() << std::endl;

    // difficulty change by score
    main_ticker.SetInterval(std::chrono::milliseconds(START_TIME_PER_FRAME - ((600) / (1 + ((PRIME_DIFFICULTY_DEFINER) / (int)(sqrt(game_Board.Get_score() + 1) * 20))))));
    std::cout << "time per frame: " << main_ticker.GetInterval().count() << std::endl;
    Render_locker.unlock();
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
    
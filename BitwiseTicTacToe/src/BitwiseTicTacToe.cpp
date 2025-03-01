#include <iostream>
#include <cstdint>
#include "..\headers\BitwiseTicTacToe.h"
#include "..\headers\GUIConsole.h"

uint16_t PlayerX = 0;
uint16_t PlayerY = 0;

int main() 
{
    DisplayBoard(PlayerX,PlayerY);
    ShowMessage("Player X starts!");
    ShowMessage("Enter column,row (for example 3,4)");
    PlayerMove PM = GetInput();

    std::cout << PM.column << " " << PM.row << std::endl;

    char a;
    std::cin >> a;
    return 1;
}

// This file should handle all the game logic and winning conditions.
// Might have to split up more later.
// Maybe have one logic file?
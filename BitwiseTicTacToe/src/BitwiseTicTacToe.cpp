#include <iostream>
#include <cstdint>
#include "..\headers\BitwiseTicTacToe.h"

uint16_t PlayerX = 0;
uint16_t PlayerY = 0;
bool PlayerXMove = true;
int GameOver = 0;

int main()
{
    PlayerX = 0;
    PlayerY = 0;
    while (!GameOver)
    {
        DisplayBoard(PlayerX, PlayerY);
        if (PlayerXMove)
            ShowMessage("Player Xs turn!");
        else
            ShowMessage("Player Ys turn!");

        ShowMessage("Enter Position to change");
        int PM = GetInput();
        int ValidMove = 0;
        if (PM >= 0)
        {
            ValidMove = MakeMove(PlayerX, PlayerY, PlayerXMove, PM);
        }
        else
        {
            ValidMove = 0;
        }

        if (!ValidMove)
            ShowMessage("Player made wrong move!");
        else
            PlayerXMove = !PlayerXMove;

        if (CheckWinner(PlayerX) || CheckWinner(PlayerY))
        {
            DisplayBoard(PlayerX, PlayerY);
            if (PlayerXMove)
                ShowMessage("Game Over! Player Y won! \n do you want to play again? Y/N");
            else if (!PlayerXMove)
                ShowMessage("Game Over! Player X won! \n do you want to play again? Y/n");

            char answer;
            std::cin >> answer;
            PlayerX = 0;
            PlayerY = 0;

            GameOver = !(answer == 'y' || answer == 'Y');            
        }
        else if (GameNeedsReset(PlayerX, PlayerY))
            {
                ShowMessage("Gameboard full, resetting game now.");
                PlayerY = 0;
                PlayerX = 0;
            }

    }
    return 1;

}

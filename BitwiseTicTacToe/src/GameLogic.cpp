#include "../headers/GameLogic.h"
#include "stdint.h"
#include "..\headers\GameLogic.h"

int MakeMove(uint16_t &PlayerX, uint16_t &PlayerY, bool PlayerXMove, int PM)
{
    auto OccupiedSpace = [&](uint16_t PlayerX, uint16_t PlayerY, int PM) -> bool
    {
        return (PlayerX & (1 << PM)) || (PlayerY & (1 << PM));
    };
    if (PlayerXMove && !OccupiedSpace(PlayerY, PlayerX, PM))
    {
        PlayerX |= 1 << PM;
        return 1;
    }
    else if (!PlayerXMove && !OccupiedSpace(PlayerX, PlayerY, PM))
    {
        PlayerY |= 1 << PM;
        return 1;
    }

    return 0;
}

int CheckWinner(uint16_t Player)
{
    int win[] = WIN;
    for (int i : win)
    {
        if ((Player & i) == i)
            return 1;
    }

    return 0;
}

int GameNeedsReset(uint16_t &PlayerX, uint16_t &PlayerY)
{
    return ((PlayerX | PlayerY) == FULLBOARD);
}
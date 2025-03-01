#include "../headers/GameLogic.h"
#include "stdint.h"
#include "..\headers\GameLogic.h"


int MakeMove(uint16_t &PlayerX, uint16_t &PlayerY, bool PlayerXMove,int PM)
{
    auto OccupiedSpace = [&](uint16_t Player,int PM) -> int {   return (Player & (1 << PM)) ? 1 : 0;  };

    if(PlayerXMove && !OccupiedSpace(PlayerY,PM)){
        PlayerX |= 1 << PM;
        return 1;
    }
    else if(!PlayerXMove && !OccupiedSpace(PlayerX,PM))
    {
        PlayerY |= 1 << PM;
        return 1;
    }

    return 0;
}

/*
*   1 | 2 | 3
*   4 | 5 | 6
*   7 | 8 | 9
*
*   Winner row 1 0x000000111
*   Winner row 2 0b000111000
*   Winner row 3 0b111000000
*/
int CheckWinner(uint16_t &Player){
    int win[] = WIN;
    for (int i : win){
        if(Player = i)
            return 1;
    }
    return 0;
}

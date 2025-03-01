#include <cstdint>


#define WIN {0b000000111, 0b000111000, 0b111000000, 0b001001001, 0b010010010, 0b100100100, 0b100010001, 0b001010100 }

int MakeMove(uint16_t &PlayerX, uint16_t &PlayerY, bool PlayerXMove,int PM);
int CheckWinner(uint16_t &Player);

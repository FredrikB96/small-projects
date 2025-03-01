#include <string>
#include <cstdint>

struct PlayerMove{
    int row, column;
};


void ShowMessage(std::string msg);
void DisplayBoard(uint16_t PlayerX, uint16_t PlayerO);
PlayerMove GetInput();
int StringToIntSplit(std::string input, int Column, char delimeter);

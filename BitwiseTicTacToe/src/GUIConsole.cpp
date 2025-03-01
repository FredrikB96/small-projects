// This file should handle all display elements, showing the grid, texts, and such. ALL GUI.
#include <iostream>
#include <vector>
#include "..\headers\GUIConsole.h"
#include <cstdint>

void ShowMessage(std::string msg){
    std::cout << msg << std::endl;
}

void DisplayBoard(uint16_t PlayerX, uint16_t PlayerY) {
    for (int i = 0; i < 9; i++) {
        if (PlayerX & (1 << i))
            std::cout << "X ";
        else if (PlayerY & (1 << i))
            std::cout << "Y ";
        else
            std::cout << i+1 << " ";
        
        if ((i + 1) % 3 == 0) std::cout << std::endl;
        else
            std::cout << "| ";
    }
}

int GetInput()
{
    std::string input;
    std::cin >> input;
    auto number = [&](char a) -> int{   
        switch (a)
        {
        case '1': return 1; break;
        case '2': return 2; break;
        case '3': return 3; break;
        case '4': return 4; break;
        case '5': return 5; break;
        case '6': return 6; break;
        case '7': return 7; break;
        case '8': return 8; break;
        case '9': return 9; break;
        default: return -1; break;
        }};

    return number(input[0])-1;
}



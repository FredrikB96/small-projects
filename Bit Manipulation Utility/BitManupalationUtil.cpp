#include <iostream>
#include <vector>

int ConsoleManager(int input = 0);
int InputManager();
int IsNumber(std::string input);

std::vector<int> UserNumbers;


int main() {
    int mode = 0;

    do{
    switch (mode)
    {
    case 1:
        mode = AddDeleteNumbers();
        break;
    case 2:
        break;  
    case 3:
        break;
    case 8: // error in program
        break;
    default:
        ConsoleManager();
        mode = InputManager();
        break;
    }
    }while(mode != 4);
    return 1;
}

int AddDeleteNumbers(){
    int input;
    ConsoleManager(1);
    input = InputManager();
    
    if(UserNumbers.size() >input)
    {
        
    }

    UserNumbers.resize(input);

    return 0;
}

int ConsoleManager(int input){
    int numbers;
    switch (input)
    {
        case 1:
            std::cout << "How many numbers do you want to use: ";
            numbers = InputManager();
            return numbers;
            break;   
        default:
            std::cout << "Welcome to the Bit Manupalation Utillity! \nIt is an application to explore bitwise operators with the use of the command line!" << std::endl;
            std::cout << "\n\n1. Enter/change numbers to bitwise\n2.Performe bitwise operator\n3.Read up on bitwise operators.\n4.exit" << std::endl;
            break;
    }     
    return 1;
}


int IsNumber(std::string input){
    for(int i=0; i<input.length();i++){
        if(!isdigit(input[i]))
            return 0;
    }
    return 1;
}


int InputManager(){
    std::string a;
    std::cin >> a;
    if(IsNumber(a)){
        return std::stoi(a);
    }

    return 0;
}
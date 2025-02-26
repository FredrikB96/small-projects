#include <iostream>
#include <vector>
#include <bitset>
#include <stdint.h>

enum MenuOptions { INPUT_NUMBERS = 1, BITWISE_OPERATION, HELP, EXIT, ERROR = 8 };


int InputManager();
int IsNumber(std::string input);
int NumberModificationMode();
int AddNumbers(int NumberOfElements);
int GetIndex(int SearchNumber);
int DeleteNumbers(int NumberOfElements);
void PrintElements();
int BitWiseOperation();
void ApplyBitwiseOperation(int operation, int Steps, int UserNum);

std::vector<uint16_t> UserNumbers;

int main() {
    int mode = 0;

    std::cout << "Welcome to the Bit Manipulation Utillity! \nIt is an application to explore bitwise operators with the use of the command line!" << std::endl;
    std::cout << "\n\n1. Enter/change numbers to bitwise\n2.Perform bitwise operation\n3.Read up on bitwise operators.\n4.exit" << std::endl;
    do{
        mode = InputManager();

        switch (mode)
        {
        case INPUT_NUMBERS:
            mode = NumberModificationMode();
            break;
        case BITWISE_OPERATION:
            mode = BitWiseOperation();
            break;  
        case HELP:
            break;
        case EXIT:
            break;
        case ERROR: // error in program
            break;
        default:
             std::cout << mode <<" is not a valid chocice!" << std::endl;
            break;
        }
        if(mode < 0)
        {
            // Error!
        }

        PrintElements();
        std::cout << "\n1. Enter/change numbers to bitwise\n2.Performe bitwise operation\n3.Read up on bitwise operators.\n4.exit" << std::endl;


    }while(mode != 4);
    return 1;
}

int BitWiseOperation(){
    std::cout << "\nAvailable operations: 1.&   2.|   3.^   4.~   5.>>   6.<<\nWhat operation do you want to perform?" << std::endl;
    int UserChoice = InputManager();
    PrintElements();
    std::cout << "What number do you wish to modify?" << std::endl;
    int UserNum = InputManager();
    int index = GetIndex(UserNum);
    if(index = -1)
    {
        return -1;
    }
    switch (UserChoice)
    {
    case 1:        
    {
        std::cout << "what number do you want to performe the AND operator with: " << std::endl;
        int Steps = InputManager();
        (void)ApplyBitwiseOperation(UserChoice,Steps,UserNum);
        break;
    }
    break;
    case 2:
    {
        std::cout << "What number do you want to performe the OR operator with: " << std::endl;
        int Steps = InputManager();
        (void)ApplyBitwiseOperation(UserChoice,Steps,UserNum);
        break;
    }
    break;
    case 3:
    {
        std::cout << "What number do you want to performe the XOR operator with: " << std::endl;
        int Steps = InputManager();
        (void)ApplyBitwiseOperation(UserChoice,Steps,UserNum);
        break;
    }
    break;
    case 4:
    {
        (void)ApplyBitwiseOperation(UserChoice,0,UserNum);
    }    
        break;
    case 5:
    {
        std::cout << "Number of steps to the right is: " << std::endl;
        int Steps = InputManager();
        (void)ApplyBitwiseOperation(UserChoice,Steps,UserNum);
        break;
    }
    case 6:
    {
        std::cout << "Number of steps to the left is: " << std::endl;
        int Steps = InputManager();
        (void)ApplyBitwiseOperation(UserChoice,Steps,UserNum);
    }
        break;
    default:
        break;
    }
    return 1;
}

void ApplyBitwiseOperation(int operation, int Steps, int UserNum) {
    switch (operation) {
        case 1: UserNumbers[GetIndex(UserNum)] &= Steps; break;
        case 2: UserNumbers[GetIndex(UserNum)] |= Steps; break;
        case 3: UserNumbers[GetIndex(UserNum)] ^= Steps; break;
        case 4: UserNumbers[GetIndex(UserNum)] = ~UserNumbers[GetIndex(UserNum)]; break;
        case 5: UserNumbers[GetIndex(UserNum)] >>= Steps; break;
        case 6: UserNumbers[GetIndex(UserNum)] <<= Steps; break;
        default: break;
    }
}


int NumberModificationMode(){
    int input;
    if(UserNumbers.empty())
    {
        std::cout << "List is empty, how many numbers do you want to store? (You will have to assign a value later)" << std::endl;
        input = InputManager();
        return AddNumbers(input);
    }else
    {
        std::cout << "how many numbers do you want the new size to be?" << std::endl;
        input = InputManager();
        if(input < UserNumbers.size())
            return DeleteNumbers(input);
        else
            return AddNumbers(input);
    }

    return 0;
}

int DeleteNumbers(int NumberOfElements)
{
    (void)PrintElements();
    std::cout << "What number do you wish to remove?" << std::endl;
    int UserChoice = InputManager();
    UserNumbers.erase(UserNumbers.begin() + GetIndex(UserChoice));
    UserNumbers.shrink_to_fit();
    return 1;
}

int AddNumbers(int NumberOfElements)
{
    UserNumbers.resize(NumberOfElements);
    for(int i=0;i<UserNumbers.size();i++)
    {
        std::cout << "Enter number " << i+1 << " to use:";
        uint16_t NewNumber = InputManager();
        UserNumbers[i] = NewNumber;
    }

    if(UserNumbers.size() == NumberOfElements){
        std::cout << "Successfully added: " << UserNumbers.size() << std::endl;
        return 1;
    }
    else
        return 0;
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

    return -1;
}

int GetIndex(int SearchNumber){
        for(int i = 0; i< UserNumbers.size();i++)
        {
            if(UserNumbers[i] == SearchNumber)
                return i;
        }
        return -1;
}

void PrintElements(){
    std::cout << "\n Data: ";
    for(int i=0; i<UserNumbers.size();i++){
        std::bitset<16> bits = std::bitset<16>(UserNumbers[i]);

        std::cout << UserNumbers[i] << " " << bits << ", ";
    }
    std::cout << std::endl;
}
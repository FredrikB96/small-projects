#include <iostream>
#include <vector>

int InputManager();
int IsNumber(std::string input);
int NumberModifactionMode();
int AddNumbers(int NumberOfElements);
int GetIndex(int SearchNumber);
int DeleteNumbers(int NumberOfElements);
void PrintElements();


std::vector<int> UserNumbers = {11,12,15,22};

int main() {
    int mode = 0;

    std::cout << "Welcome to the Bit Manupalation Utillity! \nIt is an application to explore bitwise operators with the use of the command line!" << std::endl;
    std::cout << "\n\n1. Enter/change numbers to bitwise\n2.Performe bitwise operation\n3.Read up on bitwise operators.\n4.exit" << std::endl;
    do{
        mode = InputManager();

        switch (mode)
        {
        case 1:
            mode = NumberModifactionMode();
            break;
        case 2:
            break;  
        case 3:
            break;
        case 8: // error in program
            break;
        default:
            break;
        }
        if(mode = -1)
        {
            // Error!
        }

        PrintElements();
        std::cout << "\n1. Enter/change numbers to bitwise\n2.Performe bitwise operation\n3.Read up on bitwise operators.\n4.exit" << std::endl;


    }while(mode != 4);
    return 1;
}

int NumberModifactionMode(){
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
    UserNumbers.resize(NumberOfElements*2);
    for(int i=0;i<UserNumbers.size();i++)
    {
        std::cout << "Enter number " << i << " to use:";
        int NewNumber = InputManager();
        UserNumbers[i] = NewNumber; 
    }

    if(UserNumbers.size() == NumberOfElements){
        std::cout << "Succesully added: " << UserNumbers.size() << std::endl;
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

    return 0;
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
    std::cout << UserNumbers[i] << ", ";
    }
    std::cout << std::endl;
}
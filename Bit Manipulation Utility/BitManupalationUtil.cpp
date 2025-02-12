#include <iostream>

int ConsoleManager();
int InputManager();

int main() {
   ConsoleManager();
   InputManager();
    return 1;
}

int ConsoleManager(){
    std::cout << "Welcome to the Bit Manupalation Utillity! \nIt is an application to explore bitwise operators with the use of the command line!" << std::endl;
    std::cout << "\n\n1. Enter/change numbers to bitwise\n2.Performe bitwise operator\n3.Read up on bitwise operators.\n4.exit" << std::endl;

    
    return 1;
}

int InputManager(){
    std::string a;
    std::cin >> a;
    switch (a[0])
    {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    default:
        std::cout << a << "is not a valid input!" << std::endl;
        return -1;
        break;
    }

    return 1;
}
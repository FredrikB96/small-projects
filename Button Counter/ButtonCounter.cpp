#include <iostream>
std::string PrintOut(int RunTimes);
int main() {
	char Input;
	int RunTimes = 0;
	std::cout << "Welcome to this hello world run counter app" << std::endl;
	do{
	std::cout << "Press one of the following numbers to decide what happens next. \n" 
	<< "  	Press 1 to run the hello world counter once. \n"
	<< "	Press 2 to run the hello world counter for a set number of run times. \n"
	<< "	Press 3 to exit the program. \n"
	<< std::endl;	
	std::cin >> Input;
	switch(Input){
		case '1':
			std::cout << PrintOut(++RunTimes) << std::endl;
			break;
		case '2':
			int TimesToRun;
			std::cout << "How many times do you want to run: ";
			std::cin >> TimesToRun;
			for (int i=0;i<TimesToRun;i++){
				std::cout << PrintOut(++RunTimes) << std::endl;
			}
			break;
		case '3':
			std::cout << "Bye bye, You ran hello world " << RunTimes << " times. \n" << std::endl;
			break;
		default:
			std::cout << "Wrong key press." << std::endl;
	}
	

	}while(Input != '3');
}

std::string PrintOut(int RunTimes){
	std::string Msg = "Hello World has been run " + std::to_string(RunTimes)+ " times! \n";
	return Msg;
}
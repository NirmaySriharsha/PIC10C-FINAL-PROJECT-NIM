#include "Game.cpp"
#include <iostream>
#include <string>

int main(){
	int no_rows; int difficulty; std::string dummy; std::string answer = "Yes";
	while (*(answer.begin()) == 'Y' || *(answer.begin())== 'y')
	{
		system("CLS");
		std::cout<<"Welcome to the Game of Nim! \n";
		answer= "N0";
	}
	return 0;
}
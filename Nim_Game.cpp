#include "Game.cpp"
#include <iostream>
#include <string>

int main(){
	/*int no_rows; int difficulty; std::string dummy; std::string answer = "Yes";
	while (*(answer.begin()) == 'Y' || *(answer.begin())== 'y')
	{
		system("CLS");
		std::cout<<"Welcome to the Game of Nim! \n";
		answer= "N0";
	}*/


	Nim<'*'> game(4);
	game.print_game();
	auto CPU=game.generate();
	std::cout<<CPU.nim_sum()<<std::endl;
	return 0;
}
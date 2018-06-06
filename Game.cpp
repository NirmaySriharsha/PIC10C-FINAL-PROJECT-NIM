#include "Game.h"
#include <iostream>

Game::Game(int _no, char _token):no_rows(_no), token(_token){
	for(int i=0; i<no_rows; i++)
	{
		rows[i]= 2*i +1;
	}
}

void Game::print_game() const{
	for(int i=0; i<no_rows; i++)
	{
		for(int j=1; j<=rows[i]; j++)
			std::cout<<token<<"\t";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	return;
}


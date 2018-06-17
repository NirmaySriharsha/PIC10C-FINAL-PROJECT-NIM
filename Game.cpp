#include "Game.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

template<char token, int no_rows>
Game<token, no_rows>::Game():rows(new int[no_rows]){
	for(int i=0; i<no_rows; i++)
	{
		rows[i]= 2*i +1;
	}
}

template<char token, int no_rows>
void Game<token, no_rows>::print_game() const{
	std::for_each(rows, rows+ no_rows, 
		[&](const int& x){
			 for (int i=0; i<x; i++)
			 	std::cout<<token<<"\t";
			 std::cout<<std::endl;
			});
	std::cout<<std::endl;
	return;
}

template<char token, int no_rows>
Game<token, no_rows>::CPU_opponent::CPU_opponent(Game* _parent, int _difficulty):parent(_parent), difficulty(_difficulty){}


template<char token, int no_rows>
void Game<token, no_rows>::CPU_opponent::optimal_move() const{

	return;
}

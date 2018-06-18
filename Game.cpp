#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include "Game.h"

template<char token>
Nim<token>::Nim(int _no_rows): no_rows(_no_rows), game_layout(new int[_no_rows]){
	for(int i=0; i<no_rows; i++)	
		game_layout[i]=2*i+1;
}

template<char token>
Nim<token>::~Nim(){
	delete[] game_layout;
}

template<char token>
void Nim<token>::print_game() const{
	std::for_each(game_layout, game_layout+no_rows, 
		[&](const int& x){
			for(int i=0; i<x; i++)
				std::cout<<token<<"\t";
			std::cout<<std::endl;
		});
	std::cout<<std::endl;
	return;
}

template<char token>
Nim<token>::CPU_Opponent::CPU_Opponent(int _difficulty, Nim<token>* _parent):difficulty(_difficulty), parent(_parent){}

template<char token>
int Nim<token>::CPU_Opponent::nim_sum(int* game) const{
	class xor_add{
	public:
		int operator()(int sum, int x) const{
			return sum^x;
		}

	}xor_add;
	int x= std::accumulate(game, game+(parent->no_rows), 0, xor_add);
	return x;
}	


template<char token>
void Nim<token>::player_move(int row, int counters){
	if(game_layout[row-1]>=counters)
		game_layout[row-1]-=counters;
	else
		std::cout<<"Invalid Move. Please try again."<<std::endl;
	return;
}

template<char token>
void Nim<token>::CPU_Opponent::decide_move(){
	srand(time(NULL));
	int x=rand()%10;
	if(x<=difficulty)
		this->best_move();
	else
		this->random_move();
}

template<char token>
void Nim<token>::CPU_Opponent::best_move(){
	int* test_dummy=parent->game_layout;
	for (int i=0; i<parent->no_rows; i++)
	{
		for(int j=0; j<test_dummy[i]; j++)
		{
			test_dummy[i]=j;
			if(nim_sum(test_dummy)==0)
				parent->player_move(i+1,test_dummy[i]-j);
			else
				test_dummy=parent->game_layout;

		}
	}

}

template<char token>
void Nim<token>::CPU_Opponent::random_move(){
	int row=rand()%((parent->no_rows)+1);
	int counters=rand()%(parent->game_layout[row]);
	parent->player_move(row, counters);
	return;
}

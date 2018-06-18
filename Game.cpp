#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
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
int Nim<token>::CPU_Opponent::nim_sum() const{
	class xor_add{
	public:
		int operator()(int sum, int x) const{
			return sum^x;
		}

	}xor_add;
	int x= std::accumulate((parent->game_layout), (parent->game_layout)+(parent->no_rows), 0, xor_add);
	return x;
}	
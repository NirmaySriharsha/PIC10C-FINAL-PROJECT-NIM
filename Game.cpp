#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ctime>

template<char token>
Nim<token>::Nim(int _no_rows):no_rows(_no_rows){
	try{
		game_layout= new int[no_rows];
	}
	catch(std::exception &e){
		std::cerr<<"An exception occured \n";
		game_layout=nullptr;
	}
	for(int i=0; i<no_rows; i++)
		game_layout[i]=2*i + 1;
}

template<char token>
void Nim<token>::print_game() const{
	std::for_each(game_layout, game_layout+no_rows, 
		[&](const int& x){
			for(int i=1; i<=x; i++)
				std::cout<<token<<"\t";
			std::cout<<std::endl;
		});
	std::cout<<std::endl;
}

template<char token>
Nim<token>::~Nim(){
	delete[] game_layout;
}

template<char token>
Nim<token>::CPU_Opponent::CPU_Opponent(Nim<token>* _parent, int _difficulty):parent(_parent), difficulty(_difficulty){}

template<char token>
void Nim<token>::player_move(int row, int counters, bool user){
	if(game_layout[row-1]>=counters)
		game_layout[row-1]-=counters;
	else
		{
			std::cout<<"Invalid entry. Please try again"<<std::endl;
			this->user_move();
		}
	if(user)
		std::cout<<"The player removed "<<counters<<" counters from row "<<row<<std::endl;
	else
		std::cout<<"The CPU removed "<<counters<<" counters from row "<<row<<std::endl;
	return;
}

template<char token>
void Nim<token>::user_move(){
	std::cout<<"What row would you like to remove counters from? "<<std::endl;
	int row; std::cin>>row;
	std::cout<<"How many counters would you like to remove from row "<<row<<std::endl;
	int counters; std::cin>>counters;
	this->player_move(row, counters, true);
	return;
}

template<char token>
bool Nim<token>::game_finished() const{
	int check;
	std::for_each(game_layout, game_layout+no_rows, [&check](const int& x){check+=x;});
	if(check==0)
		return true;
	else 
		return false;
}

template<char token>
int Nim<token>::CPU_Opponent::nim_sum(int* dummy) const{
	class xor_add{
	public:
		int operator()(int sum, int x) const{
			return sum^x;
		}
	}xor_add;
	int x= std::accumulate(dummy, dummy+parent->no_rows, 0, xor_add);
	return x;

}

template<char token>
void Nim<token>::CPU_Opponent::decide_move(){
	srand(time(NULL));
	int random_or_calculated = rand()% 10;
	if(random_or_calculated<=difficulty)
		this->best_move();
	else
		this->random_move();
	return;
}

template<char token>
void Nim<token>::CPU_Opponent::best_move(){
	int* dummy = parent->game_layout;
	for (int i =0; i<parent->no_rows; i++)
	{
		for(int j=0; j<parent->game_layout[i]; j++)
		{
			int counters = dummy[i]-j;
			dummy[i]-=counters;
			if(this->nim_sum(dummy)== 0)
				parent->player_move(i, counters, false);
			else
				dummy=parent->game_layout;
		}
	}
	return;
}

template<char token>
void Nim<token>::CPU_Opponent::random_move(){
	int row= rand()%(parent->no_rows)+1;
	int counters=rand()%(parent->game_layout[row]);
	parent->player_move(row, counters, false);
	return;
}
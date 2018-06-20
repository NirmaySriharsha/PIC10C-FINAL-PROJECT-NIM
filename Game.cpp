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
		std::cerr<<"Memory allocation problem \n";
		game_layout=nullptr;
	}
	for(int i=0; i<no_rows; i++)
		game_layout[i]=2*i + 1;
}

template<char token>
void Nim<token>::print_game() const{
	int row_counter = 1;
	std::for_each(game_layout, game_layout+no_rows, 
		[&](const int& x){
			std::cout<<"Row "<<row_counter<<"\t";
			for(int i=1; i<=x; i++)
				std::cout<<token<<"\t";
			std::cout<<std::endl;
			++row_counter;
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
bool Nim<token>::user_move(){
	bool valid_move = false; int row; int counters;
	while(valid_move==false){
		std::cout<<"(Press 0 to exit at any time)"<<std::endl;
		std::cout<<"What row would you like to remove counters from?"<<std::endl;
		std::cin>>row;
		if(row == 0)
			return false;
		std::cout<<"How many counters would you like to remove from row "<<row<<std::endl;
		std::cin>>counters;
		if(row == 0 || counters == 0)
			return false;
		if(game_layout[row-1]<counters || row>no_rows+1)
			std::cout<<"Invalid input. Please try again."<<std::endl;
		else
			valid_move=true;
	}
	system("CLS");
	std::cout<<"Before : "<<std::endl;
	this->print_game();
	game_layout[row-1]-=counters;
	std::cout<<"After : "<<std::endl;
	this->print_game();
	std::cout<<"The player took "<<counters<<" counters from row "<<row<<std::endl;
	return true;
}

template<char token>
bool Nim<token>::game_finished() const{
	int check = 0;
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
	{
		std::cout<<"I choose the best possible move"<<std::endl;
		this->best_move();

	}
	else
	{
		std::cout<<"I choose a random move"<<std::endl;
		this->random_move();
	}
	return;
}

template<char token>
void Nim<token>::CPU_Opponent::best_move(){
	int dummy[parent->no_rows];
	std::copy(parent->game_layout, parent->game_layout+parent->no_rows, dummy);
	for (int i =0; i<parent->no_rows; i++)
	{
		std::cout<<"There are "<<parent->game_layout[i]<<"	counters on row" << i<<std::endl;

		for(int j=0; j<=parent->game_layout[i]-1; j++)
		{
			int counters = dummy[i]-j;
			dummy[i]-=counters;
			if(this->nim_sum(dummy)== 0)
				{
					std::cout<<"CPU played this: "<<i+1<<"	"<<counters<<std::endl;
					system("CLS");
					std::cout<<"Before :"<<std::endl;
					parent->print_game(); 
					parent->game_layout[i]-=counters;
					std::cout<<"After :"<<std::endl;
					parent->print_game();
					std::cout<<"The CPU removed "<<counters<<"  counters from row "<<i+1<<std::endl;
					return;
				}
			else
					std::copy(parent->game_layout, parent->game_layout+parent->no_rows, dummy);
		}
	}
	std::cout<<"No perfect move so settling for a random one \n";
	this->random_move();
	return;
}

template<char token>
void Nim<token>::CPU_Opponent::random_move(){
	srand(time(NULL));
	std::cout<<"Entered CPU_Opponent::random_move() safely "<<std::endl;
	int row;
	do{
		 row= rand()%(parent->no_rows);
	}while(parent->game_layout[row]==0);
	std::cout<<"Took a random row safely "<<row<<std::endl;
	int counters=rand()%(parent->game_layout[row]) + 1;
	std::cout<<"Took a random counter safely "<<counters<<std::endl;
	std::cout<<"I think i'll take "<<counters<<" from row "<<row+1<<" 	and recall that there are "<<parent->game_layout[row]<<" counters on row "<<row+1<<std::endl;
	system("CLS");
	std::cout<<"Before: "<<std::endl;
	parent->print_game();
	parent->game_layout[row]-=counters;
	std::cout<<"After : "<<std::endl;
	parent->print_game(); 
	std::cout<<"The CPU removed "<<counters<<"  counters from row "<<row+1<<std::endl;
	return;
}
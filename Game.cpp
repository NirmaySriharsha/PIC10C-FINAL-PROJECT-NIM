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
	catch(std::exception &e){								//Safe memory allocation to prevent heap overflow. 
		std::cerr<<"Memory allocation problem \n";
		game_layout=nullptr;
	}
	for(int i=0; i<no_rows; i++)
		game_layout[i]=2*i + 1;								//Creating the game. 
}

template<char token>
void Nim<token>::print_game() const{
	int row_counter = 1;									//Keeps track of which row it is. 
	std::for_each(game_layout, game_layout+no_rows, 		//for_each, a generic algorithm. 
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
	delete[] game_layout;								//safely disposing of our allocated memory to prevent memory leaks. 
}

template<char token>
Nim<token>::CPU_Opponent::CPU_Opponent(Nim<token>* _parent, int _difficulty):parent(_parent), difficulty(_difficulty){}

template<char token>
bool Nim<token>::user_move(){																	
	bool valid_move = false; int row; int counters;												//valid move stores whether or not the move the user wants to make is valid
	while(valid_move==false){																	//Keeps going if the user keeps making invalid moves
		std::cout<<"(Press 0 to exit at any time)"<<std::endl;
		std::cout<<"What row would you like to remove counters from? (1 to "<<no_rows<<")"<<std::endl;
		std::cin>>row;
		if(row == 0)				
			return false;																		//By returning false it tells us that the user wishes to quit. 
		std::cout<<"How many counters would you like to remove from row "<<row<<"? (Must be greater than 0 and less than" << game_layout[row-1]<<")"<<std::endl;
		std::cin>>counters;
		if(row == 0 || counters == 0)															//In case the user wished to quit while entering the no of counters 
			return false;
		if(game_layout[row-1]<counters || row>no_rows+1)										//Checks if the user's move is invalid
			std::cout<<"Invalid input. Please try again."<<std::endl;
		else
			valid_move=true;																	//If the move is valid, the user can exit the loop. 
	}
	system("CLS");
	std::cout<<"Before : "<<std::endl;															//Before and after helps the user understand exactly what happened. 
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
	std::for_each(game_layout, game_layout+no_rows, [&check](const int& x){check+=x;});			//Adds up the number of counters left in the game. 
	if(check==0)																				//If the game was over, there would be 0 counters left. 
		return true;
	else 
		return false;
}

template<char token>
int Nim<token>::CPU_Opponent::nim_sum(int* dummy) const{
	class xor_add{																				//^ is the XOR operator in C++ 
	public:
		int operator()(int sum, int x) const{
			return sum^x;
		}									
	}xor_add;																					//Defines our binary operation to be used in the next line. 
	int x= std::accumulate(dummy, dummy+parent->no_rows, 0, xor_add);							//Nim sum is simply the XOR addition of the number of counters in each row. 
	return x;

}

template<char token>
void Nim<token>::CPU_Opponent::decide_move(){
	//Difficulty works as follows. The CPU can either make a perfect move or a random move. The higher the difficulty, 
	//the more likely it is to make the perfect move. 
	srand(time(NULL));
	int random_or_calculated = rand()% 10;										//Decides whether or not to make the perfect or random move. 											
	if(random_or_calculated<=difficulty)										//As you can see, if difficulty is higher, 
	{																			//then random_or_calculated is more likely to satisfy the condition. 
		this->best_move();														//..leading to a perfect move occuring more often. 

	}																			//Notice that at the highest difficulty (10), the CPU will always make the best move.
	else
	{
		this->random_move();
	}
	return;
}

template<char token>
void Nim<token>::CPU_Opponent::best_move(){
	int dummy[parent->no_rows];																	//A "duplicate" game for the CPU to experiment on.  
	std::copy(parent->game_layout, parent->game_layout+parent->no_rows, dummy);					//Replicatin the current game. 
	//Here's how this function works: The CPU goes through every row and tries every move possible, and stops at the first one that will produce
	//a nim sum of 0 (there can be many such moves). Of course, this algorithm is not very efficient. However, keep in mind that most games are quite small. 
	//Small enough that a human can do the same thing in a few seconds as well. 
	for (int i =0; i<parent->no_rows; i++)														//Going through each row. 
	{
		for(int j=0; j<=parent->game_layout[i]-1; j++)											
		{
			int counters = dummy[i]-j;															//Going through each move. 
			dummy[i]-=counters;																	//Each move is experimented on dummy. 
			if(this->nim_sum(dummy)== 0)														//If the move works, 
				{
					system("CLS");																
					std::cout<<"Before :"<<std::endl;
					parent->print_game(); 
					parent->game_layout[i]-=counters;											//We execute it. 
					std::cout<<"After :"<<std::endl;
					parent->print_game();
					std::cout<<"The CPU removed "<<counters<<"  counters from row "<<i+1<<std::endl;
					return;
				}
			else
					std::copy(parent->game_layout, parent->game_layout+parent->no_rows, dummy);	//If the move doesn't work, we reset the dummy game
																								//And go back to experimenting. 
		}
	}
	//If the program reaches this far without being called by return; then that means that there was no perfect move/ 
	//Mathematically speaking this means that the game already has a nim sum of 0 and any move the CPU does would result in a nim sum of non zero. 
	//Regardless, in the absence of a perfect move, the CPU settles for any random move. 
	this->random_move();
	return;
}

template<char token>
void Nim<token>::CPU_Opponent::random_move(){
	srand(time(NULL));
	int row;
	do{															//Have to make sure that the random row actually has counters to remove. 
		 row= rand()%(parent->no_rows);							//Notice that the modulo function already assures us that all possible values will correspond to a row on the array. 
	}while(parent->game_layout[row]==0);
	int counters=rand()%(parent->game_layout[row]) + 1;			//Have to remove non zero counters from the row, hence the +1
	system("CLS");
	std::cout<<"Before: "<<std::endl;
	parent->print_game();
	parent->game_layout[row]-=counters;							//And we execute the random move. 
	std::cout<<"After : "<<std::endl;
	parent->print_game(); 
	std::cout<<"The CPU removed "<<counters<<"  counters from row "<<row+1<<std::endl;
	return;
}
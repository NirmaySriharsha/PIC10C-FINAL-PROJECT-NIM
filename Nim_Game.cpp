#include "Game.cpp"
#include <iostream>
#include <string>

std::string answer = "yes";
bool valid_input=true;
void ui();
void ui_interaction(void (*)());
int game_setup();
int CPU_setup();
template<char token>
void manage_player_move(Nim<token> game);
void play_first();

int main(){
	bool play_first;
	while((*answer.begin())=='y'||(*answer.begin())=='Y'){
		ui();
		if(answer=="no")
			return 0;
		int rows=game_setup();
		Nim<'*'> game(rows);
		int difficulty=CPU_setup();
		auto CPU= game.generate(difficulty);
		play_first();
		CPU.decide_move();

		answer="no";
		
	}
	return 0;
}

void play_first(){
	std::cout<<"Would you like to go first? (Y/N)"<<std::endl;
	char response;
	std::cin>response;
	if(response=='y'||response=='Y')
		manage_player_move();
	else return;

}
template<char token>
void manage_player_move(Nim<token> game){
	std::cout<<"Which row would you like to remove counters from? "<<std::endl;
	int row; std::cin>>row;
	std::cout<<"And how many counters would you like to remove? "<<std::endl;
	int counters; std::cin>>counters;
	game.player_move(row, counters);
}

int CPU_setup(){
	std::cout<<"How hard would you like your opponent to be? (On a scale of 1-10, 1 being the easiest and 10 being the hardest. We recommend 5)"<<std::endl;
	int difficulty; 
	std::cin>>difficulty;
	return difficulty;
}

int game_setup(){
	std::cout<<"How many rows would you like in your game? (Standard games have 4 rows)\n";
	int rows; std::cin>>rows;
	return rows;

}

void help_and_instructions(){

}

void math_of_nim(){

}

void sample_game(){
	
}

void ui(){
	system("CLS");
	if(valid_input==false)
		std::cout<<"Invalid Input. Try again!"<<std::endl;
	valid_input=true;
	char input;
	std::cout<<"****************************************************\n";
	std::cout<<"*         WELCOME TO THE GAME OF NIM               *\n";
	std::cout<<"****************************************************\n";
	std::cout<<"Type 				P    	TO PLAY!"<<std::endl;
	std::cout<<"				H 	FOR HELP AND INSTRUCTIONS"<<std::endl;
	std::cout<<"				N 	FOR THE MATH BEHIND NIM"<<std::endl;
	std::cout<<"				S       TO SEE A SAMPLE GAME BETWEEN TWO AI PLAYERS"<<std::endl;
	std::cout<<"				E 	TO EXIT"<<std::endl;
	std::cin>>input;

	switch(input)
	{
		case 'p':
		case 'P':
		return; break;
		case 'h':
		case 'H':
		ui_interaction(help_and_instructions); break;
		case 'n':
		case 'N':
		ui_interaction(math_of_nim); break;
		case 's':
		case 'S':
		ui_interaction(sample_game); break;
		case 'e':
		case 'E':
		std::cout<<"Thank you for your time!"; answer="no"; break;
		default:
		valid_input=false; ui(); break;

	}
}

void ui_interaction(void(*f)()){
	f();
	std::cout<<"Are you ready to play now? (Press P to Play, or M to go back to the menu)"<<std::endl;
	char input;
	std::cin>>input;
	switch(input){
		case 'p':
		case 'P':
		return; break;
		case 'm':
		case 'M':
		ui(); break;
	}
}
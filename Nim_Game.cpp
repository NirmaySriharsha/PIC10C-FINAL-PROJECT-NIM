#include <iostream>
#include "Game.cpp"
void ui(bool);
void ui_interaction(void (*)());
void play_game(); 
void help(); 
void math();

int main(){
	ui(true);
}

void ui_interaction(void (*f)()){
	system("CLS");
	f();
	std::cout<<"Would you like to play a game now? \n";
	std::cout<<"Press \t P to play again \n \t M to return to the menu \n \t E to exit \n";
	char input; std::cin>>input;
	switch(input){
		case 'p':
		case 'P':
		ui_interaction(play_game); break;
		case 'm':
		case 'M':
		ui(true); break;
		case 'e':
		case 'E':
		std::cout<<"Thank you for your time!"; break;
	}
}

void ui(bool valid_input){
	system("CLS");
	if(valid_input==false)
	{
		std::cout<<"Sorry, invalid input. Try again! \n";
	}
	std::cout<<"**********************************************************************************************************\n";
	std::cout<<"*                                     WELCOME TO THE GAME OF NIM                                         *\n";
	std::cout<<"**********************************************************************************************************\n";
	std::cout<<"		Press 				P 		to Play \n";
	std::cout<<"						H 		for Help and Instructions \n";
	std::cout<<"						N 		for the Math behind Nim\n";
	std::cout<<"						E		to exit\n";
	char input; std::cin>>input;
	switch(input){
		case 'p':
		case 'P':
		ui_interaction(play_game); break;
		case 'h':
		case 'H':
		ui_interaction(help); break;
		case 'n':
		case 'N':
		ui_interaction(math);break;
		case 'e':
		case 'E':
		std::cout<<"Thank you for your time!"<<std::endl; break;
		default:
		ui(false); break;
	}
	return;
}

void play_game(){
	bool player_won;
	std::cout<<"It's Nim time! Whoever takes the last counter wins! \n";
	std::cout<<"How many rows would you like to play with? (Standard is 4) \n";
	int rows; std::cin>>rows;
	Nim<'*'> game(rows);
	std::cout<<"How hard would you like your opponent to be? (1-10. Recommended 5) \n";
	int difficulty; std::cin>>difficulty;
	auto CPU = game.generate(difficulty);
	std::cout<<"Alright! Would you like to go first? (Y/N)"<<std::endl; char input; std::cin>>input;
	system("CLS");
	if(input=='Y'|| input == 'y')
		game.user_move();
	int i=1;
	while(game.game_finished() == false){
		std::cout<<"I entered the loop for the "<<i<<" time "<<std::endl;
		CPU.decide_move();
		if(game.game_finished())
		{
			player_won=false;
			break;
		}
		game.user_move();
		if(game.game_finished())
		{
			player_won=true;
			break;
		}
		++i;
	}
	if(player_won==true)
		std::cout<<"Congratulations! You win! \n";
	else
		std::cout<<"Sorry! You lose! \n";
	return;
}

void help(){
	return;
}

void math(){
	return;
}
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
	return;
}

void help(){
	return;
}

void math(){
	return;
}
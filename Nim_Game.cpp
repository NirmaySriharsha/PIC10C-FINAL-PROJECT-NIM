#include "Game.cpp"
#include <iostream>
#include <string>

std::string answer = "yes";

void ui(){
	system("CLS");
	std::cout<<"****************************************************\n";
	std::cout<<"*         WELCOME TO THE GAME OF NIM               *\n";
	std::cout<<"****************************************************\n";
	std::cout<<"Type 				P    	TO PLAY!"<<std::endl;
	std::cout<<"				H 	FOR HELP AND INSTRUCTIONS"<<std::endl;
	std::cout<<"				M 	FOR THE MATH BEHIND NIM"<<std::endl;
	std::cout<<"				S       TO SEE A SAMPLE GAME BETWEEN TWO AI PLAYERS"<<std::endl;
}

void ui_interaction(void(*f)()){
	f();
	std::cout<<"Are you ready to play now? "<<std::endl;


}


int main(){
	ui();




	return 0;
}
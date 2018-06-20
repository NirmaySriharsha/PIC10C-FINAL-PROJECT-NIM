#include <iostream>
#include "Game.cpp"
void ui(bool);											//Displays the menu and takes in the user's choice. The bool decides if the user's input is valid. 
void ui_interaction(void (*)());						//Reacts to the user choice. 
void play_game(); 										//Actually executes the game. 
void help(); 											//Provides the user with help and instructions. 
void math();											//Gives a mathematical summary behind the nim algorithm. 

int main(){
	ui(true);											//We invoke the ui. We say the user input is true because the user hasn't even inputted anything yet so there's no reason to show them an error message. 
}

void ui_interaction(void (*f)()){						//Using a function pointer to set policy based on the user's choice. 
	system("CLS");
	f();												//Executes the function. 
	std::cout<<"Would you like to play a game now? \n";
	std::cout<<"Press \t P to play again \n \t M to return to the menu \n \t E to exit \n";
	char input; std::cin>>input;						//Captures what the user wants to do next. 
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
	switch(input){														//Captures the user input. 
		case 'p':
		case 'P':
		ui_interaction(play_game); break;								//The switch block calls ui_interaction to react to the user's input. 
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
	bool player_won;																	//Stores whether or not the player won. 
	std::cout<<"It's Nim time! Whoever takes the last counter wins! \n";
	std::cout<<"How many rows would you like to play with?(Standard is 4. Make sure your window is big enough for your game!) \n";
	int rows; std::cin>>rows;
	Nim<'*'> game(rows);																//Creates the game. 
	std::cout<<"How hard would you like your opponent to be? (1-10. Recommended 5) \n";
	int difficulty; std::cin>>difficulty;
	auto CPU = game.generate(difficulty);												//Creates the CPU opponent. 
	std::cout<<"Alright! Would you like to go first? (Y/N)"<<std::endl; char input; std::cin>>input;
	system("CLS");
	if(input=='Y'|| input == 'y')														//If the user would like to go first. 
	{
		game.print_game();																//This is the actual bulk of the user's playing experience. 
		bool wants_to_continue = game.user_move();										//Helps facilitate the user choose his move. 
		if(wants_to_continue==false)													//If it turned out he wanted to quit. 
			return;																		//We quit. 
		std::string dummy; 																
		std::cout<<"Press enter to continue"<<std::endl;
		std::cin.ignore();																//Basicaly to give the user a break, time to see their move, think, etc. 
		std::cin.ignore();
	}
	while(game.game_finished() == false){												//While their still game to be played. 
		CPU.decide_move();																//CPU plays. 
		if(game.game_finished())														//If the game has finished after the CPU played, then the CPU must have
		{																				//taken the last token, i.e, the CPU won. 
			player_won=false;
			break;
		}
		bool wants_to_continue = game.user_move();										//Facilitates the user's move and checks if he wants to quit. 
		if(wants_to_continue==false)													//Quits if he wants to quit. 
			return;
		std::string dummy; 	
		std::cout<<"Press enter to continue"<<std::endl;
		std::cin.ignore();																//Gives the user breathing time. 
		std::cin.ignore();
		if(game.game_finished())														//If the game has finished after the user played, then the user must
		{																				//have taken the last token, i.e, the user must have won. 
			player_won=true;
			break;
		}
	}
	if(player_won==true)																//Displays the appropriate message based on the user's loss/victory. 
		std::cout<<"Congratulations! You win! \n";										
	else
		std::cout<<"Sorry! You lose! \n";
	return;
}

void help(){
	std::cout<<"THE RULES OF NIM"<<std::endl;
	std::cout<<"					Nim is a fairy simple game. Given a fixed number of rows (say, 4), each row will be populated with an increasing number of odd counters (1,3,5,7,etc). \n";
	std::cout<<"So a standard 4 row match would look as follows: \n";
	Nim<'*'> sample(4); 
	sample.print_game();	
	std::cout<<"Your goal is to take the last counter off the game. In order to do so, in a single move you are allowed to take as many counters from a row as you want, but ONLY FROM THAT ROW \n";
	std::cout<<"Therefore, for example, you are allowed to take 3 counters from row 5, or 1 counter from row 1, but not 7 counters from row 2 and 3, etc. \n";
	std::cout<<"We recommend you begin with a lower difficulty. The CPU opponent at difficulty 10 is unbeatable unless you also know the winning algorithm. \n";
	std::cout<<"Have fun!"<<std::endl;
	return;
}

void math(){
	std::cout<<"THE MATH OF NIM"<<std::endl;
	std::cout<<"				Nim is a game that most math students would encounter during an introductory foray into the field of mathematical game theory. \n";
	std::cout<<"The reason being that Nim is simple and fun, yet also has deep insights into game theory and winning algorithms. \n";
	std::cout<<"Yes, Nim has a winning algorithm. And yes, the CPU knows it. \n";
	std::cout<<"So what is this algorithm? "<<std::endl;
	std::cout<<"First we cover the concept of a 'Nim Sum'. \n";
	std::cout<<"A Nim sum is basically a binary XOR addition. An XOR addition is basically a binary addition WITHOUT CARRYING. \n";
	std::cout<<"For example, if we want to find the Nim sum of 2 and 5, first we convert them to binary: 10 and 110. And then we add the two without carrying: \n";
	std::cout<<"				 10  \n 				110\n 			       =100 \n";
	std::cout<<"Given a game of Nim, we convert each row into binary based on the number of counters it has, and then find its nim sum. \n";
	std::cout<<"Without going too deep into the mathematics, it can be proved that if the nim sum of the game is 0, any subsequent move will make the nim sum non-zero, and if the nim sum of the game is non-zero, then there exists a move that makes the game have a nim sum of zero. \n";
	std::cout<<"Combine these two facts with the fact that the nim sum of a finished game is 0 (since every row is empty), and we see that the player who always makes moves such that the nim sum of the game is zero following his move will win (as he will eventually make the move that will make the board empty, or in other words, he will take the last counter. \n";
	std::cout<<"This, in essence, is the secret of Nim: Make the move that will result in a Nim sum of 0. Why don't you try out this algorithm? "<<std::endl;
	std::cout<<"This algorithm will mathematically guarantee your victory. \n";
	std::cout<<".......with one small caveat. When both players use the algorithm, then clearly only one of them can make moves that will result in a nim sum of 0 (provided they both play without mistakes). Then who will win? The answer comes down to the layout of the starting board. If the starting board has a nim sum of 0, then the first players cannot make a move that will result in a nim sum of 0, thus making him lose. Similarly, if the starting position of the board has a nim sum of non-zero, then the first player can make a move that will make the game zero, but the second player can't, making the second player lose."<<std::endl;
	std::cout<<"In other words, if you're both playing perfectly, then who goes first matters a lot. \n";
	return;
}
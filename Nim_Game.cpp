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
	std::cout<<"How many rows would you like to play with?(Standard is 4. Make sure your window is big enough for your game!) \n";
	int rows; std::cin>>rows;
	Nim<'*'> game(rows);
	std::cout<<"How hard would you like your opponent to be? (1-10. Recommended 5) \n";
	int difficulty; std::cin>>difficulty;
	auto CPU = game.generate(difficulty);
	std::cout<<"Alright! Would you like to go first? (Y/N)"<<std::endl; char input; std::cin>>input;
	system("CLS");
	if(input=='Y'|| input == 'y')
	{
		game.print_game();
		bool wants_to_continue = game.user_move();
		if(wants_to_continue==false)
			return;
		std::string dummy; 
		std::cout<<"Press enter to continue"<<std::endl;
		std::cin.ignore();
		std::cin.ignore();
	}
	int i=1;
	while(game.game_finished() == false){
		std::cout<<"I entered the loop for the "<<i<<" time "<<std::endl;
		CPU.decide_move();
		if(game.game_finished())
		{
			player_won=false;
			break;
		}
		bool wants_to_continue = game.user_move();
		if(wants_to_continue==false)
			return;
		std::string dummy; 
		std::cout<<"Press enter to continue"<<std::endl;
		std::cin.ignore();
		std::cin.ignore();
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
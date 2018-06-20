#include <iostream>
#include <string>
#include <vector>

template<char token = '*'>							//Templating the class so that any symbol can be used as counters
class Nim
{
public:
	Nim(int = 4);
	void print_game() const;
	~Nim();
private:
	class CPU_Opponent;								//CPU_Opponent will be exactly what it sounds like: The "AI" that the player will play against
public:
	CPU_Opponent generate(int difficulty = 5){		//Our way to access the private class. 
		return CPU_Opponent(this, difficulty);
	}
	friend class CPU_Opponent;						
	bool user_move();								//Helps the user make his move. 
													//However, it has another important duty. It returns as a bool if the user wants to quit in the middle of the game. 
	bool game_finished() const;						//Checks if the game is finished or not. 
private:
	int* game_layout;								//Stores the current layout of the game (how many rows and how many counters in each row)
	int no_rows;									//Stores how many rows. 
private:
	class CPU_Opponent								//CPU_Opponent is private to prevent outside meddling. 
	{
	public:
		int nim_sum(int*) const;					//Calculates the nim sum of the game to make a decision about its next move. 
		friend class Nim<token>;
		void decide_move();							//Helps decide what the next move should be (a random one or a perfect one)
		void best_move();							//Finds and executes the best move 
		void random_move();							//Executes a random move
	private:
		CPU_Opponent(Nim<token>*, int); 			//Private constructor to keep the class and its objects away from the front end users. 
		int difficulty;								//Difficulty of the CPU opponent. 
		Nim<token>* parent;
	};
};

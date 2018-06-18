#include <iostream>
#include <string>
#include <vector>


template<char token = '*'>
class Nim
{
public:
	Nim(int = 4);
	void print_game() const;
	~Nim();
private:
	class CPU_Opponent{
	private:
		int difficulty;
		Nim<token>* parent;
		CPU_Opponent(int, Nim<token>*);
	public:
		int nim_sum(int*) const;
		friend class Nim<token>;
		void decide_move();
		void best_move();
		void random_move();
	};
	friend class CPU_Opponent;
public:
	CPU_Opponent generate(int _difficulty = 5){
		return CPU_Opponent(_difficulty, this);
	}
	void player_move(int, int);
	bool game_finished() const;
private:
	int* game_layout;
	int no_rows;

};
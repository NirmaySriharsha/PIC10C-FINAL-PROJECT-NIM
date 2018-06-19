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
	class CPU_Opponent;
public:
	CPU_Opponent generate(int difficulty = 5){
		return CPU_Opponent(this, difficulty);
	}
	friend class CPU_Opponent;
	void player_move(int, int, bool);
	void user_move();
	bool game_finished() const;
private:
	int* game_layout;
	int no_rows;
private:
	class CPU_Opponent
	{
	public:
		int nim_sum(int*) const;
		friend class Nim<token>;
		void decide_move();
		void best_move();
		void random_move();
	private:
		CPU_Opponent(Nim<token>*, int); 
		int difficulty;
		Nim<token>* parent;
	};
};

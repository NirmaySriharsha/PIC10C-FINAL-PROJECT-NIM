#include <iostream>
#include <string>


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
		int nim_sum() const;
		friend class Nim<token>;
	};
	friend class CPU_Opponent;
public:
	CPU_Opponent generate(int _difficulty = 5){
		return CPU_Opponent(_difficulty, this);
	}
private:
	int* game_layout;
	int no_rows;

};
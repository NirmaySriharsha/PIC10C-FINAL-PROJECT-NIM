#include <iostream>
template<char token = '*', int no_rows = 4>
class Game{
public:
	Game();
	void print_game() const;
	class CPU_opponent;
public:
	class CPU_opponent{
	public:
		void optimal_move() const;
	private:
		CPU_opponent(Game*, int);	
		int difficulty;
		Game* parent;
	};
private:
	int* rows;
public:
	CPU_opponent generate(int _difficulty = 5){
		return CPU_opponent(this, _difficulty);
	}
};

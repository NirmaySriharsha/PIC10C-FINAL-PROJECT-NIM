#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

template<char token, int size>
class Game
{
public:
	Game();
	void print_out_game() const;
	~Game();
	class cpu_opponent;
	class cpu_opponent
	{
	public:
		void calculate_move() const;
		cpu_opponent();
		~cpu_opponent();
	private:
		bool nim_solved;
		void row_fill();
	};
private:
	int* rows=new int[size]; 


};
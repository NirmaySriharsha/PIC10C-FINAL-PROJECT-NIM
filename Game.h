#include <iostream>

class Game{
public:
	Game(int _no, char _token);
	void print_game() const;
	class CPU_opponent{
	public:

	private:
		bool difficulty;
		CPU_opponent(bool _difficulty):difficulty(_difficulty){}

	};
	
private:
	int no_rows; char token;
	int* rows=new int[no_rows];
};






/*class Standard_Game extends Game{
public: 

private:
	int no_rows=4; char token= '*';
};*/
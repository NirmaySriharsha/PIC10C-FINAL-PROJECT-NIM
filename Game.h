#include <iostream>

class Game{
public:
	Game(int _no, char _token);
	void print_game() const;
	
private:
	int no_rows; char token;
	int* rows=new int[no_rows];
};






/*class Standard_Game extends Game{
public: 

private:
	int no_rows=4; char token= '*';
};*/
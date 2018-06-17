#include <iostream>
#include "Game.cpp"
#include <string>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main(){
	char _token; int rows; 
	std::string play_again="yes";
	std::string dummy;
	while(play_again == "yes" || play_again == "y"){
		std::cout<<"Enter what you would like to use as your token! (*, $, etc) "<<std::endl;
		std::cin>>_token;
		std::cout<<"Would you like to play again?"<<std::endl;
		getline(std::cin, dummy);
		std::cin>>play_again;
	}
	return 0;
}
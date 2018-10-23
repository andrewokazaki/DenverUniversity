#include <iostream>
#include "tickTackToe/tickTackToe.h"
//test state 
bool test = true; 

int main() {

try{
	//create new tick tack toe game 
	boardGame::tickTackToe game;
	if(test == true){ //test the game
		game.test();  
	}else{            //run the game 
		game.run(); 
	}
}catch (std::exception e){
	std::cerr << "caught: " << e.what() << '\n';
}catch(...){
	std::cerr << "caught unknown error \n"; 
}

	std::cout<<"DONE"<<std::endl;
    return 0;
}

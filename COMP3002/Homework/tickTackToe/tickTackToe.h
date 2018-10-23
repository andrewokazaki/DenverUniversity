#ifndef INC_20181019_tickTackToe_H
#define INC_20181019_tickTackToe_H

#include <iostream>

namespace boardGame{
//cell occupation only 3 options 
enum class occupation{X, O, E};
//player only 2 players 
enum class Player{playerOne, playerTwo};
//game state only 3 states
enum class gameState{won, cats, inProgress};

//game class tick tack toe
class tickTackToe{
public:
	//ctor
	tickTackToe(); 
	//run the game 
	void run();
	//run the test 
	void test(); 
private: 
	//create board variable  
	occupation board[3][3];
	//create player variable 
	Player player; 
	//set the game state 
	gameState state; 
};
//reset board 
void resetBoard(occupation board[3][3]); 
//print the board
void printBoard(occupation board[3][3]); 
//move
void move(occupation board[3][3], Player *player);
//move is valid 
void isValid(occupation board[3][3], Player *player, int x, int y);
//check move 
void checkMove(occupation board[3][3], Player player,gameState *state);
//check column 
void checkCol(occupation board[3][3], occupation O, gameState *state, int x = 0, int y = 0);
//check the rows 
void checkRow(occupation board[3][3], occupation O, gameState *state, int x = 0, int y = 0); 
//check diagonal 
void checkDag1(occupation board[3][3], occupation O, gameState *state, int x = 0, int y = 0); 
//check diagonal 
void checkDag2(occupation board[3][3], occupation O, gameState *state, int x = 2, int y = 0); 
//check game state 
void checkCat(occupation board[3][3], occupation O, gameState *state); 
//overload operator 
std::ostream& operator<<(std::ostream &os, occupation m);
//overload operator 
std::ostream& operator<<(std::ostream &os, Player P);
//overload operator s
Player &operator++(Player &p);
} //end game namespace
#endif //INC_20181017_DATE_H

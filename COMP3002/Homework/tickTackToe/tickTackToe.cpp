#include "tickTackToe.h"

#include <iostream>
#include <string>


const int BOARD_SIZE = 3; 

namespace boardGame{

//ctor 
tickTackToe::tickTackToe(){
	resetBoard(board);                                    //reset board to all empty occupation
	player = Player::playerOne;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	std::cout <<  "Welcome to Tick Tack Toe \n"           //print welcome message
	              "Created By Andrew Okazaki\n";
}
//play the game
void tickTackToe::run(){
	//loop through turns until someone has won or a cats game
	switch(state){                                        
		//game is running in progress                     
		case gameState::inProgress:              
			 printBoard(board);                           //print the board current state 
			 move(board, &player);                        //players turn 
			 checkMove(board, player, &state);            //check the game state 
			 run();                                       //call itself 
			 break;                                       //break
		//cats game tie game found
		case gameState::cats:              
			 printBoard(board);                           //print the board current state
		     std::cout<<"CATS"<<std::endl;                //print Cats so the players know
		     break;                                       //break
		//a player has won  
		case gameState::won:               
			 printBoard(board);                           //print the board current state    
			 ++player;                                    //switch player to previous player 
			 std::cout<<player<<" Won"<<std::endl;        //print that the player has won
			 break;                                       //break
	}
}

//occupy all board spaces with empty state 
void resetBoard(occupation board[3][3]){	
	for(int i = 0; i < BOARD_SIZE; ++i){                  //loop columns 
		for(int j = 0; j < BOARD_SIZE; ++j){              //loop rows 
			board[i][j] = occupation::E;                  //occupy board space with empty space
		}
	}
}
//print the board 
void printBoard(occupation board[3][3]){       
	for(int i = 0; i < BOARD_SIZE; ++i){                  //loop columns 
		for(int j = 0; j < BOARD_SIZE; ++j){              //loop rows 
			std::cout << board[i][j];                     //print cell 
		}
		if(i == 0){std::cout<<"   |   7|8|9";}            //print move instruction to row 1
		if(i == 1){std::cout<<"   |   4|5|6";}            //print move instruction to row 2
		if(i == 2){std::cout<<"   |   1|2|3";}            //print move instruction to row 3 
		std::cout<<std::endl;                             //new line character 
	}
}
//recieve a players move 
void move(occupation board[3][3], Player *player){
	std::string space = "???";                            //define variable
	std::cout<<*player<<" Choose your move(1-9): ";       //print instruction 
	std::cin>>space;                                      //initalize variable with user input 
	int value = atoi(space.c_str());                      //change user input to int value
	switch(value){ 
		case 1:                                           //choose location 1 on the board (2,0)
			isValid(board, player,2,0);                   //check if move is valid
			break;
		case 2:                                           //choose location 2 on the board (2,1)
			isValid(board, player,2,1);                   //check if move is valid
			break;
		case 3:                                           //choose location 3 on the board (2,2)
			isValid(board, player,2,2);                   //check if move is valid
			break; 
		case 4:                                           //choose location 4 on the board (1,0)
			isValid(board, player,1,0);                   //check if move is valid
			break; 
		case 5:                                           //choose location 5 on the board (1,1)
			isValid(board, player,1,1);                   //check if move is valid
			break; 
		case 6:                                           //choose location 6 on the board (1,2)
			isValid(board, player,1,2);                   //check if move is valid
			break; 
		case 7:                                           //choose location 7 on the board (0,0)
			isValid(board, player,0,0);                   //check if move is valid
			break; 
		case 8:                                           //choose location 8 on the board (0,1)
			isValid(board, player,0,1);                   //check if move is valid
			break; 
		case 9:                                           //choose location 9 on the board (0,2)
			isValid(board, player,0,2);                   //check if move is valid
			break; 
		default:                                          //if input does not match any case 
			std::cout<<"incorect move"<< std::endl;       //let player know input was incorect 
		break; 

	}
} 
//check if the board is valid place the piece 
void isValid(occupation board[3][3], Player *player, int x, int y){
	//check if cell ocupation is empty 
	if(board[x][y] == occupation::E){                         
		if(*player == Player::playerOne){                 //if current player is player one 
			board[x][y] = occupation::X;}                 //place a X for player one 
		else{                                             //if current player is player two 
			board[x][y] = occupation::O;}                 //place an O for player two 
		++*player;                                        //incement the player
	}else{                                                //cell is occupied                                 
		std::cout << "Space Is Occupied" << std::endl;    //inform the player cell is occupied 
	}
}
//check after the move has created a win,cats or inProgress game state 
void checkMove(occupation board[3][3], Player player, gameState *state){
	boardGame::occupation O;                              //define variable 
	if (player == Player::playerOne){O = occupation::O;}  //set player one
	else{O = occupation::X;}                              //set player two 
	checkCol(board,O,state);                              //check columns for win 
	checkRow(board,O,state);                              //check rows for a win 
	checkDag1(board,O,state);							  //check Diagonal for a win 
	checkDag2(board,O,state);							  //check Diagonal for a win 
	if(*state != gameState::won){
		checkCat(board,O,state);                          //check board for cats game 
	}
}
//check colums for a win 
void checkCol(occupation board[3][3],occupation O,gameState *state,int x,int y){
	if(x == BOARD_SIZE){                                  //if X = the board size set the game state to win base case  
		*state = gameState::won; 						  //sets the game state to win 
	}else if(y < BOARD_SIZE){                             //if y is less than the board size then continue 
		if(board[x][y] == O){                             //if board is = to player space continue to next x space 
			checkCol(board,O,state,x+1,y);                //call itself 
		}else{                                            //if board space isnt = to player space go to the next y location 
			checkCol(board,O,state,0,y+1);                //call itself and go to the next y
		}
	}
}
//check rows for a win
void checkRow(occupation board[3][3],occupation O,gameState *state,int x,int y){
	if(y == BOARD_SIZE){                                  //if y = the board size set the game state to win base case
		*state = gameState::won;                          //sets the game state to win 
	}else if(x < BOARD_SIZE){                             //if x is less than the board size then continue 
		if(board[x][y] == O){                             //if board is = to player space continue to next y space
			checkRow(board,O,state,x,y+1);                //call itself 
		}else{                                            //if board space isnt = to player space go to the next x location
			checkRow(board,O,state,x+1,0);                //call itself and go to the next x
		}
	} 
}
//check diagonal 
void checkDag1(occupation board[3][3],occupation O,gameState *state,int x,int y){
	if(y == BOARD_SIZE){                                  //if y = the board size set the game state to win base case
		*state = boardGame::gameState::won;               //sets the game state to win
	}else if(board[x][y] == O){                           //if board is = to player space continue to next x y space
		checkDag1(board,O,state,x+1,y+1);                 //call itself and go to the next +x +y space
	}
}
//check diagonal 
void checkDag2(occupation board[3][3],occupation O,gameState *state,int x,int y){
	if(y == BOARD_SIZE){                                  //if y = the board size set the game state to win base case
		*state = gameState::won; 					      //sets the game state to win
	}else if(board[x][y] == O){                           //if board is = to player space continue to next x y space
		checkDag2(board,O,state,x-1,y+1);                 //call itself and go to the next -x +y space
	}
}
//check for cats game
void checkCat(occupation board[3][3],occupation O,gameState *state){
	bool cats = true;                                     //init cats game to true 
	for (int i = 0; i < 3; ++i){                          //loop columns 
        for (int j = 0; j < 3; ++j){                      //loop row 
            if (board[i][j] == occupation::E){            //if found empty space
                cats = false;                             //set cats to false 
                break;                                    //break from loop 
            }
        }
    }
    if(cats){                                             //if the loop exits not finding an empty space 
    	*state = gameState::cats;                         //set the game state to cats game 
    }
}
//overload opperator 
std::ostream &operator<<(std::ostream &os,Player P){
    if(P == Player::playerOne){os << "X's";}
    else if(P == Player::playerTwo){os << "O's";}
    return os;
}
//overload opperator 
std::ostream &operator<<(std::ostream &os,occupation O){
    if(O == occupation::E){os << "- ";}
    else if(O == occupation::X){os << "X ";}
    else if(O == occupation::O){os << "O ";}
    return os;
}
//overload opperator 
Player &operator++(Player &p) {
    if (p == Player::playerOne){p = Player::playerTwo;} 
    else {p = Player::playerOne;}
    return p;
}
void tickTackToe::test(){
	resetBoard(board);
	player = Player::playerOne;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	board[0][0] = occupation::O;
	board[0][1] = occupation::X;
	board[0][2] = occupation::O;
	board[1][0] = occupation::X;
	board[1][1] = occupation::O;
	board[1][2] = occupation::X;
	board[2][0] = occupation::X;
	board[2][1] = occupation::O;
	board[2][2] = occupation::X;
	printBoard(board);
	checkMove(board, player, &state);  
	if(state == gameState::cats){
		std::cout << "correct cats\n"<<std::endl; 
	}

	resetBoard(board);
	player = Player::playerOne;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	board[0][0] = occupation::E;
	board[0][1] = occupation::X;
	board[0][2] = occupation::O;
	board[1][0] = occupation::E;
	board[1][1] = occupation::E;
	board[1][2] = occupation::E;
	board[2][0] = occupation::E;
	board[2][1] = occupation::E;
	board[2][2] = occupation::E;
	printBoard(board);
	checkMove(board, player, &state);  
	if(state == gameState::inProgress){
		std::cout << "correct inProgress\n"<<std::endl; 
	}

	resetBoard(board);
	player = Player::playerTwo;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	board[0][0] = occupation::O;
	board[0][1] = occupation::X;
	board[0][2] = occupation::O;
	board[1][0] = occupation::O;
	board[1][1] = occupation::O;
	board[1][2] = occupation::X;
	board[2][0] = occupation::X;
	board[2][1] = occupation::X;
	board[2][2] = occupation::X;
	printBoard(board);
	checkMove(board, player, &state);  
	if(state == gameState::won){
		++player;                                    //switch player to previous player 
		std::cout<<player<<" Won"<<std::endl;        //print that the player has won
		std::cout << "correct colum win \n"<<std::endl; 
	}
	resetBoard(board);
	player = Player::playerOne;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	board[0][0] = occupation::O;
	board[0][1] = occupation::X;
	board[0][2] = occupation::O;
	board[1][0] = occupation::O;
	board[1][1] = occupation::E;
	board[1][2] = occupation::X;
	board[2][0] = occupation::O;
	board[2][1] = occupation::X;
	board[2][2] = occupation::O;
	printBoard(board);
	checkMove(board, player, &state);  
	if(state == gameState::won){
		++player;                                    //switch player to previous player 
		std::cout<<player<<" Won"<<std::endl;        //print that the player has won
		std::cout << "correct row win\n"<<std::endl; 
	}

	resetBoard(board);
	player = Player::playerTwo;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	board[0][0] = occupation::X;
	board[0][1] = occupation::O;
	board[0][2] = occupation::O;
	board[1][0] = occupation::O;
	board[1][1] = occupation::X;
	board[1][2] = occupation::E;
	board[2][0] = occupation::O;
	board[2][1] = occupation::X;
	board[2][2] = occupation::X;
	printBoard(board);
	checkMove(board, player, &state);  
	if(state == gameState::won){
		++player;                                    //switch player to previous player 
		std::cout<<player<<" Won"<<std::endl;        //print that the player has won
		std::cout << "correct row win\n"<<std::endl; 
	}

	resetBoard(board);
	player = Player::playerOne;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	board[0][0] = occupation::X;
	board[0][1] = occupation::X;
	board[0][2] = occupation::O;
	board[1][0] = occupation::O;
	board[1][1] = occupation::O;
	board[1][2] = occupation::X;
	board[2][0] = occupation::O;
	board[2][1] = occupation::X;
	board[2][2] = occupation::O;
	printBoard(board);
	checkMove(board, player, &state);  
	if(state == gameState::won){
		++player;                                    //switch player to previous player 
		std::cout<<player<<" Won"<<std::endl;        //print that the player has won
		std::cout << "correct diagonal1 win \n"<<std::endl; 
	}

	resetBoard(board);
	player = Player::playerOne;                           //the starting player is player one 
	state = gameState::inProgress;                        //the starting game state is inProgress 
	board[0][0] = occupation::O;
	board[0][1] = occupation::X;
	board[0][2] = occupation::O;
	board[1][0] = occupation::O;
	board[1][1] = occupation::O;
	board[1][2] = occupation::X;
	board[2][0] = occupation::X;
	board[2][1] = occupation::X;
	board[2][2] = occupation::O;
	printBoard(board);
	checkMove(board, player, &state);  
	if(state == gameState::won){
		++player;                                    //switch player to previous player 
		std::cout<<player<<" Won"<<std::endl;        //print that the player has won
		std::cout << "correct diagonal2 win \n"<<std::endl; 
	}

	std::cout << "player test"<<std::endl;
	player = Player::playerOne;
	std::cout << "starting player " << player <<std::endl;
	++player; 
	std::cout << "next player " << player <<std::endl;
	++player; 
	std::cout << "next player " << player <<std::endl;
	++player; 
	std::cout << "next player " << player <<std::endl;
	++player; 
	std::cout << "next player " << player <<std::endl;
}
}//end of namespace boardGame 




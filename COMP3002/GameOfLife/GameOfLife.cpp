//
// Created by Andrew Okazaki on 11/4/18.
//

#include "GameOfLife.h"

//ctor
GameOfLife::GameOfLife(int rows_, int cols_) : rows(rows_), cols(cols_){
    //init
    current = new bool*[rows];
    next = new bool*[rows];
    for(int i = 0; i < rows; ++i){
        current[i] = new bool[cols];
        next[i] = new bool[cols];
    }

    // fill
    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            current[i][j] = false;
            next[i][j] = true;
        }
    }
}

//dtor
GameOfLife::~GameOfLife(){
    // free
    for(int i = 0; i < rows; ++i) {
        delete[] current[i];
        delete[] next[i];
    }
    delete [] current;
    delete [] next;
}

bool GameOfLife::alive_in_next_generation(int row, int col) {
    // Rules:
    // * If a cell has less than 2 live neighbors, it will die (or stay dead)
    // * If a cell is alive and has 2 live neighbors, it will stay alive
    // * If a cell that 3 live neighbors, it will be alive
    //   (either by staying alive or coming alive)
    // * If a cell has move than 3 live neighbors, it will die (or stay dead)
    // * If not otherwise mentioned, the cell is dead
    //
    // Live neighbors are calculated by looking at its octile neighbors. That is
    // for a cell X, you look at the neighbors A-H as in:
    //
    //  A B C
    //  D X E
    //  F G H
    //
    // Note that a cell does not itself count towards its own live neighbor count
    //live neighbors
    int liveNeighbors = 0;
    //count the number of alive neighbors
    if(current[row-1][col-1]){ ++liveNeighbors; }
    if(current[row-1][col]){ ++liveNeighbors; }
    if(current[row-1][col+1]){ ++liveNeighbors; }
    if(current[row][col-1]){ ++liveNeighbors; }
    if(current[row][col+1]){ ++liveNeighbors; }
    if(current[row+1][col-1]){ ++liveNeighbors; }
    if(current[row+1][col]){ ++liveNeighbors; }
    if(current[row+1][col+1]){ ++liveNeighbors; }

    //logic to determine if alive(true) or dead(false)
    if(liveNeighbors < 2){
        return false;
    }else if(liveNeighbors == 2 && current[row][col]){
        return true;
    }else if(liveNeighbors == 3){
        return true;
    }else{
        return false;
    }
}

void GameOfLife::simulate_step() {
    // Clear out next by going through each row and column and set
    // every value to false
    // fill
    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            next[i][j] = false;
        }
    }

    // Calculate next by going through each row and column, except for the
    // borders, and set the ith, jth entry in next to the result of the
    // function alive based upon current at i, j
    for(int i = 1; i <(rows-1); ++i){
        for (int j = 1; j <(cols-1); ++j){
            next[i][j] = alive_in_next_generation(i,j);
        }
    }

    // Swap current and next
    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            current[i][j] = next[i][j];
        }
    }
}


std::ostream &operator<<(std::ostream &os, const GameOfLife &gol) {
    // This function should print out the 2D array board.
    // If you would like to print out a color block instead of a character,
    // use
    //std::cout << "\033[7m \033[0m";
    // This is an ANSI escape sequence which will print out a solid block of
    // color that is the opposite color of your terminal. That is if the
    // background
    // of your terminal is normally black, it will be white, and vice versa.
    // print
    os<< std::endl;
    for(int i = 0; i < gol.get_rows(); ++i) {
        for (int j = 0; j < gol.get_cols(); ++j) {
            if(gol.get_current()[i][j]){
                os << "\033[7m \033[0m";
            }else{
                os << " ";
            }
        }
        os << std::endl;
    }
    return os;
}

void GameOfLife::add_blinker(int row_off, int col_off) {
    current[row_off][col_off - 1] = true;
    current[row_off][col_off] = true;
    current[row_off][col_off + 1] = true;
}

void GameOfLife::add_toad(int row_off, int col_off) {
    current[2 + row_off][2 + col_off] = true;
    current[2 + row_off][3 + col_off] = true;
    current[2 + row_off][4 + col_off] = true;
    current[3 + row_off][1 + col_off] = true;
    current[3 + row_off][2 + col_off] = true;
    current[3 + row_off][3 + col_off] = true;
}

void GameOfLife::add_pentadecathlon(int row_off, int col_off) {
    current[4 + row_off][5 + col_off] = true;
    current[5 + row_off][5 + col_off] = true;
    current[7 + row_off][5 + col_off] = true;
    current[8 + row_off][5 + col_off] = true;
    current[9 + row_off][5 + col_off] = true;
    current[10 + row_off][5 + col_off] = true;
    current[12 + row_off][5 + col_off] = true;
    current[13 + row_off][5 + col_off] = true;

    current[6 + row_off][4 + col_off] = true;
    current[6 + row_off][6 + col_off] = true;
    current[11 + row_off][4 + col_off] = true;
    current[11 + row_off][6 + col_off] = true;
}

void GameOfLife::add_gosper_glider_gun() {
    current[6][1] = true;
    current[7][1] = true;
    current[6][2] = true;
    current[7][2] = true;

    current[4][35] = true;
    current[5][35] = true;
    current[4][36] = true;
    current[5][36] = true;

    current[4][13] = true;
    current[4][14] = true;
    current[5][12] = true;
    current[5][16] = true;
    current[6][11] = true;
    current[6][17] = true;
    current[7][11] = true;
    current[7][15] = true;
    current[7][17] = true;
    current[7][18] = true;
    current[8][11] = true;
    current[8][17] = true;
    current[9][12] = true;
    current[9][16] = true;
    current[10][13] = true;
    current[10][14] = true;

    current[2][25] = true;
    current[3][23] = true;
    current[3][25] = true;
    current[4][21] = true;
    current[4][22] = true;
    current[5][21] = true;
    current[5][22] = true;
    current[6][21] = true;
    current[6][22] = true;
    current[7][23] = true;
    current[7][25] = true;
    current[8][25] = true;
}

void GameOfLife::add_pulsar(int row_off, int col_off) {
    current[2 + row_off][4 + col_off] = current[2 + row_off][5 + col_off] =
    current[2 + row_off][6 + col_off] = true;
    current[2 + row_off][10 + col_off] = current[2 + row_off][11 + col_off] =
    current[2 + row_off][12 + col_off] = true;

    current[7 + row_off][4 + col_off] = current[7 + row_off][5 + col_off] =
    current[7 + row_off][6 + col_off] = true;
    current[7 + row_off][10 + col_off] = current[7 + row_off][11 + col_off] =
    current[7 + row_off][12 + col_off] = true;

    current[9 + row_off][4 + col_off] = current[9 + row_off][5 + col_off] =
    current[9 + row_off][6 + col_off] = true;
    current[9 + row_off][10 + col_off] = current[9 + row_off][11 + col_off] =
    current[9 + row_off][12 + col_off] = true;

    current[14 + row_off][4 + col_off] = current[14 + row_off][5 + col_off] =
    current[14 + row_off][6 + col_off] = true;
    current[14 + row_off][10 + col_off] = current[14 + row_off][11 + col_off] =
    current[14 + row_off][12 + col_off] = true;

    current[4 + row_off][2 + col_off] = current[5 + row_off][2 + col_off] =
    current[6 + row_off][2 + col_off] = true;
    current[4 + row_off][7 + col_off] = current[5 + row_off][7 + col_off] =
    current[6 + row_off][7 + col_off] = true;
    current[4 + row_off][9 + col_off] = current[5 + row_off][9 + col_off] =
    current[6 + row_off][9 + col_off] = true;
    current[4 + row_off][14 + col_off] = current[5 + row_off][14 + col_off] =
    current[6 + row_off][14 + col_off] = true;

    current[10 + row_off][2 + col_off] = current[11 + row_off][2 + col_off] =
    current[12 + row_off][2 + col_off] = true;
    current[10 + row_off][7 + col_off] = current[11 + row_off][7 + col_off] =
    current[12 + row_off][7 + col_off] = true;
    current[10 + row_off][9 + col_off] = current[11 + row_off][9 + col_off] =
    current[12 + row_off][9 + col_off] = true;
    current[10 + row_off][14 + col_off] = current[11 + row_off][14 + col_off] =
    current[12 + row_off][14 + col_off] = true;
}

//get columns
int GameOfLife::get_cols() const {
    return cols;
}

//get rows
int GameOfLife::get_rows() const{
    return rows;
}

//get current
bool **GameOfLife::get_current() const{
    return current;
}

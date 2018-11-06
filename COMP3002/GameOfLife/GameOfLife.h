#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>

class GameOfLife {
public:
    //ctor
    explicit GameOfLife(int rows = 33, int cols = 44);
    //dtor
    ~GameOfLife();

    GameOfLife(const GameOfLife &other) = delete;
    GameOfLife(GameOfLife &&other) = delete;
    GameOfLife &operator=(const GameOfLife &other) = delete;
    GameOfLife &operator=(GameOfLife &&other) = delete;

    //simulate next step
    void simulate_step();

    //add structures
    void add_blinker(int row_off, int col_off);
    void add_toad(int row_off, int col_off);
    void add_pentadecathlon(int row_off, int col_off);
    void add_pulsar(int row_off, int col_off);
    void add_gosper_glider_gun();

    //getters
    int get_rows() const;
    int get_cols() const;
    bool **get_current() const;

    //overload
    friend std::ostream &operator<<(std::ostream &os, const GameOfLife &gol);
private:
    //private variables
    bool **current;
    bool **next;
    int rows;
    int cols;

    //check (row,col) if next is alive or dead
    bool alive_in_next_generation(int row, int col);
};
//overload operator
std::ostream &operator<<(std::ostream &os, const GameOfLife &gol);
#endif
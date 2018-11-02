#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>

class GameOfLife {
public:
    explicit GameOfLife(int rows = 33, int cols = 44);

    ~GameOfLife();

    GameOfLife(const GameOfLife &other) = delete;
    GameOfLife(GameOfLife &&other) = delete;
    GameOfLife &operator=(const GameOfLife &other) = delete;
    GameOfLife &operator=(GameOfLife &&other) = delete;

    void simulate_step();

    void add_blinker(int row_off, int col_off);
    void add_toad(int row_off, int col_off);
    void add_pentadecathlon(int row_off, int col_off);
    void add_pulsar(int row_off, int col_off);
    void add_gosper_glider_gun();

    friend std::ostream &operator<<(std::ostream &os, const GameOfLife &gol);
private:
    bool **current;
    bool **next;

    bool alive_in_next_generation(int row, int col);
};

std::ostream &operator<<(std::ostream &os, const GameOfLife &gol);

#endif

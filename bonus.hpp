#pragma once
#include <config.hpp>
#include "Square.hpp"

class Bonus : public Square {
public:
    Bonus(float r, float g, float b, int type) : Square(r, g, b, type) {}
    virtual void useBonus(const int row, const int col,Square *grid[GRID_SIZE][GRID_SIZE])=0;
};

class PaintBonus : public Bonus {
public:
    PaintBonus(int type);
    void useBonus(const int row, const int col, Square *grid[GRID_SIZE][GRID_SIZE]);
};

class BombBonus : public Bonus {
public:
    BombBonus();
    void useBonus(const int row, const int col, Square *grid[GRID_SIZE][GRID_SIZE]);
};
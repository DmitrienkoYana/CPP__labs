#include <bonus.hpp>

PaintBonus::PaintBonus(int type) : Bonus(1.0f, 1.0f, 1.0f, type) {}

void PaintBonus::useBonus(const int row, const int col, Square *grid[GRID_SIZE][GRID_SIZE]) {
    int paintBonusBlock = 0;
    int rowPaint, colPaint;

    if (row < GRID_SIZE && dynamic_cast<Bonus*>(grid[row + 1][col]) == nullptr) {
        while (paintBonusBlock < 2) {
            rowPaint = row + rand() % 5 - 2;
            colPaint = col + rand() % 5 - 2;

            if (rowPaint >= 0 && rowPaint < GRID_SIZE && colPaint >= 0 && colPaint < GRID_SIZE && grid[rowPaint][colPaint]->type > 0) {
                grid[rowPaint][colPaint]->type = this->type; 
                grid[rowPaint][colPaint]->colorR = COLORS[this->type][0];
                grid[rowPaint][colPaint]->colorG = COLORS[this->type][1];
                grid[rowPaint][colPaint]->colorB = COLORS[this->type][2];
                paintBonusBlock++;
            }
        }
    }
}


BombBonus::BombBonus() : Bonus(1.0f, 0.5f, 1.0f, 101) {}

void BombBonus::useBonus(const int row, const int col, Square *grid[GRID_SIZE][GRID_SIZE]) {
    int BombBonusBlock = 0;

    while (BombBonusBlock < 5) {
        int i = rand() % GRID_SIZE;
        int j = rand() % GRID_SIZE;

        if (grid[i][j]->type > 0 && dynamic_cast<Bonus*>(grid[i][j]) == nullptr) {
            grid[i][j]->type = -grid[i][j]->type; 
            grid[i][j]->colorR = COLORS[0][0];
            grid[i][j]->colorG = COLORS[0][1];
            grid[i][j]->colorB = COLORS[0][2];
            
            BombBonusBlock++;
        }
    }
}


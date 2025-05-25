#pragma once
#include "Config.hpp"
#include "UnbreakableRectangle.hpp"
#include "BreakableRectangle.hpp"
#include "Ball.hpp"
#include "Platform.hpp"
#include "Bonus.hpp"

class ArkanoidField {
public:
    ArkanoidField();
    void newIterationArkanoidField();
    bool checkIfBallsEmpty();
    void MovePlatform(float dx);
    void setScore();
    ~ArkanoidField();
private:
    void renderGrid();
    void RenderScore();
    void checkCollisionBall();
    void checkCollisionBonus();
    std::vector<Rectangle*> RectangleVector;
    std::vector<Ball*> ballsVector;
    std::vector<Bonus*> bonuses;
    Platform *platform;
    int score;
};

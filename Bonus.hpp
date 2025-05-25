#pragma once 
#include "Config.hpp"
#include "Ball.hpp"

class Bonus {
public:
    Bonus(float x, float y);
    void update();
    void render();
    float getX();
    float getY();
    virtual void useBonus(std::vector<Ball*>& Balls) = 0;

protected:
    float x;
    float y;
    float red;
    float green;
    float blue;
};

class AddBall : public Bonus {
public:
    AddBall(float x, float y);
    void useBonus(std::vector<Ball*>& Balls);
};

class SpeedUp : public Bonus {
public:
    SpeedUp(float x, float y);
    void useBonus(std::vector<Ball*>& Balls);
};

class Bottom: public Bonus {
public:
    Bottom(float x, float y);
    void useBonus(std::vector<Ball*>& Balls);
};

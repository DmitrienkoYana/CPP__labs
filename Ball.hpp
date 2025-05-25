#pragma once
#include "Config.hpp"

class Ball {
public:
    Ball();
    void render();
    void update();
    float getX();
    float getY();
    float getDirX() const;
    float getDirY() const;
    void setDirection(float newDirX, float newDirY);
    void activateBonusSpeed();
    void activateBonusBottom();
private:
    static int bonusBottom;
    int speedBoost;
    float x;
    float y;
    float directionX;
    float directionY;
    float red;
    float green;
    float blue;
};
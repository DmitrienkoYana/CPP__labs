#pragma once
#include "Config.hpp"
#include "Rectangle.hpp"
#include "ArkanoidField.hpp"

class BreakableRectangle : public Rectangle {
protected:
    int hp;
public:
    BreakableRectangle(float x, float y, int hp);
    bool Collision(Ball* ball);
    void SetColor();
};
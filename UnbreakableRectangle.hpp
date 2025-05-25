#pragma once
#include "Config.hpp"
#include "Rectangle.hpp"

class UnbreakableRectangle : public Rectangle {
protected:
public:
    UnbreakableRectangle(float x, float y, float width, float height);
    bool Collision(Ball* ball);
};

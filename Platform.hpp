#pragma once
#include "Config.hpp"
#include "Rectangle.hpp"


class Platform : public Rectangle {
protected:
public:
    Platform();
    void MovePlatform(float dx);
    virtual bool Collision(Ball* ball);
};

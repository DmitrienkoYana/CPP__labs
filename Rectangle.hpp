#pragma once
#include "Config.hpp"
#include "Ball.hpp"

class Rectangle {
protected:
    float posX, posY;
    float width, height;  
    float red;
    float green;
    float blue;
    bool checkCollision(Ball* ball);
public:
    Rectangle(float x, float y, float width, float height) : posX(x), posY(y), width(width), height(height) {}

    void render();

    float getX() const { return posX; }
    float getY() const { return posY; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    virtual bool Collision(Ball* ball) = 0;
};




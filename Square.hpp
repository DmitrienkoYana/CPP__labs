#pragma once

class Square {
public:
    float colorR;
    float colorG;
    float colorB;  
    int type; 

    Square(float r, float g, float b, int type) {
        this->colorR = r;
        this->colorG = g;
        this->colorB = b;
        this->type = type;
    }
    virtual ~Square() {};

    Square& operator=(const Square& other) {
        if (this != &other) {
            colorR = other.colorR;
            colorG = other.colorG;
            colorB = other.colorB;
            type = other.type;
        }
        return *this;
    }
};
#include <GLFW/glfw3.h>
#include "stb_easy_font.h"
#include <iostream>
#include <vector>
#include <cmath>
#pragma once

class ArkanoidField; 
extern ArkanoidField* arkanoidField;

extern GLFWwindow* window;

const float PI = 3.14159265359f;
const int WIDTH = 600;
const int HEIGHT = 600;
const int GRIDSIZE = 51; 

const float BALLSPEED = 0.01f;
const float BALLRADIUS = 0.015f;


const float SIZEPLATFORM = 0.5f;
const float SPEEDPLATFORM = 0.1f;

const float BONUSRADIUS = 0.015f;
const float SPEEDBONUS = 0.01f;
const float SPEEDBOOSTFACTOR = 1.1f;

const float BreakableRectColors[3][3] = {
    {1.0f, 0.0f, 0.0f}, 
    {0.0f, 1.0f, 0.0f}, 
    {0.0f, 0.0f, 1.0f},
};

const float BonusColors[3][3] = {
    {1.0f, 0.0f, 0.0f}, 
    {0.0f, 1.0f, 0.0f}, 
    {0.0f, 0.0f, 1.0f},
};

const float UnbreakableRectColors[3] = {1.0f, 1.0f, 1.0f};

const float PlatformColors[3] = {0.75f, 0.75f, 0.75f};




#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>


extern GLFWwindow* window;
class GameGrid;
extern GameGrid* Game;

const int WIDTH = 800;
const int HEIGHT = 600;
const int GRID_SIZE = 20; 

const int NUMCOLORS = 25;
const float COLORS[NUMCOLORS][3] = {
    { 0.0, 0.0, 0.0 },
    { 0.0, 0.0, 0.5 },
    { 0.0, 0.0, 1.0 },
    { 0.0, 0.5, 0.0 },
    { 0.0, 0.5, 0.5 },
    { 0.0, 0.5, 1.0 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 1.0, 0.5 },
    { 0.0, 1.0, 1.0 },
    { 0.5, 0.0, 0.0 },
    { 0.5, 0.0, 0.5 },
    { 0.5, 0.0, 1.0 },
    { 0.5, 0.5, 0.0 },
    { 0.5, 0.5, 0.5 },
    { 0.5, 0.5, 1.0 },
    { 0.5, 1.0, 0.0 },
    { 0.5, 1.0, 0.5 },
    { 0.5, 1.0, 1.0 },
    { 1.0, 0.0, 0.0 },
    { 1.0, 0.0, 0.5 },
    { 1.0, 0.0, 1.0 },
    { 1.0, 0.5, 0.0 },
    { 1.0, 0.5, 0.5 },
    { 1.0, 0.5, 1.0 },
    { 1.0, 1.0, 0.0 },
};


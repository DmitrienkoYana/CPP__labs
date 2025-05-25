#pragma once
#include "Config.hpp"
#include "ArkanoidField.hpp"

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_A)
    {
        if ( action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            arkanoidField->MovePlatform(-SPEEDPLATFORM);
        }
    }
    else if (key == GLFW_KEY_D)
    {
        if ( action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            arkanoidField->MovePlatform(SPEEDPLATFORM);
        }
    }else if (key == GLFW_KEY_R)
    {
        if ( action == GLFW_PRESS)
        {
            delete arkanoidField;
            arkanoidField = new ArkanoidField();
        }
    }
}
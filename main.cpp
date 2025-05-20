#include <GameGrid.hpp>

GLFWwindow* window;
GameGrid* Game = new GameGrid;

int prevRow = -1, prevCol = -1;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        int row = static_cast<int>(ypos * GRID_SIZE / HEIGHT);
        int col = static_cast<int>(xpos * GRID_SIZE / WIDTH);
        if ((prevRow != -1 && prevCol != -1) && 
        (abs(prevRow-row) <= 1 && abs(prevCol - col) <= 1 
        && !(abs(prevRow-row) == 1 && abs(prevCol - col) == 1))) {
            
            Game->swap(prevRow, prevCol, row, col);
            prevRow = -1;
            prevCol = -1;
        }
        else{
            prevRow = row;
            prevCol = col;
        }
    }
}

int main() {
	
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "game", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_button_callback);


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        Game->Render();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    delete Game;
    glfwTerminate();
    return 0;
}

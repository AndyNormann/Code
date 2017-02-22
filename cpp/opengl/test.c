#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int POINT_SIZE = 20;

const int WINDOW_X = (SCREEN_WIDTH) / (POINT_SIZE);
const int WINDOW_Y = (SCREEN_HEIGHT) / (POINT_SIZE);

typedef struct Vertex2f {
    GLfloat x;
    GLfloat y;
} Vertex2f;

int main() {
    GLFWwindow *window;

    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "yoyohvaskjera", NULL,
            NULL);

    if (!window) {
        glfwTerminate();
        return -2;
    }

    glfwMakeContextCurrent(window);

    Vertex2f grid[WINDOW_X * WINDOW_Y];

    int i, j;
    for (i = 0; i < WINDOW_X; i++) {
        for (j = 0; j < WINDOW_Y; j++) {
            grid[(WINDOW_X * j) + i].x = ((POINT_SIZE)*i) + (POINT_SIZE / 2);
            grid[(WINDOW_X * j) + i].y = ((POINT_SIZE)*j) + (POINT_SIZE / 2);
        }
    }

    /* glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(POINT_SIZE);

    /* Main Loop */

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, grid);
        glDrawArrays(GL_POINTS, 0, WINDOW_X * WINDOW_Y);

        glDisableClientState(GL_VERTEX_ARRAY);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Cleanup */

    glfwTerminate();
    return 0;
}

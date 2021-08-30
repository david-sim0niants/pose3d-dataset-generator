#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>


#include "window.h"
#include "pose3d.h"


int main()
{
    if (!glfwInit())
        return 1;
    set_Window_hints(4, false);
    GLFWwindow *window = create_Window(1280, 768, "");

    if (glewInit() != GLEW_OK)
    {
        return 1;
    }

    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        GLint width, height;
        glfwGetWindowSize(window, &width, &height);
        glViewport(0, 0, width, height);
        

        

        glfwSwapBuffers(window);
        glfwPollEvents();
    } 
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glfwTerminate();
}

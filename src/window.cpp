#include "window.h"



void set_Window_hints(int samples, bool hidden)
{
    glfwWindowHint(GLFW_SAMPLES, samples);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    glfwWindowHint(GLFW_VISIBLE, !hidden);
}


GLFWwindow* create_Window(GLuint width, GLuint height, const char *title, bool make_current_context)
{
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);     
    if (make_current_context && window)
        glfwMakeContextCurrent(window); 
    return window;
}

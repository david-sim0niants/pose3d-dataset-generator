#pragma once

#include <GLFW/glfw3.h>

// some window stuff
void set_Window_hints(int samples, bool hidden);
// it says what it does
GLFWwindow* create_Window(GLuint width, GLuint height, const char *title, bool make_current_context=true);

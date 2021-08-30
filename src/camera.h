#pragma once

#include <glm/gtc/matrix_transform.hpp>



struct Camera
{
    glm::mat4 view_matrix;
    float FOV = 60;
};

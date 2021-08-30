#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


class Pose
{
public:
    const char *name;
    glm::mat4 transformation;
    Pose *parent = NULL;
    std::vector<Pose> children;

    void render(glm::mat4 MVP);
};


template<unsigned short num_verts = 15>
void render_Pose(Pose &pose, glm::mat4 MVP);


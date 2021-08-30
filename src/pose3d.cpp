#include "pose3d.h"
#include "shader.h"



template<unsigned short num_verts = 15>
struct Bone_mesh 
{
    glm::vec3 vertices[num_verts + 1];
    GL_UNSIGNED_SHORT triangles[num_verts * 6]
};

template<unsigned short num_verts = 15>
Pose_mesh generate_Bone_mesh(glm::vec3 begin, glm::vec3 end)
{
    Bone_mesh<num_verts> mesh;

    glm::quat rotation = glm::lookAt(begin, end, glm::vec3(0.0, 1.0, 0.0));
    float angle_step = 2 * glm::pi<float> / num_verts;
    float angle = 0;

    mesh.vertices[num_verts - 1] = end;

    for (size_t i = 0; i < num_verts; i++)
    {
        mesh.vertices[i] = rotation * glm::vec4(glm::cos(angle), glm::sin(angle), 0, 1);
        angle += angle_step;

        unsigned int elem_i = i * 6;
        mesh.triangles[elem_i] = 0;
        mesh.triangles[elem_i + 1] = i + 1;
        mesh.triangles[elem_i + 2] = i + 2;
        mesh.triangles[elem_i + 3] = i;
        mesh.triangles[elem_i + 4] = i + 1;
        mesh.triangles[elem_i + 5] = num_elems - 1;
    }
}

static GLuint bone_shader_ProgramID;
static bool bone_shader_available = false;
static const char *shader_fp = "../shader/bone.glsl";


template<unsigned short num_verts = 15>
void render_Pose(Pose& pose, glm::mat4 MVP)
{
    if (bone_shader_available)
        glUseProgram(bone_shader_ProgramID);
    else
    {
        GLuint shaderID;
        load_Shader(shader_fp, GL_VERTEX_SHADER, shaderID, 
    }
    MVP * pose.transformation;
}

#pragma once

#include <GL/glew.h>

#include <string>
#include <vector>


// load and create a shader
bool load_Shader(const char *fp, GLenum type, GLuint &shaderID, std::string *compile_output=NULL); 
// load into an existing shader (tbh idk where or when will I need this)
bool load_into_Shader(const char *fp, GLuint shaderID, std::string *compile_output=NULL);
// write source to an existing shader 
bool Shader_source(GLuint shaderID, const char *shader_code, std::string *compile_output=NULL);
// builds program of mostly two shaders - vertex and fragment
bool build_Shader_program(GLuint *shaders, size_t num_shaders, GLuint &programID, std::string *link_output=NULL);


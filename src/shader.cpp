#include "shader.h"
#include <sstream>
#include <fstream>



bool load_Shader(const char *fp, GLenum type, GLuint &shaderID, std::string *compile_output)
{
    std::ifstream fs = std::ifstream(fp, std::ios::in);
    std::string shader_code;

    if (fs.is_open())
    {
        std::stringstream ss;
        ss << fs.rdbuf();
        shader_code = ss.str();
        fs.close();
    }
    else return false;

    shaderID = glCreateShader(type);
    return Shader_source(shaderID, shader_code.c_str(), compile_output);
}


bool load_into_Shader(const char *fp, GLuint shaderID, std::string *compile_output)
{
    std::ifstream fs = std::ifstream(fp, std::ios::in);
    std::string shader_code;

    if (fs.is_open())
    {
        std::stringstream ss;
        ss << fs.rdbuf();
        shader_code = ss.str();
        fs.close();
    }
    else return false;

    return Shader_source(shaderID, shader_code.c_str(), compile_output);
}


bool Shader_source(GLuint shaderID, const char *shader_code, std::string *compile_output)
{
    glShaderSource(shaderID, 1, &shader_code, NULL);
    glCompileShader(shaderID);

    GLint compiled = GL_FALSE;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);  

    if (compile_output)
    {
        int info_log_length;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &info_log_length);
        
        size_t size = compile_output->size();
        compile_output->resize(size + info_log_length);
        glGetShaderInfoLog(shaderID, info_log_length, NULL, (GLchar *)compile_output->c_str() + size);
    }

    return compiled;
}


bool build_Shader_program(GLuint *shaders, size_t num_shaders, GLuint &programID, std::string *link_output)
{
    programID = glCreateProgram();

    for (size_t i = 0; i < num_shaders; i++)
        glAttachShader(programID, shaders[i]);

    glLinkProgram(programID);

    GLint linked = GL_FALSE;
    glGetProgramiv(programID, GL_LINK_STATUS, &linked);  

    if (link_output)
    {
        int info_log_length;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &info_log_length);
        
        size_t size = link_output->size();
        link_output->resize(size + info_log_length);
        glGetProgramInfoLog(programID, info_log_length, NULL, (GLchar *)link_output->c_str() + size);
    }

    
    for (size_t i = 0; i < num_shaders; i++)
        glDetachShader(programID, shaders[i]); 
    
    return linked;
}

#type vertex
#version 430


layout(location=0) in vec3 vertex;

uniform mat4 transformation;
uniform vec4 color;


out vec4 f_color;


void main()
{
    f_color = color;
    gl_Position = transformation * vec4(vertex);
}


#type fragment

in vec4 f_color;

void main()
{
    gl_Color = f_color;
}

#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 m_matrix = mat4(1.0);

out DATA{
	vec4 position;
	vec4 color;

}vs_out;

out vec4 pos;


void main()
{
   gl_Position = pr_matrix * vw_matrix * m_matrix *  position;
   vs_out.position = m_matrix * position;
   vs_out.color = color;

}
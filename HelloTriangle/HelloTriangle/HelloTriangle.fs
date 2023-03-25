//Códifo fonte do Fragment Shader (em GLSL): ainda hardcoded
#version 460

in vec4 finalColor;
out vec4 color;

void main()
{
	color = finalColor;
};
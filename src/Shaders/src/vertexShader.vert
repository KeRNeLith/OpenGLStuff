#version 130

uniform mat4 matrixMVP;

void main(void)
{
	// Position du sommet après projection
	gl_Position = matrixMVP * gl_Vertex;

	// Définition de la couleur au sommet
	gl_FrontColor = gl_Color;
}

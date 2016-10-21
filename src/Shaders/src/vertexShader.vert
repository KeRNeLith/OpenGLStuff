#version 130

void main(void)
{
	// Position du sommet après projection
	gl_Position = gl_Vertex;

	// Définition de la couleur au sommet
        gl_FrontColor = gl_Color;
}

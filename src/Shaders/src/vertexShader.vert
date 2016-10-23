#version 130

uniform mat4 matrixMVP;

// Position du sommet
in vec3 position;

void main(void)
{
	// Position du sommet après projection
        gl_Position = matrixMVP * vec4(position, 1.0);

	// Définition de la couleur au sommet
	gl_FrontColor = gl_Color;
}

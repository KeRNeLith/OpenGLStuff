#version 330

uniform mat4 matrixP;
uniform mat4 matrixV;
uniform mat4 matrixM;

// Position du sommet
in vec3 position;
in vec3 normalIn;

out vec3 normal;
out vec3 color;

void main(void)
{
	// Position du sommet après projection
	gl_Position = matrixP * matrixV * matrixM * vec4(position, 1.0);

        // Pour le fragment shader
        color = vec3(1.0, 1.0, 1.0);
        normal = normalIn;
}

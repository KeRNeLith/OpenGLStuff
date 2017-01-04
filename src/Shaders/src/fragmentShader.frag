#version 330

in vec3 normalOut;
in vec3 color;

out vec4 colorOut;

void main(void)
{
        // Couleur
        colorOut = vec4(color, 1.0);
}

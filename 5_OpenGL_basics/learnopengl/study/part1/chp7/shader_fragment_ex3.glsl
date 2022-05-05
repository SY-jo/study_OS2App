#version 440 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D myTexture1;
uniform sampler2D myTexture2;
uniform vec2 move;

void main()
{
    FragColor = mix(texture(myTexture1, TexCoord+move), texture(myTexture2, TexCoord+move), 0.5);
}

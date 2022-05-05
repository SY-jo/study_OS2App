#version 440 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D myTexture1;
uniform sampler2D myTexture2;


void main()
{
    vec2 TexCoord_reversed = vec2(1.0 - TexCoord.x, TexCoord.y);
    FragColor = mix(texture(myTexture1, TexCoord), texture(myTexture2, TexCoord_reversed), 0.5);
}

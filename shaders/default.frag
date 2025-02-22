#version 330 core

out vec4 FragColor;

in vec3 color;
in vec2 texCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
   FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}

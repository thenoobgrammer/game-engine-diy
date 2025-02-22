#version 330 core

out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
   vec4 brickColor = texture(tex0, texCoord);
   vec4 smileyFaceColor = texture(tex1, texCoord);

   FragColor = mix(brickColor, smileyFaceColor, 0.2);
}
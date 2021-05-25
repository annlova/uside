#version 460

uniform vec4 uniColor;

out vec4 color;

void main() {
    color = vec4(uniColor.r, 0.0f, 0.5f, 1.0f);
}
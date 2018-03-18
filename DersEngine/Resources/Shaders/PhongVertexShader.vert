#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 textureCoord;

out VS_Data
{
	vec4 worldPosition;
	vec3 normal;
	vec2 textureCoord;
	vec3 cameraViewDirection;
} vs_out;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
	vec4 worldPosition = modelMatrix * vec4(position, 1);

	vs_out.worldPosition = worldPosition;
	vs_out.normal = normal;
	vs_out.textureCoord = textureCoord;
	vs_out.cameraViewDirection = (normalize((inverse(viewMatrix) * vec4(0.0, 0.0, 0.0, 1.0)) - worldPosition)).xyz;
	
	gl_Position = projectionMatrix * viewMatrix * worldPosition;
}
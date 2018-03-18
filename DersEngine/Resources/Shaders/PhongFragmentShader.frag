#version 330 core

layout (location = 0) out vec4 fragColor;

in VS_Data
{
	vec4 worldPosition;
	vec3 normal;
	vec2 textureCoord;
	vec3 cameraViewDirection;
} fs_in;

struct Material
{
	sampler2D diffuseMap;
	sampler2D specularMap;
	//sampler2D metallicMap;	
	//sampler2D roughnessMap;
	//sampler2D normalMap;
	//sampler2D ambientOcclusionMap;

	vec3 emissiveColor;
	float shininess;
};

struct DirectionalLight
{
	vec3 ambientLight;
	vec3 diffuseLight;
	vec3 specularLight;
	vec3 direction;
};

uniform DirectionalLight light;
uniform Material material;

vec4 calculateDiffuseLight(vec4 diffuseMapSample, vec3 normal, vec3 lightDirection, vec3 diffuseLight)
{
	float diffuseFactor = max(dot(normal, lightDirection), 0.0);
	return vec4(diffuseLight, 1.0) * diffuseFactor * diffuseMapSample;
}

vec4 calculateSpecularLight(vec4 specularMapSample, vec3 normal, vec3 viewDirection, vec3 lightDirection, vec3 specularLight)
{
	vec3 halfwayDirection = normalize(lightDirection + viewDirection);
	float normalizationFactor = (material.shininess + 2.0) / 8.0;
	float specularFactor = pow(max(dot(normal, halfwayDirection), 0.0), material.shininess) * normalizationFactor;
	return vec4(specularLight, 1.0) * specularFactor * specularMapSample;
}

void main()
{
	vec2 texCoord 	   = fs_in.textureCoord;
	vec3 normal 	   = fs_in.normal;
	vec3 viewDirection = fs_in.cameraViewDirection;

	vec4 diffuseMapSample  = texture2D(material.diffuseMap, texCoord);
	vec4 specularMapSample = texture2D(material.specularMap, texCoord);

	vec4 ambientLight  = vec4(light.ambientLight, 1.0) * diffuseMapSample;
	vec4 diffuseLight  = calculateDiffuseLight(diffuseMapSample, normal, light.direction, light.diffuseLight);
	vec4 specularLight = calculateSpecularLight(specularMapSample, normal, viewDirection, light.direction, light.specularLight);
	vec4 emissiveLight = vec4(material.emissiveColor, 1.0) * diffuseMapSample;

	fragColor = ambientLight + diffuseLight + specularLight + emissiveLight;
}
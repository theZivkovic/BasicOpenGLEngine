
attribute vec4 vPosition;
attribute vec4 vNormal;

uniform vec4 vColor;
uniform mat4 camera;
varying vec4 transferColor;

uniform vec4 lPosition;
uniform vec4 lAmbient;
uniform vec4 lDiffuse;
uniform vec4 lSpecular;

uniform vec3 cPosition;

void main()
{
	vec4 L = normalize(lPosition - vPosition);
	float diffuseCo =  max(dot(L, vNormal), 0);
	
	vec4 R = normalize(2.0 * dot(vNormal, L) * vNormal  - L); 

	vec4 V = normalize(vec4(cPosition, 1.0) - vPosition);

	float specularCo = pow(max(0, dot(R, V)), 5.0);

	gl_Position = camera * vPosition;
	transferColor = vColor + lAmbient + diffuseCo * lDiffuse + specularCo * lSpecular;
}
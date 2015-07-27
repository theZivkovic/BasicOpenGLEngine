
attribute vec4 vPosition;
attribute vec4 vNormal;

uniform vec4 vColor;
uniform mat4 camera;
uniform vec4 lightPosition;
varying vec4 transferColor;

void main()
{
	vec4 toLight = normalize(lightPosition - vPosition);

	float diffuseCo = dot(vNormal, toLight);

	gl_Position = camera * vPosition;
	transferColor = vColor + diffuseCo * vec4(0.5, 0.5, 0.5, 1.0);
}
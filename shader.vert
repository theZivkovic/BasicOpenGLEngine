attribute vec4 vPosition;
uniform vec4 vColor;
varying vec4 transferColor;

void main()
{
	gl_Position = vPosition;
	transferColor = vColor;
}
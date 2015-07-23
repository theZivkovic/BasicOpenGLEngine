#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <GL/glew.h>
#include <GL/glut.h>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private:
	GLuint _ID;
	GLuint _type;
	char* readFromFile(const char* filename);
public:

	Shader(GLuint type);
	int compileFrom(const char* filename);
	void print_log();
	GLuint getID();

	~Shader();
};
#endif
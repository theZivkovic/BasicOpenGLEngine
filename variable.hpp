#ifndef __VARIABLE_HPP__
#define __VARIABLE_HPP__

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>


enum VariableType { ATTRIBUTE, UNIFORM };

class Variable
{
private:
	GLint _ID;
	const char* _name;
	VariableType _type;

public:
	Variable(const char* name, VariableType type, GLuint programID);
	bool isValid();
	std::string getType();
	GLuint getID();
};
#endif
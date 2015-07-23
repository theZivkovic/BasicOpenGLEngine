#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__


#include <cstdlib>
#include <iostream>
#include <unordered_map>

#include "variable.hpp"
#include "shader.hpp"

class Program
{
private:
	GLuint _ID;
	std::unordered_map<std::string, GLuint> _variables;
public:
	Program(const char* vertFile, const char* fragFile);
	
	GLuint getID();
	void print_log();

	void addVariable(const char* name, VariableType type);
	GLuint getVariableID(const char* name);
};
#endif
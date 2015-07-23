#include "variable.hpp"

Variable::Variable(const char* name, VariableType type, GLuint programID)
{
	_name = name;
	_type = type;

	switch(type)
	{
		case ATTRIBUTE:
		{
			_ID = glGetAttribLocation(programID, _name);
		     break;
		}
		case UNIFORM:
		{
			_ID = glGetUniformLocation(programID, _name); 
		     break;
		 }
		default: _ID = -1; break;	
	}
}

bool Variable::isValid()
{
	return _ID != -1;
}
std::string Variable::getType()
{
	switch(_type)
	{
		case ATTRIBUTE: return "attibute";
		case UNIFORM: return "uniform";
		default: return "???";
	}
}
GLuint Variable::getID()
{
	return _ID;
}
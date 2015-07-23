#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>
#include <memory>

#include "configuration.hpp"
#include "program.hpp"
#include "variable.hpp"

using namespace std;

unique_ptr<Program> program;

GLfloat vertices[] = { -0.5, -0.5,
					    0.5, -0.5,
					    0.5,  0.5,
					   -0.5,  0.5 };

GLuint vertID;

void initializeResources()
{
	program = unique_ptr<Program>(new Program("shader.vert", "shader.frag"));

	program->addVariable("vPosition", VariableType::ATTRIBUTE);
	program->addVariable("vColor"	, VariableType::UNIFORM);

	glGenBuffers(1, &vertID);
	glBindBuffer(GL_ARRAY_BUFFER, vertID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void onDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(program->getID());

	glEnableVertexAttribArray(program->getVariableID("vPosition"));
	glBindBuffer(GL_ARRAY_BUFFER, vertID);

	glVertexAttribPointer(
        program->getVariableID("vPosition"),
        2,                     
        GL_FLOAT,              
        GL_FALSE,              
        0,                     
        0                 
    );

	glUniform4f(program->getVariableID("vColor"), 1.0f, 1.0f, 0.0f, 1.0f);

    glDrawArrays(GL_QUADS,0 ,4);
	glDisableVertexAttribArray(program->getVariableID("vPosition"));

	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(Configuration::window_width, Configuration::window_height);
	glutCreateWindow(Configuration::program_name);

	if (glewInit() != GLEW_OK)
	{
		cerr << "You must have OpenGL 2.0 version (or higher)!" << endl;
		exit(EXIT_FAILURE);
	}

	initializeResources();

	glutDisplayFunc(onDisplay);

	glutMainLoop();
	return 0;
}
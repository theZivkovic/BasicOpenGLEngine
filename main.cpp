#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>
#include <memory>

#include "configuration.hpp"
#include "program.hpp"
#include "variable.hpp"
#include "sphere_mesh.hpp"
#include "triangle_mesh.hpp"

using namespace std;

unique_ptr < Program > program;
unique_ptr < TriangleMesh > triangle;
unique_ptr < SphereMesh > sphere;

void initializeResources()
{
    program =
        unique_ptr < Program > (new Program("shader.vert", "shader.frag"));

    program->addVariable("vPosition", VariableType::ATTRIBUTE);
    program->addVariable("vColor", VariableType::UNIFORM);

    triangle = unique_ptr < TriangleMesh > (new TriangleMesh());
    triangle->initializeBuffers();

    sphere = unique_ptr < SphereMesh > (new SphereMesh(0.5, 20, 20));
    sphere->initializeBuffers();

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void onDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(program->getID());

    triangle->draw(program, glm::vec4(1.0, 0.0, 0.0, 1.0));
    sphere->draw(program, glm::vec4(0.0, 1.0, 0.0, 1.0));

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(Configuration::window_width,
                       Configuration::window_height);
    glutCreateWindow(Configuration::program_name);

    if (glewInit() != GLEW_OK) {
        cerr << "You must have OpenGL 2.0 version (or higher)!" << endl;
        exit(EXIT_FAILURE);
    }

    initializeResources();

    glutDisplayFunc(onDisplay);

    glutMainLoop();
    return 0;
}

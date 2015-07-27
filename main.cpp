
#define degreesToRadians(x) x*(3.141592f/180.0f)
#define GLM_FORCE_RADIANS

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cstdlib>
#include <memory>

#include "configuration.hpp"
#include "program.hpp"
#include "variable.hpp"
#include "sphere_mesh.hpp"
#include "triangle_mesh.hpp"
#include "camera.hpp"
#include "light.hpp"

using namespace std;

unique_ptr < Program > program;
unique_ptr < SphereMesh > sphere;
unique_ptr < Camera > camera;
unique_ptr < Light > light;

void initializeResources()
{
    program =
        unique_ptr < Program > (new Program("shader.vert", "shader.frag"));

    camera = unique_ptr < Camera > (new Camera());

    program->addVariable("vPosition", VariableType::ATTRIBUTE);
    program->addVariable("vColor", VariableType::UNIFORM);
    program->addVariable("camera", VariableType::UNIFORM);
    program->addVariable("vNormal", VariableType::ATTRIBUTE);
    program->addVariable("lightPosition", VariableType::UNIFORM);

    light = unique_ptr < Light > (new Light());
    light->setPosition(glm::vec4(10, 10, 10, 1));
    light->initializeInProgram(program);

    sphere = unique_ptr < SphereMesh > (new SphereMesh(0.5, 50, 50));
    sphere->initializeBuffers();


    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}

void onDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(program->getID());

    // set light and write a code to use it in shader too

    glUniformMatrix4fv(program->getVariableID("camera"), 1, false,
                       glm::value_ptr(camera->matrix()));

    sphere->draw(program, glm::vec4(0.0, 0.5, 0.0, 1.0));

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

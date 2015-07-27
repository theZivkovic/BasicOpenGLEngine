#include "light.hpp"

Light::Light()
{
    _ambient = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f);
    _diffuse = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
    _specular = glm::vec4(0.7f, 0.7f, 0.7f, 1.0f);
}

Light::Light(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
{
    _ambient = ambient;
    _diffuse = diffuse;
    _specular = specular;
}

void Light::initializeInProgram(std::unique_ptr < Program > &program)
{
    program->addVariable("lAmbient", UNIFORM);
    program->addVariable("lDiffuse", UNIFORM);
    program->addVariable("lSpecular", UNIFORM);
    program->addVariable("lPosition", UNIFORM);
}

void Light::applyInProgram(std::unique_ptr < Program > &program)
{
    glUniform4fv(program->getVariableID("lAmbient"), 1,
                 glm::value_ptr(_ambient));
    glUniform4fv(program->getVariableID("lDiffuse"), 1,
                 glm::value_ptr(_diffuse));
    glUniform4fv(program->getVariableID("lSpecular"), 1,
                 glm::value_ptr(_specular));
    glUniform4fv(program->getVariableID("lPosition"), 1,
                 glm::value_ptr(_position));
}

void Light::setPosition(glm::vec4 && position)
{
    _position = position;
}

Light::~Light()
{

}

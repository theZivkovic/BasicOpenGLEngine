#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#define GLM_FORCE_RADIANS

#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include "program.hpp"

class Light {
  private:
    glm::vec4 _position;
    glm::vec4 _ambient;
    glm::vec4 _diffuse;
    glm::vec4 _specular;
  public:
    Light();
    Light(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular);

    void initializeInProgram(std::unique_ptr < Program > &program);
    void applyInProgram(std::unique_ptr < Program > &program);
    void setPosition(glm::vec4 && position);
    ~Light();
};
#endif

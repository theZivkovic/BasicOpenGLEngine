#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glut.h>

class Camera {
  private:
    glm::mat4 _perspective;
    glm::mat4 _orientation;
    glm::vec3 _position;
  public:
};
#endif

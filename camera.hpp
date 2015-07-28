#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__


#define degreesToRadians(x) x*(3.141592f/180.0f)
#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include <memory>

#include "program.hpp"

class Camera {
  private:
    glm::vec3 _position;
    GLfloat _horizontalAngle;
    GLfloat _verticalAngle;
    GLfloat _fieldOfView;
    GLfloat _nearPlane;
    GLfloat _farPlane;
    GLfloat _viewportAspectRatio;
  public:
     Camera();
    void setPerspective(GLfloat fieldOfView, GLfloat aspectRatio,
                        GLfloat nearPlane, GLfloat farPlane);
    void lookAt(glm::vec3 target);
    glm::mat4 matrix();
    glm::mat4 orientation();
    glm::vec3 position();
    glm::vec3 forward();

    void rotateHorizontal(float dangle);
    void rotateVertical(float dangle);
    void zoom(float times);

    void initializeInProgram(std::unique_ptr < Program > &program);
    void applyInProgram(std::unique_ptr < Program > &program);

    ~Camera();
};
#endif

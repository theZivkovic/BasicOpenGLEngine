#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__


#define degreesToRadians(x) x*(3.141592f/180.0f)
#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <GL/glew.h>
#include <GL/glut.h>


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

    void rotateHorizontal(float dangle);
    void rotateVertical(float dangle);
    void zoom(float times);
    ~Camera();
};
#endif

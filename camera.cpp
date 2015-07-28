#include "camera.hpp"

Camera::Camera():_position(0.0f, 0.0f, 5.0f),
_horizontalAngle(0.0f),
_verticalAngle(0.0f),
_fieldOfView(50.0f),
_nearPlane(0.01f), _farPlane(100.0f), _viewportAspectRatio(4.0f / 3.0f)
{

}

void Camera::setPerspective(GLfloat fieldOfView, GLfloat aspectRatio,
                            GLfloat nearPlane, GLfloat farPlane)
{

}

void Camera::lookAt(glm::vec3 target)
{

}

glm::mat4 Camera::matrix()
{
    glm::mat4 camera =
        glm::perspective(_fieldOfView, _viewportAspectRatio, _nearPlane,
                         _farPlane);
    camera *= orientation();
    camera = glm::translate(camera, -_position);
    return camera;
}

glm::mat4 Camera::orientation()
{
    glm::mat4 orientation;
    orientation =
        glm::rotate(orientation, glm::radians(_verticalAngle),
                    glm::vec3(1, 0, 0));
    orientation =
        glm::rotate(orientation, glm::radians(_horizontalAngle),
                    glm::vec3(0, 1, 0));
    return orientation;
}

void Camera::rotateHorizontal(float dangle)
{
    _horizontalAngle += dangle;
}

void Camera::rotateVertical(float dangle)
{
    _verticalAngle += dangle;
}

void Camera::zoom(float times)
{
    _position *= times;
}
glm::vec3 Camera::position()
{
    return _position;
}
glm::vec3 Camera::forward()
{
    glm::vec4 forward = glm::inverse(orientation()) * glm::vec4(0,0,-1,1);
    return glm::vec3(forward);
}
void Camera::initializeInProgram(std::unique_ptr < Program > &program)
{
    program->addVariable("cPosition", VariableType::UNIFORM);
    program->addVariable("camera", VariableType::UNIFORM);
}
void Camera::applyInProgram(std::unique_ptr<Program>& program)
{
    glUniform3fv(program->getVariableID("cPosition"), 1, glm::value_ptr(_position));
    glUniformMatrix4fv(program->getVariableID("camera"), 1, false, glm::value_ptr(matrix()));
}

Camera::~Camera()
{

}

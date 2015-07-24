#include "sphere_mesh.hpp"

SphereMesh::SphereMesh(float r, int horizontals,
                       int verticals):Mesh(GL_TRIANGLE_STRIP, 3), _r(r),
_horizontals(horizontals), _verticals(verticals)
{
    _center = glm::vec3(0, 0, 0);
    _nVertices = _horizontals * _verticals;
}

void SphereMesh::initializeData()
{
    _vertices = new GLfloat[_nVertices * 3];

    GLfloat phi = 0;
    GLfloat dphi = 2.0 * M_PI / _verticals;
    GLfloat theta = -M_PI / 2.0;
    GLfloat dtheta = 2.0 * M_PI / _horizontals;

    for (int i = 0; i < _horizontals; i++) {

        phi = 0;

        for (int j = 0; j < _verticals; j++) {
            _vertices[3 * ((i * _horizontals) + j) + 0] =
                _center[0] + _r * cos(phi) * cos(theta);
            _vertices[3 * ((i * _horizontals) + j) + 1] =
                _center[2] + _r * sin(theta);
            _vertices[3 * ((i * _horizontals) + j) + 2] =
                _center[1] + _r * sin(phi) * cos(theta);

            phi += dphi;
        }

        theta += dtheta;
    }
    _normals = new GLfloat[_nVertices * 3];


}

SphereMesh::~SphereMesh()
{

}

#include "sphere_mesh.hpp"

SphereMesh::SphereMesh(float r, int horizontals,
                       int verticals):Mesh(GL_TRIANGLES, 3), _r(r),
_horizontals(horizontals), _verticals(verticals)
{
    _center = glm::vec3(0, 0, 0);
    _nVertices = _nNormals = _horizontals * _verticals * 6;
}

void SphereMesh::initializeData()
{
    _vertices = new GLfloat[_nVertices * _coordsPerVertex];
    _normals = new GLfloat[_nNormals * _coordsPerVertex];

    GLfloat phi = 0;
    GLfloat dphi = 2.0 * M_PI / _verticals;
    GLfloat theta = -M_PI;
    GLfloat dtheta = 2.0 * M_PI / _horizontals;

    for (int i = 0; i < _horizontals; i++) {

        phi = 0;

        for (int j = 0; j < _verticals; j++) {

            _vertices[18 * ((j * _horizontals) + i) + 0] =
                _center[0] + _r * cos(phi) * cos(theta);
            _vertices[18 * ((j * _horizontals) + i) + 1] =
                _center[2] + _r * sin(theta);
            _vertices[18 * ((j * _horizontals) + i) + 2] =
                -_center[1] - _r * sin(phi) * cos(theta);

            _vertices[18 * ((j * _horizontals) + i) + 3] =
                _center[0] + _r * cos(phi + dphi) * cos(theta);
            _vertices[18 * ((j * _horizontals) + i) + 4] =
                _center[2] + _r * sin(theta);
            _vertices[18 * ((j * _horizontals) + i) + 5] =
                -_center[1] - _r * sin(phi + dphi) * cos(theta);

            _vertices[18 * ((j * _horizontals) + i) + 6] =
                _center[0] + _r * cos(phi) * cos(theta + dtheta);
            _vertices[18 * ((j * _horizontals) + i) + 7] =
                _center[2] + _r * sin(theta + dtheta);
            _vertices[18 * ((j * _horizontals) + i) + 8] =
                -_center[1] - _r * sin(phi) * cos(theta + dtheta);

            _vertices[18 * ((j * _horizontals) + i) + 9] =
                _center[0] + _r * cos(phi) * cos(theta + dtheta);
            _vertices[18 * ((j * _horizontals) + i) + 10] =
                _center[2] + _r * sin(theta + dtheta);
            _vertices[18 * ((j * _horizontals) + i) + 11] =
                -_center[1] - _r * sin(phi) * cos(theta + dtheta);

            _vertices[18 * ((j * _horizontals) + i) + 12] =
                _center[0] + _r * cos(phi + dphi) * cos(theta);
            _vertices[18 * ((j * _horizontals) + i) + 13] =
                _center[2] + _r * sin(theta);
            _vertices[18 * ((j * _horizontals) + i) + 14] =
                -_center[1] - _r * sin(phi + dphi) * cos(theta);

            _vertices[18 * ((j * _horizontals) + i) + 15] =
                _center[0] + _r * cos(phi + dphi) * cos(theta + dtheta);
            _vertices[18 * ((j * _horizontals) + i) + 16] =
                _center[2] + _r * sin(theta + dtheta);
            _vertices[18 * ((j * _horizontals) + i) + 17] =
                -_center[1] - _r * sin(phi + dphi) * cos(theta + dtheta);


            _normals[18 * ((j * _horizontals) + i) + 0] =
                cos(phi) * cos(theta);
            _normals[18 * ((j * _horizontals) + i) + 1] =
                -sin(phi) * cos(theta);
            _normals[18 * ((j * _horizontals) + i) + 2] = sin(theta);

            _normals[18 * ((j * _horizontals) + i) + 3] =
                cos(phi + dphi) * cos(theta);
            _normals[18 * ((j * _horizontals) + i) + 4] =
                -sin(phi + dphi) * cos(theta);
            _normals[18 * ((j * _horizontals) + i) + 5] = sin(theta);

            _normals[18 * ((j * _horizontals) + i) + 6] =
                cos(phi) * cos(theta + dtheta);
            _normals[18 * ((j * _horizontals) + i) + 7] =
                -sin(phi) * cos(theta + dtheta);
            _normals[18 * ((j * _horizontals) + i) + 8] =
                sin(theta + dtheta);

            _normals[18 * ((j * _horizontals) + i) + 9] =
                cos(phi) * cos(theta + dtheta);
            _normals[18 * ((j * _horizontals) + i) + 10] =
                -sin(phi) * cos(theta + dtheta);
            _normals[18 * ((j * _horizontals) + i) + 11] =
                sin(theta + dtheta);

            _normals[18 * ((j * _horizontals) + i) + 12] =
                cos(phi + dphi) * cos(theta);
            _normals[18 * ((j * _horizontals) + i) + 13] =
                -sin(phi + dphi) * cos(theta);
            _normals[18 * ((j * _horizontals) + i) + 14] = sin(theta);

            _normals[18 * ((j * _horizontals) + i) + 15] =
                cos(phi + dphi) * cos(theta + dtheta);
            _normals[18 * ((j * _horizontals) + i) + 16] =
                -sin(phi + dphi) * cos(theta + dtheta);
            _normals[18 * ((j * _horizontals) + i) + 17] =
                sin(theta + dtheta);

            phi += dphi;
        }

        theta += dtheta;
    }


}

SphereMesh::~SphereMesh()
{

}

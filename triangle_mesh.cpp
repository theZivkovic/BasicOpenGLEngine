#include "triangle_mesh.hpp"

TriangleMesh::TriangleMesh():Mesh(GL_TRIANGLES, 2)
{
    _nVertices = 3;
}

void TriangleMesh::initializeData()
{
    _vertices = new GLfloat[6] {
    -0.5, -0.5, 0.5, -0.5, 0, 0.5};

}

TriangleMesh::~TriangleMesh()
{

}

#include "mesh.hpp"

Mesh::Mesh(GLenum howToDraw, int coordsPerVertex):_howToDraw(howToDraw),
_coordsPerVertex
(coordsPerVertex)
{

}

void Mesh::initializeBuffers()
{
    initializeData();

    glGenBuffers(1, &_vBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vBufferID);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(GL_FLOAT) * _nVertices * _coordsPerVertex,
                 _vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void Mesh::draw(std::unique_ptr < Program > &program, glm::vec4 color)
{
    glEnableVertexAttribArray(program->getVariableID("vPosition"));

    glBindBuffer(GL_ARRAY_BUFFER, _vBufferID);

    glVertexAttribPointer(program->getVariableID("vPosition"),
                          _coordsPerVertex, GL_FLOAT, GL_FALSE, 0, 0);

    glUniform4f(program->getVariableID("vColor"), color[0], color[1],
                color[2], color[3]);


    glDrawArrays(GL_TRIANGLES, 0, _nVertices * _coordsPerVertex);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(program->getVariableID("vPosition"));
}

Mesh::~Mesh()
{

}

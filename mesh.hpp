#ifndef __MESH_HPP__
#define __MESH_HPP__

#include <glm/glm.hpp>
#include <memory>
#include "program.hpp"

class Mesh {

  private:

    GLuint _vBufferID;
    GLuint _nBufferID;

  protected:

     GLfloat * _vertices;
    GLfloat *_normals;
    int _nVertices;
    int _nNormals;
    GLenum _howToDraw;
    int _coordsPerVertex;

  public:

     Mesh(GLenum howToDraw, int coordsPerVertes);
    virtual void initializeData() = 0;
    void initializeBuffers();
    void draw(std::unique_ptr < Program > &program, glm::vec4 color);
     virtual ~ Mesh();


};
#endif

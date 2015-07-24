#ifndef __TRIANGLE_MESH_HPP__
#define __TRIANGLE_MESH_HPP__

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <math.h>
#include "mesh.hpp"

class TriangleMesh:public Mesh {

  public:
    TriangleMesh();
    virtual void initializeData();
     virtual ~ TriangleMesh();
};
#endif

#ifndef __SPHERE_MESH_HPP__
#define __SPHERE_MESH_HPP__

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <math.h>
#include "mesh.hpp"

class SphereMesh:public Mesh {
  private:
    float _r;
    int _horizontals;
    int _verticals;
     glm::vec3 _center;
  public:
     SphereMesh(float r, int horizontals, int verticals);
    virtual void initializeData();
     virtual ~ SphereMesh();
};
#endif

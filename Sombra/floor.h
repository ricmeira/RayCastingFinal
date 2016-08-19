/*
created with obj2opengl.pl

source file    : ./floor.obj
vertices       : 4
faces          : 2
normals        : 1
texture coords : 0


// include generated arrays
#import "./floor.h"

// set input data to arrays
glVertexPointer(3, GL_FLOAT, 0, floorVerts);
glNormalPointer(GL_FLOAT, 0, floorNormals);

// draw data
glDrawArrays(GL_TRIANGLES, 0, floorNumVerts);
*/

unsigned int floorNumVerts = 6;

float floorVerts [] = {
  // f 2//1 4//1 3//1
  50, 0, 50,
  50, 0, -50,
  -50, 0, -50,
  // f 1//1 2//1 3//1
  -50, 0, 50,
  50, 0, 50,
  -50, 0, -50,
};

float floorNormals [] = {
  // f 2//1 4//1 3//1
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 1//1 2//1 3//1
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
};


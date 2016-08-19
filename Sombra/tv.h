/*
created with obj2opengl.pl

source file    : ./tv.obj
vertices       : 8
faces          : 12
normals        : 8
texture coords : 0


// include generated arrays
#import "./tv.h"

// set input data to arrays
glVertexPointer(3, GL_FLOAT, 0, tvVerts);
glNormalPointer(GL_FLOAT, 0, tvNormals);

// draw data
glDrawArrays(GL_TRIANGLES, 0, tvNumVerts);
*/

unsigned int tvNumVerts = 36;

float tvVerts [] = {
  // f 4//1 3//2 1//3
  0.0499999999999989, -0.649, -1.5,
  0.0499999999999989, 0.649, -1.5,
  0.0499999999999989, 0.649, 1.5,
  // f 8//4 7//5 3//2
  -0.0500000000000007, -0.649, -1.5,
  -0.0500000000000007, 0.649, -1.5,
  0.0499999999999989, 0.649, -1.5,
  // f 6//6 5//7 7//5
  -0.0500000000000007, -0.649, 1.5,
  -0.0500000000000007, 0.649, 1.5,
  -0.0500000000000007, 0.649, -1.5,
  // f 2//8 1//3 5//7
  0.0499999999999989, -0.649, 1.5,
  0.0499999999999989, 0.649, 1.5,
  -0.0500000000000007, 0.649, 1.5,
  // f 3//2 7//5 5//7
  0.0499999999999989, 0.649, -1.5,
  -0.0500000000000007, 0.649, -1.5,
  -0.0500000000000007, 0.649, 1.5,
  // f 8//4 4//1 2//8
  -0.0500000000000007, -0.649, -1.5,
  0.0499999999999989, -0.649, -1.5,
  0.0499999999999989, -0.649, 1.5,
  // f 2//8 4//1 1//3
  0.0499999999999989, -0.649, 1.5,
  0.0499999999999989, -0.649, -1.5,
  0.0499999999999989, 0.649, 1.5,
  // f 4//1 8//4 3//2
  0.0499999999999989, -0.649, -1.5,
  -0.0500000000000007, -0.649, -1.5,
  0.0499999999999989, 0.649, -1.5,
  // f 8//4 6//6 7//5
  -0.0500000000000007, -0.649, -1.5,
  -0.0500000000000007, -0.649, 1.5,
  -0.0500000000000007, 0.649, -1.5,
  // f 6//6 2//8 5//7
  -0.0500000000000007, -0.649, 1.5,
  0.0499999999999989, -0.649, 1.5,
  -0.0500000000000007, 0.649, 1.5,
  // f 1//3 3//2 5//7
  0.0499999999999989, 0.649, 1.5,
  0.0499999999999989, 0.649, -1.5,
  -0.0500000000000007, 0.649, 1.5,
  // f 6//6 8//4 2//8
  -0.0500000000000007, -0.649, 1.5,
  -0.0500000000000007, -0.649, -1.5,
  0.0499999999999989, -0.649, 1.5,
};

float tvNormals [] = {
  // f 4//1 3//2 1//3
  0.577350269189626, -0.577350269189626, -0.577350269189626,
  0.577350269189626, 0.577350269189626, -0.577350269189626,
  0.577350269189626, 0.577350269189626, 0.577350269189626,
  // f 8//4 7//5 3//2
  -0.577350269189626, -0.577350269189626, -0.577350269189626,
  -0.577350269189626, 0.577350269189626, -0.577350269189626,
  0.577350269189626, 0.577350269189626, -0.577350269189626,
  // f 6//6 5//7 7//5
  -0.577350269189626, -0.577350269189626, 0.577350269189626,
  -0.577350269189626, 0.577350269189626, 0.577350269189626,
  -0.577350269189626, 0.577350269189626, -0.577350269189626,
  // f 2//8 1//3 5//7
  0.577350269189626, -0.577350269189626, 0.577350269189626,
  0.577350269189626, 0.577350269189626, 0.577350269189626,
  -0.577350269189626, 0.577350269189626, 0.577350269189626,
  // f 3//2 7//5 5//7
  0.577350269189626, 0.577350269189626, -0.577350269189626,
  -0.577350269189626, 0.577350269189626, -0.577350269189626,
  -0.577350269189626, 0.577350269189626, 0.577350269189626,
  // f 8//4 4//1 2//8
  -0.577350269189626, -0.577350269189626, -0.577350269189626,
  0.577350269189626, -0.577350269189626, -0.577350269189626,
  0.577350269189626, -0.577350269189626, 0.577350269189626,
  // f 2//8 4//1 1//3
  0.577350269189626, -0.577350269189626, 0.577350269189626,
  0.577350269189626, -0.577350269189626, -0.577350269189626,
  0.577350269189626, 0.577350269189626, 0.577350269189626,
  // f 4//1 8//4 3//2
  0.577350269189626, -0.577350269189626, -0.577350269189626,
  -0.577350269189626, -0.577350269189626, -0.577350269189626,
  0.577350269189626, 0.577350269189626, -0.577350269189626,
  // f 8//4 6//6 7//5
  -0.577350269189626, -0.577350269189626, -0.577350269189626,
  -0.577350269189626, -0.577350269189626, 0.577350269189626,
  -0.577350269189626, 0.577350269189626, -0.577350269189626,
  // f 6//6 2//8 5//7
  -0.577350269189626, -0.577350269189626, 0.577350269189626,
  0.577350269189626, -0.577350269189626, 0.577350269189626,
  -0.577350269189626, 0.577350269189626, 0.577350269189626,
  // f 1//3 3//2 5//7
  0.577350269189626, 0.577350269189626, 0.577350269189626,
  0.577350269189626, 0.577350269189626, -0.577350269189626,
  -0.577350269189626, 0.577350269189626, 0.577350269189626,
  // f 6//6 8//4 2//8
  -0.577350269189626, -0.577350269189626, 0.577350269189626,
  -0.577350269189626, -0.577350269189626, -0.577350269189626,
  0.577350269189626, -0.577350269189626, 0.577350269189626,
};


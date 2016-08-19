

/*
created with obj2opengl.pl

source file    : ./sofa.obj
vertices       : 42
faces          : 80
normals        : 26
texture coords : 0


// include generated arrays
#import "./sofa.h"

// set input data to arrays
glVertexPointer(3, GL_FLOAT, 0, sofaVerts);
glNormalPointer(GL_FLOAT, 0, sofaNormals);

// draw data
glDrawArrays(GL_TRIANGLES, 0, sofaNumVerts);
*/

unsigned int sofaNumVerts = 240;

float sofaVerts [] = {
  // f 11//1 7//1 20//1
  1.27048076190476, 0.0465708095238095, 4.14152728571429,
  1.27048076190476, 0.0487818095238097, 4.14152728571429,
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  // f 18//2 17//2 24//2
  0.854183761904761, 0.0465708095238095, -2.76392071428571,
  -0.131293238095239, 0.0465708095238095, -2.76392071428571,
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  // f 5//3 9//3 10//3
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  -0.131293238095239, 0.0465708095238095, -3.49626271428571,
  1.27048076190476, 0.0465708095238095, -3.49626271428571,
  // f 38//4 11//4 21//4
  1.27844876190476, 0.65490580952381, 3.36013528571429,
  1.27048076190476, 0.0465708095238095, 4.14152728571429,
  1.27844876190476, 0.0333858095238095, 3.36516928571429,
  // f 19//5 23//5 3//5
  -0.123325238095239, -1.36440319047619, 3.36516928571429,
  1.27844876190476, -1.36440319047619, 3.36516928571429,
  1.27048076190476, -1.35121819047619, 4.14152728571429,
  // f 31//6 37//6 38//6
  1.27048076190476, 0.668091809523809, -3.50129771428571,
  0.854183761904761, 0.668091809523809, -2.76895571428571,
  1.27844876190476, 0.65490580952381, 3.36013528571429,
  // f 7//7 11//7 8//7
  1.27048076190476, 0.0487818095238097, 4.14152728571429,
  1.27048076190476, 0.0465708095238095, 4.14152728571429,
  -0.131293238095239, 0.0465708095238095, 4.14152728571429,
  // f 8//8 29//8 39//8
  -0.131293238095239, 0.0465708095238095, 4.14152728571429,
  -0.131293238095239, 0.668091809523809, 4.13649228571428,
  -0.123325238095239, 0.65490580952381, 3.36013528571429,
  // f 11//9 32//9 29//9
  1.27048076190476, 0.0465708095238095, 4.14152728571429,
  1.27048076190476, 0.668091809523809, 4.13649228571428,
  -0.131293238095239, 0.668091809523809, 4.13649228571428,
  // f 5//10 14//10 33//10
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  -2.27037323809524, -1.35121819047619, -3.49626271428571,
  -2.27037323809524, 0.67030280952381, -3.50129771428571,
  // f 27//11 42//11 41//11
  -1.82435323809524, 0.0487818095238097, -2.76392071428571,
  -1.82435323809524, 0.67030280952381, -2.76895571428571,
  -1.82435323809524, 0.67030280952381, -1.61076771428571,
  // f 40//12 39//12 29//12
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  -0.123325238095239, 0.65490580952381, 3.36013528571429,
  -0.131293238095239, 0.668091809523809, 4.13649228571428,
  // f 22//1 19//1 1//1
  -0.123325238095239, 0.0355968095238097, 3.36516928571429,
  -0.123325238095239, -1.36440319047619, 3.36516928571429,
  -0.131293238095239, -1.35121819047619, 4.14152728571429,
  // f 13//13 14//13 2//13
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  -2.27037323809524, -1.35121819047619, -3.49626271428571,
  1.27048076190476, -1.35121819047619, -3.49626271428571,
  // f 16//14 27//14 26//14
  -0.131293238095239, 0.0487818095238097, -2.76392071428571,
  -1.82435323809524, 0.0487818095238097, -2.76392071428571,
  -1.82435323809524, 0.0487818095238097, -1.60573271428571,
  // f 26//15 34//15 15//15
  -1.82435323809524, 0.0487818095238097, -1.60573271428571,
  -2.27037323809524, 0.67030280952381, -1.61076771428571,
  -2.27037323809524, -1.35121819047619, -1.60573271428571,
  // f 34//14 41//14 42//14
  -2.27037323809524, 0.67030280952381, -1.61076771428571,
  -1.82435323809524, 0.67030280952381, -1.61076771428571,
  -1.82435323809524, 0.67030280952381, -2.76895571428571,
  // f 14//16 15//16 34//16
  -2.27037323809524, -1.35121819047619, -3.49626271428571,
  -2.27037323809524, -1.35121819047619, -1.60573271428571,
  -2.27037323809524, 0.67030280952381, -1.61076771428571,
  // f 24//17 17//17 12//17
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  -0.131293238095239, 0.0465708095238095, -2.76392071428571,
  -0.131293238095239, 0.0487818095238097, -1.60573271428571,
  // f 9//18 30//18 31//18
  -0.131293238095239, 0.0465708095238095, -3.49626271428571,
  -0.131293238095239, 0.668091809523809, -3.50129771428571,
  1.27048076190476, 0.668091809523809, -3.50129771428571,
  // f 24//18 39//18 40//18
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  -0.123325238095239, 0.65490580952381, 3.36013528571429,
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  // f 16//9 35//9 42//9
  -0.131293238095239, 0.0487818095238097, -2.76392071428571,
  -0.131293238095239, 0.67030280952381, -2.76895571428571,
  -1.82435323809524, 0.67030280952381, -2.76895571428571,
  // f 18//9 37//9 36//9
  0.854183761904761, 0.0465708095238095, -2.76392071428571,
  0.854183761904761, 0.668091809523809, -2.76895571428571,
  -0.131293238095239, 0.668091809523809, -2.76895571428571,
  // f 20//19 23//19 2//19
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  1.27844876190476, -1.36440319047619, 3.36516928571429,
  1.27048076190476, -1.35121819047619, -3.49626271428571,
  // f 4//3 1//3 3//3
  -0.131293238095239, 0.0487818095238097, 4.14152728571429,
  -0.131293238095239, -1.35121819047619, 4.14152728571429,
  1.27048076190476, -1.35121819047619, 4.14152728571429,
  // f 18//20 25//20 40//20
  0.854183761904761, 0.0465708095238095, -2.76392071428571,
  0.862151761904761, 0.0333858095238095, 3.36516928571429,
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  // f 9//16 17//16 36//16
  -0.131293238095239, 0.0465708095238095, -3.49626271428571,
  -0.131293238095239, 0.0465708095238095, -2.76392071428571,
  -0.131293238095239, 0.668091809523809, -2.76895571428571,
  // f 20//21 6//21 10//21
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  1.27048076190476, 0.0487818095238097, -3.49626271428571,
  1.27048076190476, 0.0465708095238095, -3.49626271428571,
  // f 21//1 11//1 20//1
  1.27844876190476, 0.0333858095238095, 3.36516928571429,
  1.27048076190476, 0.0465708095238095, 4.14152728571429,
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  // f 20//21 10//21 21//21
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  1.27048076190476, 0.0465708095238095, -3.49626271428571,
  1.27844876190476, 0.0333858095238095, 3.36516928571429,
  // f 25//2 18//2 24//2
  0.862151761904761, 0.0333858095238095, 3.36516928571429,
  0.854183761904761, 0.0465708095238095, -2.76392071428571,
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  // f 6//3 5//3 10//3
  1.27048076190476, 0.0487818095238097, -3.49626271428571,
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  1.27048076190476, 0.0465708095238095, -3.49626271428571,
  // f 21//19 10//19 38//19
  1.27844876190476, 0.0333858095238095, 3.36516928571429,
  1.27048076190476, 0.0465708095238095, -3.49626271428571,
  1.27844876190476, 0.65490580952381, 3.36013528571429,
  // f 38//4 32//4 11//4
  1.27844876190476, 0.65490580952381, 3.36013528571429,
  1.27048076190476, 0.668091809523809, 4.13649228571428,
  1.27048076190476, 0.0465708095238095, 4.14152728571429,
  // f 10//19 31//19 38//19
  1.27048076190476, 0.0465708095238095, -3.49626271428571,
  1.27048076190476, 0.668091809523809, -3.50129771428571,
  1.27844876190476, 0.65490580952381, 3.36013528571429,
  // f 1//5 19//5 3//5
  -0.131293238095239, -1.35121819047619, 4.14152728571429,
  -0.123325238095239, -1.36440319047619, 3.36516928571429,
  1.27048076190476, -1.35121819047619, 4.14152728571429,
  // f 31//14 30//14 37//14
  1.27048076190476, 0.668091809523809, -3.50129771428571,
  -0.131293238095239, 0.668091809523809, -3.50129771428571,
  0.854183761904761, 0.668091809523809, -2.76895571428571,
  // f 40//2 38//2 37//2
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  1.27844876190476, 0.65490580952381, 3.36013528571429,
  0.854183761904761, 0.668091809523809, -2.76895571428571,
  // f 30//14 36//14 37//14
  -0.131293238095239, 0.668091809523809, -3.50129771428571,
  -0.131293238095239, 0.668091809523809, -2.76895571428571,
  0.854183761904761, 0.668091809523809, -2.76895571428571,
  // f 4//7 7//7 8//7
  -0.131293238095239, 0.0487818095238097, 4.14152728571429,
  1.27048076190476, 0.0487818095238097, 4.14152728571429,
  -0.131293238095239, 0.0465708095238095, 4.14152728571429,
  // f 24//8 8//8 39//8
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  -0.131293238095239, 0.0465708095238095, 4.14152728571429,
  -0.123325238095239, 0.65490580952381, 3.36013528571429,
  // f 8//9 11//9 29//9
  -0.131293238095239, 0.0465708095238095, 4.14152728571429,
  1.27048076190476, 0.0465708095238095, 4.14152728571429,
  -0.131293238095239, 0.668091809523809, 4.13649228571428,
  // f 5//7 6//7 2//7
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  1.27048076190476, 0.0487818095238097, -3.49626271428571,
  1.27048076190476, -1.35121819047619, -3.49626271428571,
  // f 33//18 28//18 5//18
  -2.27037323809524, 0.67030280952381, -3.50129771428571,
  -0.131293238095239, 0.67030280952381, -3.50129771428571,
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  // f 2//7 14//7 5//7
  1.27048076190476, -1.35121819047619, -3.49626271428571,
  -2.27037323809524, -1.35121819047619, -3.49626271428571,
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  // f 26//11 27//11 41//11
  -1.82435323809524, 0.0487818095238097, -1.60573271428571,
  -1.82435323809524, 0.0487818095238097, -2.76392071428571,
  -1.82435323809524, 0.67030280952381, -1.61076771428571,
  // f 29//12 32//12 40//12
  -0.131293238095239, 0.668091809523809, 4.13649228571428,
  1.27048076190476, 0.668091809523809, 4.13649228571428,
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  // f 38//12 40//12 32//12
  1.27844876190476, 0.65490580952381, 3.36013528571429,
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  1.27048076190476, 0.668091809523809, 4.13649228571428,
  // f 1//1 4//1 22//1
  -0.131293238095239, -1.35121819047619, 4.14152728571429,
  -0.131293238095239, 0.0487818095238097, 4.14152728571429,
  -0.123325238095239, 0.0355968095238097, 3.36516928571429,
  // f 22//22 12//22 13//22
  -0.123325238095239, 0.0355968095238097, 3.36516928571429,
  -0.131293238095239, 0.0487818095238097, -1.60573271428571,
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  // f 13//22 19//22 22//22
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  -0.123325238095239, -1.36440319047619, 3.36516928571429,
  -0.123325238095239, 0.0355968095238097, 3.36516928571429,
  // f 23//23 19//23 13//23
  1.27844876190476, -1.36440319047619, 3.36516928571429,
  -0.123325238095239, -1.36440319047619, 3.36516928571429,
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  // f 13//13 15//13 14//13
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  -2.27037323809524, -1.35121819047619, -1.60573271428571,
  -2.27037323809524, -1.35121819047619, -3.49626271428571,
  // f 2//24 23//24 13//24
  1.27048076190476, -1.35121819047619, -3.49626271428571,
  1.27844876190476, -1.36440319047619, 3.36516928571429,
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  // f 12//14 16//14 26//14
  -0.131293238095239, 0.0487818095238097, -1.60573271428571,
  -0.131293238095239, 0.0487818095238097, -2.76392071428571,
  -1.82435323809524, 0.0487818095238097, -1.60573271428571,
  // f 15//3 13//3 26//3
  -2.27037323809524, -1.35121819047619, -1.60573271428571,
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  -1.82435323809524, 0.0487818095238097, -1.60573271428571,
  // f 26//9 41//9 34//9
  -1.82435323809524, 0.0487818095238097, -1.60573271428571,
  -1.82435323809524, 0.67030280952381, -1.61076771428571,
  -2.27037323809524, 0.67030280952381, -1.61076771428571,
  // f 13//3 12//3 26//3
  -0.131293238095239, -1.35121819047619, -1.60573271428571,
  -0.131293238095239, 0.0487818095238097, -1.60573271428571,
  -1.82435323809524, 0.0487818095238097, -1.60573271428571,
  // f 42//14 35//14 28//14
  -1.82435323809524, 0.67030280952381, -2.76895571428571,
  -0.131293238095239, 0.67030280952381, -2.76895571428571,
  -0.131293238095239, 0.67030280952381, -3.50129771428571,
  // f 33//14 34//14 42//14
  -2.27037323809524, 0.67030280952381, -3.50129771428571,
  -2.27037323809524, 0.67030280952381, -1.61076771428571,
  -1.82435323809524, 0.67030280952381, -2.76895571428571,
  // f 42//14 28//14 33//14
  -1.82435323809524, 0.67030280952381, -2.76895571428571,
  -0.131293238095239, 0.67030280952381, -3.50129771428571,
  -2.27037323809524, 0.67030280952381, -3.50129771428571,
  // f 33//16 14//16 34//16
  -2.27037323809524, 0.67030280952381, -3.50129771428571,
  -2.27037323809524, -1.35121819047619, -3.49626271428571,
  -2.27037323809524, 0.67030280952381, -1.61076771428571,
  // f 16//11 12//11 17//11
  -0.131293238095239, 0.0487818095238097, -2.76392071428571,
  -0.131293238095239, 0.0487818095238097, -1.60573271428571,
  -0.131293238095239, 0.0465708095238095, -2.76392071428571,
  // f 28//11 35//11 5//11
  -0.131293238095239, 0.67030280952381, -3.50129771428571,
  -0.131293238095239, 0.67030280952381, -2.76895571428571,
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  // f 17//11 9//11 5//11
  -0.131293238095239, 0.0465708095238095, -2.76392071428571,
  -0.131293238095239, 0.0465708095238095, -3.49626271428571,
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  // f 5//11 35//11 16//11
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  -0.131293238095239, 0.67030280952381, -2.76895571428571,
  -0.131293238095239, 0.0487818095238097, -2.76392071428571,
  // f 22//25 4//25 8//25
  -0.123325238095239, 0.0355968095238097, 3.36516928571429,
  -0.131293238095239, 0.0487818095238097, 4.14152728571429,
  -0.131293238095239, 0.0465708095238095, 4.14152728571429,
  // f 5//11 16//11 17//11
  -0.131293238095239, 0.0487818095238097, -3.49626271428571,
  -0.131293238095239, 0.0487818095238097, -2.76392071428571,
  -0.131293238095239, 0.0465708095238095, -2.76392071428571,
  // f 24//26 12//26 22//26
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  -0.131293238095239, 0.0487818095238097, -1.60573271428571,
  -0.123325238095239, 0.0355968095238097, 3.36516928571429,
  // f 22//25 8//25 24//25
  -0.123325238095239, 0.0355968095238097, 3.36516928571429,
  -0.131293238095239, 0.0465708095238095, 4.14152728571429,
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  // f 10//18 9//18 31//18
  1.27048076190476, 0.0465708095238095, -3.49626271428571,
  -0.131293238095239, 0.0465708095238095, -3.49626271428571,
  1.27048076190476, 0.668091809523809, -3.50129771428571,
  // f 25//18 24//18 40//18
  0.862151761904761, 0.0333858095238095, 3.36516928571429,
  -0.123325238095239, 0.0333858095238095, 3.36516928571429,
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  // f 27//9 16//9 42//9
  -1.82435323809524, 0.0487818095238097, -2.76392071428571,
  -0.131293238095239, 0.0487818095238097, -2.76392071428571,
  -1.82435323809524, 0.67030280952381, -2.76895571428571,
  // f 17//9 18//9 36//9
  -0.131293238095239, 0.0465708095238095, -2.76392071428571,
  0.854183761904761, 0.0465708095238095, -2.76392071428571,
  -0.131293238095239, 0.668091809523809, -2.76895571428571,
  // f 2//19 6//19 20//19
  1.27048076190476, -1.35121819047619, -3.49626271428571,
  1.27048076190476, 0.0487818095238097, -3.49626271428571,
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  // f 20//25 7//25 3//25
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  1.27048076190476, 0.0487818095238097, 4.14152728571429,
  1.27048076190476, -1.35121819047619, 4.14152728571429,
  // f 3//25 23//25 20//25
  1.27048076190476, -1.35121819047619, 4.14152728571429,
  1.27844876190476, -1.36440319047619, 3.36516928571429,
  1.27844876190476, 0.0355968095238097, 3.36516928571429,
  // f 7//3 4//3 3//3
  1.27048076190476, 0.0487818095238097, 4.14152728571429,
  -0.131293238095239, 0.0487818095238097, 4.14152728571429,
  1.27048076190476, -1.35121819047619, 4.14152728571429,
  // f 37//20 18//20 40//20
  0.854183761904761, 0.668091809523809, -2.76895571428571,
  0.854183761904761, 0.0465708095238095, -2.76392071428571,
  0.862151761904761, 0.65490580952381, 3.36013528571429,
  // f 30//16 9//16 36//16
  -0.131293238095239, 0.668091809523809, -3.50129771428571,
  -0.131293238095239, 0.0465708095238095, -3.49626271428571,
  -0.131293238095239, 0.668091809523809, -2.76895571428571,
};

float sofaNormals [] = {
  // f 11//1 7//1 20//1
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  // f 18//2 17//2 24//2
  0, 0.999997580008785, 0.00219999467601933,
  0, 0.999997580008785, 0.00219999467601933,
  0, 0.999997580008785, 0.00219999467601933,
  // f 5//3 9//3 10//3
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 38//4 11//4 21//4
  0.999946943611178, 0.000100004694830601, 0.0103004835675519,
  0.999946943611178, 0.000100004694830601, 0.0103004835675519,
  0.999946943611178, 0.000100004694830601, 0.0103004835675519,
  // f 19//5 23//5 3//5
  0, -0.999855502421025, 0.016999243465504,
  0, -0.999855502421025, 0.016999243465504,
  0, -0.999855502421025, 0.016999243465504,
  // f 31//6 37//6 38//6
  0.00339997421129341, 0.999992415086297, 0.00189998558866397,
  0.00339997421129341, 0.999992415086297, 0.00189998558866397,
  0.00339997421129341, 0.999992415086297, 0.00189998558866397,
  // f 7//7 11//7 8//7
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 8//8 29//8 39//8
  -0.999946943611178, -0.000100004694830601, -0.0103004835675519,
  -0.999946943611178, -0.000100004694830601, -0.0103004835675519,
  -0.999946943611178, -0.000100004694830601, -0.0103004835675519,
  // f 11//9 32//9 29//9
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  // f 5//10 14//10 33//10
  0.00159999295204657, -0.00249998898757276, -0.999995595029106,
  0.00159999295204657, -0.00249998898757276, -0.999995595029106,
  0.00159999295204657, -0.00249998898757276, -0.999995595029106,
  // f 27//11 42//11 41//11
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 40//12 39//12 29//12
  0, 0.999855502421025, -0.016999243465504,
  0, 0.999855502421025, -0.016999243465504,
  0, 0.999855502421025, -0.016999243465504,
  // f 22//1 19//1 1//1
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  // f 13//13 14//13 2//13
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 16//14 27//14 26//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 26//15 34//15 15//15
  -0.00779973836216489, 0.00249991614171952, 0.999966456687806,
  -0.00779973836216489, 0.00249991614171952, 0.999966456687806,
  -0.00779973836216489, 0.00249991614171952, 0.999966456687806,
  // f 34//14 41//14 42//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 14//16 15//16 34//16
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
  // f 24//17 17//17 12//17
  0.952385652418219, 0.304895406785295, -0.000599990961204254,
  0.952385652418219, 0.304895406785295, -0.000599990961204254,
  0.952385652418219, 0.304895406785295, -0.000599990961204254,
  // f 9//18 30//18 31//18
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  // f 24//18 39//18 40//18
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  // f 16//9 35//9 42//9
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  // f 18//9 37//9 36//9
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  // f 20//19 23//19 2//19
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  // f 4//3 1//3 3//3
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 18//20 25//20 40//20
  -0.999999155001071, 0, 0.00129999890150139,
  -0.999999155001071, 0, 0.00129999890150139,
  -0.999999155001071, 0, 0.00129999890150139,
  // f 9//16 17//16 36//16
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
  // f 20//21 6//21 10//21
  -0.999999280000778, 0, 0.00119999913600093,
  -0.999999280000778, 0, 0.00119999913600093,
  -0.999999280000778, 0, 0.00119999913600093,
  // f 21//1 11//1 20//1
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  // f 20//21 10//21 21//21
  -0.999999280000778, 0, 0.00119999913600093,
  -0.999999280000778, 0, 0.00119999913600093,
  -0.999999280000778, 0, 0.00119999913600093,
  // f 25//2 18//2 24//2
  0, 0.999997580008785, 0.00219999467601933,
  0, 0.999997580008785, 0.00219999467601933,
  0, 0.999997580008785, 0.00219999467601933,
  // f 6//3 5//3 10//3
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 21//19 10//19 38//19
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  // f 38//4 32//4 11//4
  0.999946943611178, 0.000100004694830601, 0.0103004835675519,
  0.999946943611178, 0.000100004694830601, 0.0103004835675519,
  0.999946943611178, 0.000100004694830601, 0.0103004835675519,
  // f 10//19 31//19 38//19
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  // f 1//5 19//5 3//5
  0, -0.999855502421025, 0.016999243465504,
  0, -0.999855502421025, 0.016999243465504,
  0, -0.999855502421025, 0.016999243465504,
  // f 31//14 30//14 37//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 40//2 38//2 37//2
  0, 0.999997580008785, 0.00219999467601933,
  0, 0.999997580008785, 0.00219999467601933,
  0, 0.999997580008785, 0.00219999467601933,
  // f 30//14 36//14 37//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 4//7 7//7 8//7
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 24//8 8//8 39//8
  -0.999946943611178, -0.000100004694830601, -0.0103004835675519,
  -0.999946943611178, -0.000100004694830601, -0.0103004835675519,
  -0.999946943611178, -0.000100004694830601, -0.0103004835675519,
  // f 8//9 11//9 29//9
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  // f 5//7 6//7 2//7
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 33//18 28//18 5//18
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  // f 2//7 14//7 5//7
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 26//11 27//11 41//11
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 29//12 32//12 40//12
  0, 0.999855502421025, -0.016999243465504,
  0, 0.999855502421025, -0.016999243465504,
  0, 0.999855502421025, -0.016999243465504,
  // f 38//12 40//12 32//12
  0, 0.999855502421025, -0.016999243465504,
  0, 0.999855502421025, -0.016999243465504,
  0, 0.999855502421025, -0.016999243465504,
  // f 1//1 4//1 22//1
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  -0.999946948611382, 0, -0.0103004836190591,
  // f 22//22 12//22 13//22
  -0.999998720002457, 0, 0.00159999795200393,
  -0.999998720002457, 0, 0.00159999795200393,
  -0.999998720002457, 0, 0.00159999795200393,
  // f 13//22 19//22 22//22
  -0.999998720002457, 0, 0.00159999795200393,
  -0.999998720002457, 0, 0.00159999795200393,
  -0.999998720002457, 0, 0.00159999795200393,
  // f 23//23 19//23 13//23
  0, -0.999996355019929, -0.00269999015855381,
  0, -0.999996355019929, -0.00269999015855381,
  0, -0.999996355019929, -0.00269999015855381,
  // f 13//13 15//13 14//13
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 2//24 23//24 13//24
  -0.00259998651910485, -0.999994815040326, -0.00189999014857662,
  -0.00259998651910485, -0.999994815040326, -0.00189999014857662,
  -0.00259998651910485, -0.999994815040326, -0.00189999014857662,
  // f 12//14 16//14 26//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 15//3 13//3 26//3
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 26//9 41//9 34//9
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  // f 13//3 12//3 26//3
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 42//14 35//14 28//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 33//14 34//14 42//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 42//14 28//14 33//14
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 33//16 14//16 34//16
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
  // f 16//11 12//11 17//11
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 28//11 35//11 5//11
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 17//11 9//11 5//11
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 5//11 35//11 16//11
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 22//25 4//25 8//25
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  // f 5//11 16//11 17//11
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 24//26 12//26 22//26
  0.999998720002457, 0, -0.00159999795200393,
  0.999998720002457, 0, -0.00159999795200393,
  0.999998720002457, 0, -0.00159999795200393,
  // f 22//25 8//25 24//25
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  // f 10//18 9//18 31//18
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  // f 25//18 24//18 40//18
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  0, -0.00809973429257473, -0.999967196614164,
  // f 27//9 16//9 42//9
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  // f 17//9 18//9 36//9
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  0, 0.00809973429257473, 0.999967196614164,
  // f 2//19 6//19 20//19
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  0.999999280000778, 0, -0.00119999913600093,
  // f 20//25 7//25 3//25
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  // f 3//25 23//25 20//25
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  0.999946948611382, 0, 0.0103004836190591,
  // f 7//3 4//3 3//3
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 37//20 18//20 40//20
  -0.999999155001071, 0, 0.00129999890150139,
  -0.999999155001071, 0, 0.00129999890150139,
  -0.999999155001071, 0, 0.00129999890150139,
  // f 30//16 9//16 36//16
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
};

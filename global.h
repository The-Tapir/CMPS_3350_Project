#ifndef GLOBAL_H
#define GLOBAL_H

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#define MakeVector(x, y, z, v) (v)[0]=(x),(v)[1]=(y),(v)[2]=(z)
#define PI 3.14159265358979323846264338327950

extern float theta;

typedef float Flt;
typedef Flt Vec[3];
typedef Flt	Matrix[4][4];

class Global {
public:
    int xres, yres;
    Flt aspectRatio;
    Vec cameraPosition;
    //added
    Flt cameraAngle;
    //------------
    GLfloat lightPosition[4];
    Global();
};

extern Global g;

#endif

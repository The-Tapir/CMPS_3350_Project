#include "global.h"

Global::Global() {
    xres = 640;
    yres = 480;
    aspectRatio = (GLfloat)xres / (GLfloat)yres;
    MakeVector(13.99999, 2.25, 15.650, cameraPosition);
    // light is up high, right a little, toward a little
    MakeVector(100.0f, 240.0f, 40.0f, lightPosition);
    lightPosition[3] = 1.0f;
    cameraAngle = (PI*0.5) - theta;
}

Global g;

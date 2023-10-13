//Name: Mostafa Abadi
//Created: September 26th, 2023



#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include "mabadi.h"


typedef float Flt;
typedef Flt Vec[3];
typedef Flt Matrix[4][4];

// The functions below will be anle  to draw the racetrack
void drawRacetrack() {
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    
    // These fucntions below will decide the width and length of the track.
    float trackWidth = 10.0f;
    float trackLength = 100.0f;
    
    glBegin(GL_QUADS);
    glVertex3f(-trackWidth, 0.0f, -trackLength);
    glVertex3f(trackWidth, 0.0f, -trackLength);
    glVertex3f(trackWidth, 0.0f, trackLength);
    glVertex3f(-trackWidth, 0.0f, trackLength);
    glEnd();

    glPopMatrix();
}




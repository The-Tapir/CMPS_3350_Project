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

void init() {
    
}

void init_opengl() {
    
}

void check_mouse(XEvent *e) {
    
}

int check_keys(XEvent *e) {
    // I will handle keyboard events here
    return 0;
}

void physics() {
    //I will deal with physics aspect/game logic here
}

void render() {
    Rect r;

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    
    // This functions below will drawk the racetrack
    drawRacetrack();

    

    ggprint8b(&r, 16, 0x00887766, "Time: 0");
}

int main() {
    init_opengl();
    int done = 0;

    while (!done) {
        while (x11.getXPending()) {
            XEvent e = x11.getXNextEvent();
            x11.check_resize(&e);
            check_mouse(&e);
            done = check_keys(&e);
        }
        physics();
        render();
        x11.swapBuffers();
    }
    cleanup_fonts();
    return 0;
}

int main() {
    init_opengl();
    int done = 0;

    while (!done) {
        while (x11.getXPending()) {
            XEvent e = x11.getXNextEvent();
            x11.check_resize(&e);
            check_mouse(&e);
            done = check_keys(&e);
        }
        physics();
        render();
        x11.swapBuffers();
    }
    cleanup_fonts();
    return 0;
}


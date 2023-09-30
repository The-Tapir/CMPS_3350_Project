//uthor: Mostafa Abadi
//Created: September 26th, 2023



#include "mabadi.h"
#include <GL/gl.h>

RoadRacetrack::RoadRacetrack() {
   // This is where you would start the racetrack logic.
}

void RoadRacetrack::check_mouse(XEvent *e) {
    // If necessary, deal with the mouse inputs. 
}

int RoadRacetrack::check_keys(XEvent *e) {
    // If necessary, deal with the keyboard inputs. 
    return 0;
}

void RoadRacetrack::physics() {
    // This us where the physics aspect of the racetrack would begin
}

void RoadRacetrack::drawRoad() {
    //below are functions for drawing the road 
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    float roadWidth = 10.0f;
    float roadLength = 1000.0f;

    
    glBegin(GL_QUADS);
    glVertex3f(-roadWidth, 0.0f, -roadLength);
    glVertex3f(roadWidth, 0.0f, -roadLength);
    glVertex3f(roadWidth, 0.0f, roadLength);
    glVertex3f(-roadWidth, 0.0f, roadLength);
    glEnd();

    glPopMatrix();
}

void RoadRacetrack::render() {
    // This s where you woukd Call drawRoad() to render the road.
    drawRoad();
}




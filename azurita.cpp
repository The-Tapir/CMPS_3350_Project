//Name: Alexis Zurita
//Date: Oct 25 2022
//Game: Jerry the Race Car Driver
//game aspect to cover:


// background                            objects off the map for to add depth
// legend/map                            timer
// 3D road                               power-ups on road --- speed boost, invincibilty, invisibility, hit boost, object to make drivers crash/stop/spin ---> possible ideas to implement
// ready set go start of game


// Current main goal implement the car on track ----> Note: after this try to implement the mmovement of the car. 2nd goal would be to be able to make the car move forward, backward, left and right

#include "azurita.h"

using namespace std;
using namespace std::chrono;

typedef float Flt;
typedef Flt Vec[3];
float wheelRotation = 0.0f;

void azuritaBox(float width, float height, float depth);
void drawCylinder(float radius, float height, int numSegments);
void drawCylinder(float radius, float height, int numSegments, float rotationAngle);

#define MakeVector(x, y, z, v) (v)[0]=(x),(v)[1]=(y),(v)[2]=(z)

static Vec carPosition;
static Vec carSize;
bool wheelsInitialized = false;

// Initialization of the car's attributes
void initializeAzuritaCarAttributes(float Pos1, float Pos2, float Pos3) {
    if (!wheelsInitialized) {
        // Set the initial position of the car
        MakeVector(Pos1, Pos2, Pos3, carPosition);

        // Set the size of the car (as a simple rectangle)
        MakeVector(1.0f, 0.5f, 2.5f, carSize);

        // Rotate the wheels to the correct initial position
        wheelRotation = 90.0f; // Add a global variable for wheel rotation

        wheelsInitialized = true; // Mark initialization as done
    }
}

void drawAzuritaCar(float Pos1, float Pos2, float Pos3) {
    initializeAzuritaCarAttributes(Pos1, Pos2, Pos3);

    glPushMatrix();

    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glTranslatef(Pos1, Pos2, Pos3);

    // Drawing the car as a rectangular cube
    azuritaBox(carSize[0], carSize[1], carSize[2]);

    // Drawing wheels with the initial wheel rotation
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for wheels

    // Declare localWheelRotation once
    float localWheelRotation = wheelRotation;

    // Draw front left wheel
    glPushMatrix();
    glTranslatef(carPosition[0]*0.5f - 7.5f, -carPosition[1]*0.5f + 0.2f, -carPosition[2]*0.5f + 3.7f);
    glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
    drawCylinder(0.25f, 0.1f, 16);
    glPopMatrix();

    // Draw front right wheel
    glPushMatrix();
    glTranslatef(carPosition[0]*0.5f - 6.5f, -carPosition[1]*0.5f + 0.2f, carPosition[2]*0.5f - 6.0f);
    glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
    drawCylinder(0.25f, 0.1f, 16);
    glPopMatrix();

    // Draw rear left wheel
    glPushMatrix();
    glTranslatef(carPosition[0]*0.5f - 7.5f, -carPosition[1]*0.5f +  0.2f, -carPosition[2]*0.5f + 6.0f);
    glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
    drawCylinder(0.25f, 0.1f, 16);
    glPopMatrix();

    // Draw rear right wheel
    glPushMatrix();
    glTranslatef(carPosition[0]*0.5f - 6.5f, -carPosition[1]*0.5f + 0.2f, -carPosition[2] * 0.5f + 6.0f);
    glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
    drawCylinder(0.25f, 0.1f, 16);
    glPopMatrix();
}

void azuritaBox(float width, float height, float depth) {

    width = width * 0.5f;
    height = height * 1.0f;
    depth = depth * 0.5f;
    glBegin(GL_QUADS);
    glColor3ub(173, 88, 8); // Car Color
    // front
    glVertex3f(-width, -height, depth);
    glVertex3f(width, -height, depth);
    glVertex3f(width, height, depth);
    glVertex3f(-width, height, depth);
    // back
    glVertex3f(-width, -height, -depth);
    glVertex3f(width, -height, -depth);
    glVertex3f(width, height, -depth);
    glVertex3f(-width, height, -depth);
    // top
    glVertex3f(-width, height, depth);
    glVertex3f(width, height, depth);
    glVertex3f(width, height, -depth);
    glVertex3f(-width, height, -depth);
    // bottom
    glVertex3f(-width, -height, depth);
    glVertex3f(width, -height, depth);
    glVertex3f(width, -height, -depth);
    glVertex3f(-width, -height, -depth);
    // right
    glVertex3f(width, -height, depth);
    glVertex3f(width, height, depth);
    glVertex3f(width, height, -depth);
    glVertex3f(width, -height, -depth);
    // left
    glVertex3f(-width, -height, depth);
    glVertex3f(-width, height, depth);
    glVertex3f(-width, height, -depth);
    glVertex3f(-width, -height, -depth);
    glEnd();
}

void drawCylinder(float radius, float height, int numSegments) {
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSegments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cos(theta);
        float y = radius * sin(theta);

        glVertex3f(x, y, -height * 0.5f);
        glVertex3f(x, y, height * 0.5f);
    }
   glEnd();
}



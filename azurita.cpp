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

#define MakeVector(x, y, z, v) (v)[0]=(x),(v)[1]=(y),(v)[2]=(z)

void azuritaBox(float width, float height, float depth);


static Vec carPosition;
static Vec carSize;

// Initialization of the car's attributes
void initializeAzuritaCarAttributes() {
    // Set the initial position of the car
    MakeVector(0.0f, 0.0f, -5.0f, carPosition);

    // Set the size of the car (as a simple rectangle)
    MakeVector(1.0f, 0.5f, 2.5f, carSize);
}

// A function to draw the car
void drawAzuritaCar() {
    // Initialize the attributes
    initializeAzuritaCarAttributes();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glTranslatef(carPosition[0], carPosition[1], carPosition[2]);

    // Drawing the car as a rectangular cube
    azuritaBox(carSize[0], carSize[1], carSize[2]);

    glPopMatrix();
}

void azuritaBox(float width, float height, float depth) {
    width = width * 0.5f;
    height = height * 2.0f;
    depth = depth * 0.5f;
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);  // red
    //front
    glVertex3f(-width, -height, depth);
    glVertex3f( width, -height, depth);
    glVertex3f( width,  height, depth);
    glVertex3f(-width,  height, depth);
    //back
    glVertex3f(-width, -height, -depth);
    glVertex3f( width, -height, -depth);
    glVertex3f( width,  height, -depth);
    glVertex3f(-width,  height, -depth);
    //top
    glVertex3f(-width,  height,  depth);
    glVertex3f( width,  height,  depth);
    glVertex3f( width,  height, -depth);
    glVertex3f(-width,  height, -depth);
    //bottom
    glVertex3f(-width, -height,  depth);
    glVertex3f( width, -height,  depth);
    glVertex3f( width, -height, -depth);
    glVertex3f(-width, -height, -depth);
    //right
    glVertex3f( width, -height,  depth);
    glVertex3f( width,  height,  depth);
    glVertex3f( width,  height, -depth);
    glVertex3f( width, -height, -depth);
    //left
    glVertex3f(-width, -height,  depth);
    glVertex3f(-width,  height,  depth);
    glVertex3f(-width,  height, -depth);
    glVertex3f(-width, -height, -depth);
    glEnd();
}

// Below is the for lab9 question 2.
// Time variables
 

steady_clock::time_point lastKeyPressTime;

int total_time_since_key_press(const bool get)
{
    static int elapsedTime = 0;

    if (get)
    {
        steady_clock::time_point now = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(now - lastKeyPressTime);
        elapsedTime = static_cast<int>(time_span.count());
        return elapsedTime;
    }
    else
    {
        // Reset the timer to the current time when a key is pressed
        lastKeyPressTime = steady_clock::now();
        return 0;
    }
}



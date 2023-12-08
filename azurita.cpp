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
//#include "common.h"

using namespace std;
using namespace std::chrono;

typedef float Flt;
typedef Flt Vec[3];
float wheelRotation = 0.0f;

float Pos1 = 13.99999f;
float Pos2 = 1.2547f;
float Pos3 = 9.65f;
float theta = 3.100f;

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
void drawAzuritaCar(float Pos1, float Pos2, float Pos3, float theta) {
	initializeAzuritaCarAttributes(Pos1, Pos2, Pos3);

	glPushMatrix();

	glColor3f(1.0f, 0.0f, 0.0f); // Red color

	// Translate and rotate the entire car
	glTranslatef(Pos1, Pos2, Pos3);
	glRotatef(theta * (180.0f / 3.1415926f), 0.0f, 1.0f, 0.0f);  // Convert radians to degrees

	// Calculate new position based on the rotation angle
	float displacement = 1.0f;  // Adjust the displacement as needed
	float newPos1 = Pos1 + displacement * cos(theta);
	float newPos3 = Pos3 + displacement * sin(theta);

	// Update the car position variables
	Pos1 = newPos1;
	Pos3 = newPos3;
	// Translate the car to the new position
	glTranslatef(newPos1 - Pos1, 0.0f, newPos3 - Pos3);

	// Drawing the car as a rectangular cube
	//azuritaBox(carSize[0], carSize[1], carSize[2]);
	drawCarBody(carSize[0], carSize[1], carSize[2]);

	// Drawing wheels with the initial wheel rotation
	glColor3f(0.0f, 0.0f, 0.0f); // Black color for wheels
	// Declare localWheelRotation once
	float localWheelRotation = wheelRotation;

	// Draw front left wheel
	glPushMatrix();
	glTranslatef(carPosition[0]*0.5f - 7.5f, -carPosition[1]*0.5f + 0.2f, -carPosition[2]*0.5f + 3.7f);
	glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
	drawCarWheel(0.25f, 0.1f, 16);
	glPopMatrix();

	// Draw front right wheel
	glPushMatrix();
	glTranslatef(carPosition[0]*0.5f - 6.5f, -carPosition[1]*0.5f + 0.2f, carPosition[2]*0.5f - 6.0f);
	glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
	drawCarWheel(0.25f, 0.1f, 16);
	glPopMatrix();

	// Draw rear left wheel
	glPushMatrix();
	glTranslatef(carPosition[0]*0.5f - 7.5f, -carPosition[1]*0.5f +  0.2f, -carPosition[2]*0.5f + 6.0f);
	glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
	drawCarWheel(0.25f, 0.1f, 16);
	glPopMatrix();

	// Draw rear right wheel
	glPushMatrix();
	glTranslatef(carPosition[0]*0.5f - 6.5f, -carPosition[1]*0.5f + 0.2f, -carPosition[2] * 0.5f + 6.0f);
	glRotatef(localWheelRotation, 0.0f, 1.0f, 0.0f);
	drawCarWheel(0.25f, 0.1f, 16);
	glPopMatrix();
	glPopMatrix();
}

void drawCarBody(float width, float height, float depth) {

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

void drawCarWheel(float radius, float height, int numSegments) {
	glBegin(GL_TRIANGLE_FAN);

	// Center vertex of the top face
	glVertex3f(0.0f, 0.0f, height * 0.5f);

	for (int i = 0; i <= numSegments; ++i) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
		float x = radius * cos(theta);
		float y = radius * sin(theta);

		// Vertex on the top face
		glVertex3f(x, y, height * 0.5f);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	// Center vertex of the bottom face
	glVertex3f(0.0f, 0.0f, -height * 0.5f);

	for (int i = 0; i <= numSegments; ++i) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
		float x = radius * cos(theta);
		float y = radius * sin(theta);

		// Vertex on the bottom face
		glVertex3f(x, y, -height * 0.5f);
	}

	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= numSegments; ++i) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
		float x = radius * cos(theta);
		float y = radius * sin(theta);

		// Vertex on the top face
		glVertex3f(x, y, height * 0.5f);

		// Vertex on the bottom face
		glVertex3f(x, y, -height * 0.5f);
	}
	glEnd();
}

void draw2DDiamondStar(float size, GLfloat r, GLfloat g, GLfloat b) {
    glColor3f(255, 255, 255);
    glBegin(GL_TRIANGLES);

    // two triangle to make a star

    // first triangle
    glVertex2f(0.0f, size / 2.0f);            // top vertex
    glVertex2f(size / 2.0f, 0.0f);            //bottom right vertex
    glVertex2f(0.0f, -size / 2.0f);         //bottom left vertex

    // second triangle
    glVertex2f(0.0f, size / 2.0f);
    glVertex2f(-size / 2.0f, 0.0f);
    glVertex2f(0.0f, -size / 2.0f);

    glEnd();
}


void createImages()
{

    //srand to randomly display stars
    srand(static_cast<unsigned int>(time(nullptr)));

    //for loop to display multiple stars
    for (int i = 0; i < 250; ++i) {

       //randomly display the stars within a certain range

        float x = static_cast<float>(rand()) / RAND_MAX * 120.0f - 60.0f; // range for length
        float y = static_cast<float>(rand()) / RAND_MAX * 20.0f + 10.0f;  //range for height
        float z = static_cast<float>(rand()) / RAND_MAX * 120.0f - 60.0f; //range for depth


      // displays the stars here
        glPushMatrix();
        glTranslatef(x, y, z);
        draw2DDiamondStar(1.0f, 1.0f, 1.0f, 1.0f);
        glPopMatrix();
    }
}


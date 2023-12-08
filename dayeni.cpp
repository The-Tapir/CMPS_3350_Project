//Name: David Ayeni

#include "dayeni.h"

//Variables for Car Position and Angle
float Pos1 = 13.99999f;
float Pos2 = 1.2547f;
float Pos3 = 9.65f;
float theta = 3.151f;
float Cam1 = 13.9999f;
float Cam2 = 2.250f;
float Cam3 = 12.650f;
float CamAngle = (PI*0.5) - theta;

//Menu Screen
void drawMenu(int xres, int yres, int selectedOption) {
    glClearColor(0.00f, 0.0f, 0.0f, 1.0f);

    // Set up the orthographic projection for 2D rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, xres, 0, yres);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Define menu option dimensions
    float OptionWidth = xres * 0.08;
    float OptionHeight = yres * 0.2;
    float spacing = yres * 0.001;

    // Calculate the center of the screen
    float centerX = xres * 0.5;
    float centerY = yres * 0.5;

    // Calculate the starting position of the menu to center it
    float startY = centerY + ((OptionHeight * 4.5) + (spacing * 3)) * 0.4;
    float offsetX = -30.0; // Adjust this value to move the menu to the left
    float startX = centerX - (OptionWidth * 0.5) - offsetX; // Adjust the left position to center it

    Rect r;
    r.bot = startY;
    r.left = startX;
    r.center = 1;

    ggprint12(&r, 16, 0x00FBFF, "Jerry the Car Race Driver");

    r.bot -= (OptionHeight * 0.8) + spacing;
    r.height = 1;

    if (selectedOption == 0) {
        ggprint13(&r, 16, 0x00FF04, "Play");
    } else {
        ggprint13(&r, 16, 0xFFFFFF, "Play");
    }

    r.bot -= OptionHeight + spacing;
    if (selectedOption == 1) {
        ggprint13(&r, 16, 0xFFFF00, "Controls");
    } else {
        ggprint13(&r, 16, 0xFFFFFF, "Controls");
    }

    r.bot -= OptionHeight + spacing;
    if (selectedOption == 2) {
        ggprint13(&r, 16, 0xFF3333, "Exit");
    } else {
        ggprint13(&r, 16, 0xFFFFFF, "Exit");
    }
}


void drawControls(int xres, int yres, int selectedOption) {
    glClearColor(0.00f, 0.0f, 0.0f, 1.0f);

   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, xres, 0, yres);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

   float OptionWidth = xres * 0.08;
    float OptionHeight = yres * 0.2;
    float spacing = yres * 0.001;

   float centerX = xres * 0.5;
    float centerY = yres * 0.5;

   float startY = centerY + ((OptionHeight * 3.5) + (spacing * 2)) * 0.4;
    float offsetX = -30.0;
    float startX = centerX - (OptionWidth * 0.5) - offsetX; 
    Rect r;
    r.bot = startY;
    r.left = startX;
    r.center = 1;

    ggprint12(&r, 16, 0x00FBFF, "Controls");

    r.bot -= (OptionHeight * 0.8) + spacing;
    r.height = 1;

    if (selectedOption == 0) {
        ggprint13(&r, 16, 0xFFFF00, "W, A, S, D Keys are for the camera movement");
    } else {
        ggprint13(&r, 16, 0xFFFFFF, "W, A, S, D Keys are for the camera movement");
    }

    r.bot -= OptionHeight + spacing;
    if (selectedOption == 1) {
        ggprint13(&r, 16, 0xFF3333, "Up and Down Arrow Keys Make the car Foward and Back");
    } else {
        ggprint13(&r, 16, 0xFFFFFF, "Up and Down Arrow Keys Make the car Foward and Back");
    }

    r.bot -= OptionHeight + spacing;
    if (selectedOption == 2) {
        ggprint13(&r, 16, 0x00FF04, "Q is to turn left ");
    } else {
        ggprint13(&r, 16, 0xFFFFFF, "E is to turn right");
    }
}

float mouseMovement(XEvent *e, const bool get) {
	static float count = 0;
	static float prevx = e->xbutton.x;
	static float prevy = e->xbutton.y;

	if(!get) {
		if ( (e->xbutton.x != prevx) || (e->xbutton.y != prevy) ) {
			float dx = e->xbutton.x - prevx;
			float dy = e->xbutton.y - prevy;
			count += (sqrt((dx*dx) + (dy*dy)));
		}

		prevx = e->xbutton.x;
		prevy = e->xbutton.y;
		return 0;
	} else {
		return count;
	}
}

void CarMovement(std::string key) {
	if (key == "up") {
		                // Move the car forward in the calculated direction
                Pos1 += cos((PI*0.5) - theta);
                Pos3 += sin((PI*0.5) - theta);

                g.cameraPosition[0] = Pos1;
                g.cameraPosition[2] = Pos3 + 6.0f;
		g.cameraAngle = (PI*0.5)-theta;
	}
	if (key == "down") {
	 // Move the car backwards in the calculated direction
		Pos1 -= cos((PI*0.5) - theta);
                Pos3 -= sin((PI*0.5) - theta);
                g.cameraPosition[0] = Pos1;
                g.cameraPosition[2] = Pos3 + 6.0f;
		g.cameraAngle = (PI*0.5)-theta;
	}
	if (key == "q") {
		/*
		theta += 0.05f;
                Pos3 += cos((PI*0.5) - theta);
                g.cameraPosition[0] = Pos1;
                g.cameraPosition[2] = Pos3 + 6.0f;
		g.cameraAngle = (PI*0.5) - theta;

		std::cout<<g.cameraAngle<<","<<theta<<".";
		*/
		 theta += 0.05f;

                // Move the car in the calculated direction
               
//		Pos1 += cos((PI/2) - theta);
              Pos3 += sin((PI/2) - theta);

          //     g.cameraPosition[0] = Pos1;
                g.cameraPosition[2] = Pos3 + 6.0f;
		g.cameraAngle = (PI/2)-theta;

	}
}



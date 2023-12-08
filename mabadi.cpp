//Name: Mostafa Abadi
//Created: September 26th, 2023
#include "mabadi.h"
// Required for the time functions
using namespace std::chrono;  // This allows easier access to the chrono functions
// Function to load an OBJ file
int faceIndex = 0; 
OBJMesh loadOBJ(const std::string& racetrack) {
    OBJMesh mesh;
    //faceIndex();    
    std::vector<Vertex> vertices;
    std::ifstream file(racetrack);
    if (!file.is_open()) {
        return mesh;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);    
        std::string token;
        iss >> token;
        if (token == "v") {
            Vertex vertex;
            iss >> vertex.position[0] >> vertex.position[1] >> vertex.position[2];
            vertices.push_back(vertex);
        }
        else if (token == "f") {
            //This code below will be the face of the track. 
            for (int i = 0; i < 3; i++) {
                std::vector<Vertex>::size_type vIndex;
                std::string vertexStr;
                iss >> vertexStr;
               // So the forward slash in the code will pretty much cut up
               // The vertex or the face of the tack. 
                std::istringstream vertexStream(vertexStr);
                std::getline(vertexStream, token, '/');
                vIndex = std::stoi(token);
                if (vIndex <= vertices.size()) {
                    
                    mesh.vertices.push_back(vertices[vIndex - 1]);
                    //mesh.indices.push_back(vIndex - 1);
                    mesh.indices.push_back(faceIndex++);
                }
            }
        }

    }
    return mesh;
}
//This was meant to be the code to test the mouse timer functions but it ended calculating the mouse distance
int time_since_mouse_moved(const bool get) {
    static std::chrono::steady_clock::time_point lastMouseMoveTime = std::chrono::steady_clock::now();
    if (!get) {
       
        lastMouseMoveTime = std::chrono::steady_clock::now();
        return 0;
    }
    
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastMouseMoveTime);
    int elapsedTime = static_cast<int>(time_span.count());
    return elapsedTime;
}
OBJMesh racetrack = loadOBJ("racetrack.obj");
OBJMesh terrain = loadOBJ("terrain.obj");

//These functions below here to make the guard rails I could not really figure out I took them from the car.cpp framework. I was not able to make them display.
struct Vec3 {
    float x, y, z;
};
Vec3 subtract(const Vec3& v1, const Vec3& v2) {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}
Vec3 add(const Vec3& v1, const Vec3& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}
Vec3 interpolatePosition(const OBJMesh& racetrack, float distance) {
    //I had code here but it was not working for me.
    return {};
}
void drawGuardRails(const OBJMesh& racetrack) {
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float distance = 0.0f; distance < 100.0f; distance += 2.5f) {
        Vec3 position = interpolatePosition(racetrack, distance);
        glPushMatrix();
        glTranslatef(position.x, position.y, position.z);
       float railWidth = 0.2f;
        float railHeight = 5.0f;
        float railDepth = 0.2f;
        glBegin(GL_TRIANGLES);
       glVertex3f(-railWidth / 2, 0.0f, 0.0f);
        glVertex3f(railWidth / 2, 0.0f, 0.0f);
        glVertex3f(railWidth / 2, railHeight, 0.0f);
        glVertex3f(-railWidth / 2, railHeight, 0.0f);
        glVertex3f(-railWidth / 2, 0.0f, -railDepth);
        glVertex3f(railWidth / 2, 0.0f, -railDepth);
        glVertex3f(railWidth / 2, railHeight, -railDepth);
        glVertex3f(-railWidth / 2, railHeight, -railDepth);
        glEnd();
        glPopMatrix();
    }
}
void drawTrack() {
    glBegin(GL_TRIANGLES);
    for (std::vector<unsigned int>::size_type i = 0; i < terrain.indices.size(); i += 3) {
        unsigned int index1 = terrain.indices[i];
        unsigned int index2 = terrain.indices[i + 1];
        unsigned int index3 = terrain.indices[i + 2];
        glColor3f(0.0, 0.8, 0.0);  

        glVertex3fv(terrain.vertices[index1].position);
        glVertex3fv(terrain.vertices[index2].position);
        glVertex3fv(terrain.vertices[index3].position);
    }
    //glEnd();
    glEnd();
    //glPopMatrix();    
    //    
}    
void drawTerrain() {
    glBegin(GL_TRIANGLES);
    for (std::vector<unsigned int>::size_type i = 0; i < racetrack.indices.size(); i += 3) {
        unsigned int index1 = racetrack.indices[i];
        unsigned int index2 = racetrack.indices[i + 1];
        unsigned int index3 = racetrack.indices[i + 2];
       glColor3f(0.3, 0.3, 0.3);  // Black color for the race track
        glVertex3fv(racetrack.vertices[index1].position);
        glVertex3fv(racetrack.vertices[index2].position);
        glVertex3fv(racetrack.vertices[index3].position);
    }
    glEnd();
}
void drawTree3D() {
    // This is a measure of the Trunk or bottom of the tree
    float trunkRadius = 0.1f;
    float trunkHeight = 0.5f;
    int trunkSlices = 20;
    // Below functions will measure the trees
    float leavesRadius = 0.3f;
    float leavesHeight = 0.5f;
    int leavesSlices = 20;
    glPushMatrix(); 
    glScalef(5.0f, 5.0f, 5.0f); 

    glColor3f(0.5f, 0.35f, 0.05f); // Just draw the color of the trunk a Brown color
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= trunkSlices; i++) {
        float angle = 2.0f * M_PI * i / trunkSlices;
        float x = trunkRadius * cos(angle);
        float z = trunkRadius * sin(angle);
        glVertex3f(x, 0.0f, z);
        glVertex3f(x, trunkHeight, z);
    }
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f); // Green color
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, trunkHeight + leavesHeight, 0.0f); //This will measure the very top of the tree or leaves.
    for (int i = 0; i <= leavesSlices; i++) {
        float angle = 2.0f * M_PI * i / leavesSlices;
        float x = leavesRadius * cos(angle);
        float z = leavesRadius * sin(angle);
        glVertex3f(x, trunkHeight, z);
    }
    glEnd();
    glPopMatrix();  
}
void drawSphere(float radius, int slices, int stacks, GLfloat r, GLfloat g, GLfloat b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= stacks; ++i) {
        float phi = M_PI * i / stacks;
        for (int j = 0; j <= slices; ++j) {
            float theta = 2.0f * M_PI * j / slices;
            float x = radius * sin(phi) * cos(theta);
            float y = radius * cos(phi);
            float z = radius * sin(phi) * sin(theta);
            glVertex3f(x, y, z);
        }
    }
    glEnd();
}

void drawStoplight() {
    float poleRadius = 0.05f;
    float poleHeight = 2.0f;

   float lightRadius = 0.2f;

    glPushMatrix();
    
    glTranslatef(0.0f, -1.0f, 0.0f);

    // This function below will draw the color of the pole and also make it into the shape we want it which is a cylinder.
    glColor3f(0.3f, 0.3f, 0.3f); // Gray color
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 20; i++) {
        float angle = 2.0f * M_PI * i / 20;
        float x = poleRadius * cos(angle);
        float z = poleRadius * sin(angle);
        glVertex3f(x, 0.0f, z);
        glVertex3f(x, poleHeight, z);
    }
    glEnd();

    //This will make one of the colors red 
    glTranslatef(0.0f, poleHeight, 0.0f);
    drawSphere(lightRadius, 20, 20, 1.0f, 0.0f, 0.0f);

    // One of the ligts will be yellow
    glTranslatef(0.0f, lightRadius * 2.0f, 0.0f);
    drawSphere(lightRadius, 20, 20, 1.0f, 1.0f, 0.0f);

    //One of the lights will be green 
    glTranslatef(0.0f, lightRadius * 2.0f, 0.0f);
    drawSphere(lightRadius, 20, 20, 0.0f, 1.0f, 0.0f);

    glPopMatrix();
}

void drawStartLine() {
    float lineWidth = 10.0f;
    float lineLength = 6.3555f;

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f);  
    glColor3f(1.0f, 1.0f, 1.0f);  // White color
    glLineWidth(lineWidth);
    glBegin(GL_LINES);
    glVertex3f(-lineLength / 2.0f, 0.0f, 0.0f);
    glVertex3f(lineLength / 2.0f, 0.0f, 0.0f);
    glEnd();

    glPopMatrix();

}

void drawMoon(float radius, int slices, int stacks, GLfloat r, GLfloat g, GLfloat b) {
    glColor3f(255, 255, 255);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= stacks; ++i) {
        float phi = M_PI * i / stacks;
        for (int j = 0; j <= slices; ++j) {
            float theta = 2.0f * M_PI * j / slices;
            float x = radius * sin(phi) * cos(theta);
            float y = radius * cos(phi);
            float z = radius * sin(phi) * sin(theta);
            glVertex3f(x, y, z);
        }
    }
    glEnd();
}
//This function below just pretty much adjusts the positions of functions and we call startline, stoplight, moon, and stars in here. Then we call drawScene in in car.cpp
void drawScene() {

    glPopMatrix();

    glPushMatrix();
    glTranslatef(13.735f, 0.6f, 7.0f);  
    drawStartLine();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9.5f, 0.7f, -2.0f); 
    drawStoplight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.5f, 0.8f, -2.0f); 
    drawStoplight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5f, 0.0f, -2.0f); 
    drawTree3D();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, 6.0f);
    drawTree3D();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f, -0.2f, -2.0f); 
    drawTree3D();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8.0f, -0.2f, -2.0f); 
    drawTree3D();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(9.0f, -0.2f, -14.0f); 
    drawTree3D();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.0f, 20.0f, -70.0f); 
    drawMoon(3.0f, 50, 50, 1.0f, 1.0f, 1.0f); 
    glPopMatrix();

}

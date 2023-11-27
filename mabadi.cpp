//Name: Mostafa Abadi
//Created: September 26th, 2023
#include "mabadi.h"
// Required for the time functions
using namespace std::chrono;  // This allows easier access to the chrono functions
// Function to load an OBJ file
int faceIndex = 0; // Variable to keep track of face index
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
            // Vertex position
            Vertex vertex;
            iss >> vertex.position[0] >> vertex.position[1] >> vertex.position[2];
            vertices.push_back(vertex);
        }
        else if (token == "f") {
            // Face 
            for (int i = 0; i < 3; i++) {
                std::vector<Vertex>::size_type vIndex;
                std::string vertexStr;
                iss >> vertexStr;
                // Split the vertex string into parts using '/'
                std::istringstream vertexStream(vertexStr);
                std::getline(vertexStream, token, '/');
                vIndex = std::stoi(token);
                std::cout << "Vertex Index: " << vIndex << std::endl;
                if (vIndex <= vertices.size()) {
                    // Valid vertex index
                    mesh.vertices.push_back(vertices[vIndex - 1]);
                    //mesh.indices.push_back(vIndex - 1);
                    mesh.indices.push_back(faceIndex++);
                }
            }
        }

    }
    return mesh;
}
//Mouse Timer functions.
int time_since_mouse_moved(const bool get)
{
static std::chrono::steady_clock::time_point lastMouseMoveTime = std::chrono::steady_clock::now();
if (!get) {
// Update the time
        lastMouseMoveTime = std::chrono::steady_clock::now();
        return 0;
    }
    // Calculate the time difference
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastMouseMoveTime);
    int elapsedTime = static_cast<int>(time_span.count());
    return elapsedTime;
}

OBJMesh racetrack = loadOBJ("racetrack.obj");

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
    //I will put some code here
     return {};
}
    // Draw guard rails along the racetrack
void drawGuardRails(const OBJMesh& racetrack) {
    glColor3f(1.0f, 1.0f, 1.0f);

    for (float distance = 0.0f; distance < 100.0f; distance += 2.5f) {
        Vec3 position = interpolatePosition(racetrack, distance);

        glPushMatrix();
        glTranslatef(position.x, position.y, position.z);
        
        // Draw the  guard rail
float railWidth = 0.2f;
float railHeight = 5.0f;
float railDepth = 0.2f;

glBegin(GL_QUADS);

// faces below
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
    for (std::vector<unsigned int>::size_type i = 0; i < racetrack.indices.size(); i += 3) {
        unsigned int index1 = racetrack.indices[i];
        unsigned int index2 = racetrack.indices[i + 1];
        unsigned int index3 = racetrack.indices[i + 2];
        // Assuming racetrack.vertices is a vector of Vertex
        glVertex3fv(racetrack.vertices[index1].position);
        glVertex3fv(racetrack.vertices[index2].position);
        glVertex3fv(racetrack.vertices[index3].position);
    }
    glEnd();
 // I got some code  from drawStreet to create the double yellow line
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.2f); // double yellow line color
    float w = 0.1;
    float d = 100.0;
    float h = 0.01;
    // Draw double yellow line
    glPushMatrix();
    glTranslatef(-0.15f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(w, h, -d);
    glVertex3f(-w, h, -d);
    glVertex3f(-w, h, d);
    glVertex3f(w, h, d);
    glEnd();
    glPopMatrix();    
    
}    
    
    
    
    
    
    
    



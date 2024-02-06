#include <GL/glut.h>
#include <GL/glu.h>

// coordinates of the cube
GLfloat cube[8][3] = {
    {-0.5, 0.5, 0.5},  // Vertex 0
    {0.5, 0.5, 0.5},   // Vertex 1
    {0.5, -0.5, 0.5},  // Vertex 2
    {-0.5, -0.5, 0.5}, // Vertex 3
    {-0.5, 0.5, -0.5}, // Vertex 4
    {0.5, 0.5, -0.5},  // Vertex 5
    {0.5, -0.5, -0.5}, // Vertex 6
    {-0.5, -0.5, -0.5} // Vertex 7
};

// camera position coordinates
GLfloat cx = 0, cy = 0, cz = 5;

// function to initialize the OpenGL settings
void init()
{
    glClearColor(0, 0, 0, 1); // Set the background color to black
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D rendering
    // These are for camera settings
    glMatrixMode(GL_PROJECTION);    // Set the matrix mode to projection
    glLoadIdentity();               // Load the identity matrix
    glFrustum(-1, 1, -1, 1, 2, 10); // Set the perspective projection
    glMatrixMode(GL_MODELVIEW);     // Set the matrix mode to modelview
    glEnable(GL_LIGHTING); // Enable lighting
    glEnable(GL_LIGHT0); // Enable light 0
}

// function to draw a square
void drawSquare(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
    glBegin(GL_POLYGON); // Begin drawing a polygon
    glVertex3fv(A);      // Specify the first vertex
    glVertex3fv(B);      // Specify the second vertex
    glVertex3fv(C);      // Specify the third vertex
    glVertex3fv(D);      // Specify the fourth vertex
    glEnd();             // End drawing the polygon
}

// function to draw the cube
void drawCube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
    glColor3f(1, 0, 0);         // Set the color to red
    drawSquare(V0, V1, V2, V3); // Draw the front face of the cube
    glColor3f(0, 1, 0);         // Set the color to green
    drawSquare(V0, V1, V5, V4); // Draw the top face of the cube
    glColor3f(0, 0, 1);         // Set the color to blue
    drawSquare(V1, V2, V6, V5); // Draw the right face of the cube
    glColor3f(1, 1, 0);         // Set the color to yellow
    drawSquare(V2, V3, V7, V6); // Draw the back face of the cube
    glColor3f(1, 0, 1);         // Set the color to magenta
    drawSquare(V3, V0, V4, V7); // Draw the bottom face of the cube
    glColor3f(0, 1, 1);         // Set the color to cyan
    drawSquare(V4, V5, V6, V7); // Draw the left face of the cube
}

// function to handle keyboard events
void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'x':
        cx = cx - 0.5; // Move the camera left along the x-axis
        break;
    case 'X':
        cx = cx + 0.5; // Move the camera right along the x-axis
        break;

    case 'y':
        cy = cy - 0.5; // Move the camera down along the y-axis
        break;
    case 'Y':
        cy = cy + 0.5; // Move the camera up along the y-axis
        break;

    case 'z':
        cz = cz - 0.5; // Move the camera closer along the z-axis
        break;
    case 'Z':
        cz = cz + 0.5; // Move the camera farther along the z-axis
        break;

    default:
        break;
    }
    glutPostRedisplay(); // Mark the current window as needing to be redisplayed
}

void renderFunction()
{
    init();                                             // Initialize the OpenGL settings
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers

    glLoadIdentity();   // Load the identity matrix
    GLfloat position[] = {0, 1, 0 , 1}; // Light position
    GLfloat color[] = {1, 0, 0 ,1}; // Light color
    glLightfv(GL_LIGHT0, GL_POSITION, position); // Set the light position
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color); // Set the light color                                                       // Load the identity matrix
    gluLookAt(cx, cy, cz, 0, 0, 0, 0, 1, 0);                                          // Set the camera position and orientation
    drawCube(cube[0], cube[1], cube[2], cube[3], cube[4], cube[5], cube[6], cube[7]); // Draw the cube
    glutSwapBuffers();                                                                // Swap the front and back buffers to display the rendered image
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                    // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Set the display mode
    glutInitWindowSize(500, 500);                             // Set the window size
    glutInitWindowPosition(200, 100);                         // Set the window position
    glutCreateWindow("Camera Introduction : Cube");           // Create a window with the specified title
    glutDisplayFunc(renderFunction);                          // Set the display callback function
    glutKeyboardFunc(myKeyboardFunc);                         // Set the keyboard callback function
    glutMainLoop();                                           // Enter the main event loop
    return 0;
}
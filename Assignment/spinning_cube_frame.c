#include <GL/glut.h>

// coordinates of the cube
GLfloat cube[8][3] = {
    {-0.5, -0.5, 0.5},  // left bottom front
    {-0.5, 0.5, 0.5},   // left top front
    {0.5, 0.5, 0.5},    // right top front
    {0.5, -0.5, 0.5},   // right bottom front
    {-0.5, -0.5, -0.5}, // left bottom back
    {-0.5, 0.5, -0.5},  // left top back
    {0.5, 0.5, -0.5},   // right top back
    {0.5, -0.5, -0.5},  // right bottom back
};

// angle of rotation
GLfloat angle = 0;

// idle function
void spinCube()
{
    angle = angle + 0.1;
    if (angle >= 360)
    {
        angle = 0; // Reset the angle to 0
    }
    glutPostRedisplay();
}

// function to draw a square frame
void drawSquareFrame(GLfloat v1[], GLfloat v2[], GLfloat v3[], GLfloat v4[])
{
    glBegin(GL_LINE_LOOP);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3fv(v3);
    glVertex3fv(v4);
    glEnd();
}

// function to draw the wireframe of the cube
void drawCubeWireFrame()
{
    drawSquareFrame(cube[0], cube[1], cube[2], cube[3]); // front face
    drawSquareFrame(cube[3], cube[2], cube[6], cube[7]); // right face
    drawSquareFrame(cube[0], cube[3], cube[7], cube[4]); // bottom face
    drawSquareFrame(cube[1], cube[5], cube[6], cube[2]); // top face
    drawSquareFrame(cube[0], cube[1], cube[5], cube[4]); // left face
    drawSquareFrame(cube[4], cube[5], cube[6], cube[7]); // back face
}

// function to set the camera view
void cameraView()
{
    glEnable(GL_DEPTH_TEST);                            // Enable depth testing for 3D rendering
    glMatrixMode(GL_PROJECTION);                        // Set the matrix mode to projection
    glLoadIdentity();                                   // Load the identity matrix
    glFrustum(-1, 1, -1, 1, 2, 10);                     // Set the frustum for perspective projection
    glMatrixMode(GL_MODELVIEW);                         // Set the matrix mode to modelview
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
    glLoadIdentity();                                   // Load the identity matrix
    gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);               // Set the camera position, look at point, and up vector
    glRotatef(angle, 0.5, 1, 0);                        // Rotate the scene around the y-axis
}

// function to render the scene
void renderFunction()
{
    glClearColor(0, 0, 0, 1); // Set the clear color to black
    cameraView();             // Set the camera view

    drawCubeWireFrame(); // Draw the wireframe of the cube
    glutSwapBuffers();   // Swap the front and back buffers for double buffering
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                    // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Set the display mode
    glutInitWindowSize(500, 500);                             // Set the window size
    glutInitWindowPosition(200, 100);                         // Set the window position
    glutCreateWindow("Spinning Cube Wireframe");              // Create a window with the specified title
    glutDisplayFunc(renderFunction);                          // Set the display callback function
    glutIdleFunc(spinCube);                                   // Set the idle callback function
    glutMainLoop();                                           // Enter the main event loop
    return 0;
}
#include <GL/glut.h>

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

// angle of rotation
GLfloat angle = 45;

// function to spin the cube
void spinCube()
{
    angle = angle + 0.2;
    if (angle >= 360)
    {
        angle = 0;
    }
    glutPostRedisplay(); // Request redisplay to update the cube's rotation
}

// function to draw a square
void drawSquare(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
}

// function to draw the cube
void drawCube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
    glColor3f(1, 0, 0);         // Set color to red
    drawSquare(V0, V1, V2, V3); // Draw front face of the cube
    glColor3f(0, 1, 0);         // Set color to green
    drawSquare(V0, V1, V5, V4); // Draw top face of the cube
    glColor3f(0, 0, 1);         // Set color to blue
    drawSquare(V1, V2, V6, V5); // Draw right face of the cube
    glColor3f(1, 1, 0);         // Set color to yellow
    drawSquare(V2, V3, V7, V6); // Draw back face of the cube
    glColor3f(1, 0, 1);         // Set color to magenta
    drawSquare(V3, V0, V4, V7); // Draw left face of the cube
    glColor3f(0, 1, 1);         // Set color to cyan
    drawSquare(V4, V5, V6, V7); // Draw bottom face of the cube
}

void renderFunction()
{
    glClearColor(0, 0, 0, 1); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // drawing cube
    glLoadIdentity();
    glRotatef(angle, 1, 1, 1); // Rotate the cube around the axis (1, 1, 1)
    drawCube(cube[0], cube[1], cube[2], cube[3], cube[4], cube[5], cube[6], cube[7]);
    glutSwapBuffers(); // Swap the front and back buffers to display the cube
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                    // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Set display mode
    glutInitWindowSize(500, 500);                             // Set window size
    glutInitWindowPosition(200, 100);                         // Set window position
    glutCreateWindow("Spinning Cube");                        // Create window with title "Spinning Cube"
    glutDisplayFunc(renderFunction);                          // Set the display callback function
    glutIdleFunc(spinCube);                                   // Set the idle callback function
    glutMainLoop();                                           // Enter the event processing loop
    return 0;
}
#include <GL/glut.h>

// coordinates for the pyramid with 4 triangular faces
GLfloat pyramid[4][3] = {
    {0, 0.6, 0},      // top
    {-0.75, -0.5, 0}, // bottom left
    {0.5, -0.5, 0.6}, // bottom right
    {0.5, -0.5, -0.6} // bottom back
};

// gradient colors for the pyramid sides
GLfloat colors[4][3][3] = {
    {{1, 0, 0}, {1, 0.5, 0}, {1, 1, 0}},        // red to orange to yellow
    {{0, 0, 1}, {0, 0.5, 1}, {0, 1, 1}},        // blue to light blue to cyan
    {{0, 1, 0}, {0.5, 1, 0}, {1, 1, 0}},        // green to lime to yellow
    {{0, 0.5, 0.5}, {0, 0.75, 0.75}, {0, 1, 1}} // teal to light teal to cyan
};

// angle of rotation
GLfloat angle = 10;

// function to draw a triangular face of the pyramid
void drawTriangleFace(GLfloat first[], GLfloat second[], GLfloat third[], GLfloat color[][3])
{
    glBegin(GL_TRIANGLES);
    glColor3fv(color[0]);   // set color for the first vertex
    glVertex3fv(first);     // specify the first vertex
    glColor3fv(color[1]);   // set color for the second vertex
    glVertex3fv(second);    // specify the second vertex
    glColor3fv(color[2]);   // set color for the third vertex
    glVertex3fv(third);     // specify the third vertex
    glEnd();
}

// function to render the scene
void renderFunction()
{
    glClearColor(0, 0, 0, 1);               // set the clear color to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // clear the color and depth buffers
    glEnable(GL_DEPTH_TEST);                // enable depth testing

    glLoadIdentity();                       // reset the modelview matrix
    glRotatef(angle, 0, 1, 0);               // rotate the scene around the y-axis
    glShadeModel(GL_SMOOTH);                 // enable smooth shading

    // draw the triangular faces of the pyramid
    drawTriangleFace(pyramid[0], pyramid[1], pyramid[2], colors[0]);
    drawTriangleFace(pyramid[0], pyramid[2], pyramid[3], colors[1]);
    drawTriangleFace(pyramid[0], pyramid[3], pyramid[1], colors[2]);
    drawTriangleFace(pyramid[1], pyramid[2], pyramid[3], colors[3]);

    glutSwapBuffers();                      // swap the front and back buffers
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                   // initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   // set the display mode
    glutInitWindowSize(500, 500);            // set the window size
    glutInitWindowPosition(200, 100);         // set the window position
    glutCreateWindow("3D Pyramid");           // create a window with the specified title
    glutDisplayFunc(renderFunction);          // set the display callback function
    glutMainLoop();                          // enter the event processing loop
    return 0;
}
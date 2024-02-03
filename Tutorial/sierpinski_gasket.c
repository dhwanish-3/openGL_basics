#include <GL/glut.h>

// coordinates of tetrahedron
GLfloat tetrahedron[4][3] = {
    {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0, 0.5, 0.5}, {0, -0.05, -0.5}};

// gradient colors for the tetrahedron sides
GLfloat colors[4][3][3] = {
    {{1, 0, 0}, {1, 0.5, 0}, {1, 1, 0}},        // red to orange to yellow
    {{0, 0, 1}, {0, 0.5, 1}, {0, 1, 1}},        // blue to light blue to cyan
    {{0, 1, 0}, {0.5, 1, 0}, {1, 1, 0}},        // green to lime to yellow
    {{0, 0.5, 0.5}, {0, 0.75, 0.75}, {0, 1, 1}} // teal to light teal to cyan
};

// Function to draw a triangle face
void drawTriangleFace(GLfloat first[], GLfloat second[], GLfloat third[], GLfloat color[][3])
{
    glBegin(GL_TRIANGLES);
    glColor3fv(color[0]);
    glVertex3fv(first);
    glColor3fv(color[1]);
    glVertex3fv(second);
    glColor3fv(color[2]);
    glVertex3fv(third);
    glEnd();
}

// Function to draw the tetrahedron
void drawTetrahedron(GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[])
{
    drawTriangleFace(V1, V2, V3, colors[0]); // draw the first face
    drawTriangleFace(V1, V3, V4, colors[1]); // draw the second face
    drawTriangleFace(V2, V3, V4, colors[2]); // draw the third face
    drawTriangleFace(V1, V2, V4, colors[3]); // draw the fourth face
}

// Function to recursively draw the Sierpinski Gasket
void drawSierpenskiGasket(GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], int n)
{
    if (n > 0)
    {
        // Calculate the midpoints of the edges
        GLfloat V12[3], V23[3], V31[3], V14[3], V24[3], V34[3];
        V12[0] = (V1[0] + V2[0]) / 2; // midpoint of V1 and V2
        V12[1] = (V1[1] + V2[1]) / 2;
        V12[2] = (V1[2] + V2[2]) / 2;
        V23[0] = (V2[0] + V3[0]) / 2; // midpoint of V2 and V3
        V23[1] = (V2[1] + V3[1]) / 2;
        V23[2] = (V2[2] + V3[2]) / 2;
        V31[0] = (V3[0] + V1[0]) / 2; // midpoint of V3 and V1
        V31[1] = (V3[1] + V1[1]) / 2;
        V31[2] = (V3[2] + V1[2]) / 2;
        V14[0] = (V1[0] + V4[0]) / 2; // midpoint of V1 and V4
        V14[1] = (V1[1] + V4[1]) / 2;
        V14[2] = (V1[2] + V4[2]) / 2;
        V24[0] = (V2[0] + V4[0]) / 2; // midpoint of V2 and V4
        V24[1] = (V2[1] + V4[1]) / 2;
        V24[2] = (V2[2] + V4[2]) / 2;
        V34[0] = (V3[0] + V4[0]) / 2; // midpoint of V3 and V4
        V34[1] = (V3[1] + V4[1]) / 2;
        V34[2] = (V3[2] + V4[2]) / 2;

        // Recursively draw smaller Sierpinski Gaskets
        drawSierpenskiGasket(V1, V12, V31, V14, n - 1); // draw the first smaller gasket
        drawSierpenskiGasket(V12, V2, V23, V24, n - 1); // draw the second smaller gasket
        drawSierpenskiGasket(V31, V23, V3, V34, n - 1); // draw the third smaller gasket
        drawSierpenskiGasket(V14, V24, V34, V4, n - 1); // draw the fourth smaller gasket
    }
    else
    {
        // Draw the tetrahedron when recursion depth is 0
        drawTetrahedron(V1, V2, V3, V4);
    }
}

// Function to render the scene
void renderFunction()
{
    glClearColor(0, 0, 0, 1);                           // set the background color to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color and depth buffers

    // Draw the Sierpinski Gasket
    drawSierpenskiGasket(tetrahedron[0], tetrahedron[1], tetrahedron[2], tetrahedron[3], 2); // draw the Sierpinski Gasket with recursion depth 2
    glutSwapBuffers();                                                                       // swap the front and back buffers to display the rendered scene
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                    // initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // set the display mode
    glutInitWindowSize(500, 500);                             // set the window size
    glutInitWindowPosition(200, 100);                         // set the window position
    glutCreateWindow("Sierpenski Gasket");                    // create a window with the specified title
    glutDisplayFunc(renderFunction);                          // set the display callback function
    glutMainLoop();                                           // enter the GLUT event processing loop
    return 0;
}
#include <GL/freeglut.h>
#include <GL/gl.h>

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set the clear color for the window to black
    glClear(GL_COLOR_BUFFER_BIT);     // Clear the color buffer with the previously set clear color
    glColor3f(1.0, 1.0, 1.0);         // Set the current color of the pen to white
    glBegin(GL_POLYGON);              // Begin drawing a polygon
    glVertex2f(-0.5, -0.5);           // Specify the first vertex of the polygon
    glVertex2f(-0.5, 0.5);            // Specify the second vertex of the polygon
    glVertex2f(0.5, 0.5);             // Specify the third vertex of the polygon
    glVertex2f(0.5, -0.5);            // Specify the fourth vertex of the polygon
    glEnd();                          // End drawing the polygon
    glFlush();                        // Force the execution of OpenGL commands in finite time
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                          // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE);               // Set the display mode to single buffer mode
    glutInitWindowSize(500, 500);                   // Set the initial window size to 500x500 pixels
    glutInitWindowPosition(100, 100);               // Set the initial window position to (100, 100)
    glutCreateWindow("OpenGL - First window demo"); // Create a window with the specified title
    glutDisplayFunc(renderFunction);                // Set the display function to renderFunction
    glutMainLoop();                                 // Enter the main event loop of GLUT
    return 0;
}
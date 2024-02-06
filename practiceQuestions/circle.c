#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int lines = 100;                                 // Number of lines to draw
    GLfloat twicePi = 2.0f * 3.14; // Value of 2 * pi

    glBegin(GL_LINE_LOOP); // Begin drawing lines
    for (int i = 0; i <= lines; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / lines)),
            y + (radius * sin(i * twicePi / lines)));
    }
    glEnd(); // End drawing lines
}

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to white
    glClear(GL_COLOR_BUFFER_BIT);     // Clear color buffer
    glColor3f(1.0, 1.0, 1.0);         // Set drawing color to blue

    drawCircle(0.0, 0.0, 0.9); // Draw a circle at the origin with radius 0.5
    glutSwapBuffers();         // Swap the front and back buffers (double buffering)
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);               // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE);    // Set display mode to double buffer
    glutInitWindowSize(500, 500);        // Set window size to 500x500 pixels
    glutInitWindowPosition(100, 100);    // Set window position
    glutCreateWindow("OpenGL - Circle"); // Create window with title
    glutDisplayFunc(renderFunction);     // Set render function
    glutMainLoop();                      // Enter main event loop
    return 0;
}
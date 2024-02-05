#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float angle = 0.0; // Global variable to store the rotation angle

void mySpecialFunc(int key, int x, int y)
{
    // if pressed key is left arrow key
    if (key == GLUT_KEY_LEFT)
    {
        angle += 30;         // Increase the rotation angle by 30 degrees
        glutPostRedisplay(); // Post redisplay event to redraw the triangle
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        angle -= 30;         // Decrease the rotation angle by 30 degrees
        glutPostRedisplay(); // Post redisplay event to redraw the triangle
    }
}

void drawTriangle()
{
    glPushMatrix();            // Push the current matrix onto the stack
    glRotatef(angle, 0, 0, 1); // Rotate the triangle by the current angle
    glBegin(GL_TRIANGLES);     // Begin drawing triangles
    glVertex2f(0.0, 0.0);      // Set first vertex of triangle
    glVertex2f(0.5, 0.0);      // Set second vertex of triangle
    glVertex2f(0.25, 0.5);     // Set third vertex of triangle
    glEnd();                   // End drawing triangles
    glPopMatrix();             // Pop the matrix from the stack
}

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT);     // Clear color buffer
    glColor3f(1.0, 1.0, 1.0);         // Set drawing color to white
    drawTriangle();                   // Draw triangle
    glFlush();                        // Flush drawing commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE);             // Set display mode to single buffer
    glutInitWindowSize(500, 500);                 // Set window size to 500x500 pixels
    glutInitWindowPosition(100, 100);             // Set window position
    glutCreateWindow("OpenGL - Rotate Triangle"); // Create window with title

    // Registering a keyboard event callback
    // MyKeyboardFunc will now get called on any key board button press
    glutSpecialFunc(mySpecialFunc);

    glutDisplayFunc(renderFunction); // Set render function
    glutMainLoop();                  // Enter main event loop
    return 0;
}
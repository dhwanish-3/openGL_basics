#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to draw a triangle with 3 lines and recursively draw triangles inside it
void drawTriangles(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, int depth)
{
    // draw the triangle
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    // calculate the midpoints of the triangle
    GLfloat x12 = (x1 + x2) / 2, y12 = (y1 + y2) / 2;
    GLfloat x23 = (x2 + x3) / 2, y23 = (y2 + y3) / 2;
    GLfloat x31 = (x3 + x1) / 2, y31 = (y3 + y1) / 2;

    // recursively draw triangles inside the triangle
    if (depth < 4)
    {
        drawTriangles(x1, y1, x12, y12, x31, y31, depth + 1);
        drawTriangles(x12, y12, x2, y2, x23, y23, depth + 1);
        drawTriangles(x31, y31, x23, y23, x3, y3, depth + 1);
    }
}

void renderFunction()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glClear(GL_COLOR_BUFFER_BIT);     // Clear color buffer
    glColor3f(1.0, 0.0, 0.0);         // Set drawing color to red

    // Draw the triangles
    drawTriangles(-0.9, -0.9, 0.9, -0.9, 0.0, 0.7, 0);
    glFlush(); // Flush drawing commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE);                       // Set display mode to single buffer
    glutInitWindowSize(500, 500);                           // Set window size to 500x500 pixels
    glutInitWindowPosition(100, 100);                       // Set window position
    glutCreateWindow("OpenGL - Triangles inside Triangle"); // Create window with title
    glutDisplayFunc(renderFunction);                        // Set render function
    glutMainLoop();                                         // Enter main event loop
    return 0;
}
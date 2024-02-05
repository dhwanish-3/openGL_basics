#include <GL/glut.h>
#include <math.h>

// Function to draw a circle using OpenGL
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int vertices = 100;
    GLfloat TwoPi = 2.0f * 3.14;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= vertices; i++)
    {
        glVertex2f(
            x + (radius * cos(i * TwoPi / vertices)),  // x-coordinate of the vertex
            y + (radius * sin(i * TwoPi / vertices))); // y-coordinate of the vertex
    }
    glEnd();
}

// Function to render the scene
void renderFunction()
{
    glClearColor(0, 0, 0, 1);     // Set the clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    drawCircle(0, 0, 0.5); // Draw a circle at the origin with radius 0.5

    glFlush(); // Flush the OpenGL pipeline
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(500, 500);                // Set the window size
    glutInitWindowPosition(200, 100);            // Set the window position
    glutCreateWindow("Simple Circle");           // Create a window with the given title
    glutDisplayFunc(renderFunction);             // Set the display callback function
    glutMainLoop();                              // Enter the main loop
    return 0;
}
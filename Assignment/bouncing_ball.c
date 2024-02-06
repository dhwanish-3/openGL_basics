#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLfloat center[2] = {0.5, 0}; // Center coordinates of the ball

int direction = 0; // Direction of the ball's movement

GLfloat movement = 0.005; // Amount of movement for each frame

void bounceBall()
{
    if (direction == 0)
    { // Ball moving towards bottom-left
        center[0] = center[0] - movement;
        center[1] = center[1] - movement;
        if (center[0] <= -0.5f || center[1] <= -0.5f)
        {                  // Check if ball reaches left or bottom edge
            direction = 1; // Change direction to move towards top-left
        }
    }
    else if (direction == 1)
    { // Ball moving towards top-left
        center[0] = center[0] - movement;
        center[1] = center[1] + movement;
        if (center[0] <= -0.5f || center[1] >= 0.5f)
        {                  // Check if ball reaches left or top edge
            direction = 2; // Change direction to move towards top-right
        }
    }
    else if (direction == 2)
    { // Ball moving towards top-right
        center[0] = center[0] + movement;
        center[1] = center[1] + movement;
        if (center[0] >= 0.5f || center[1] >= 0.5f)
        {                  // Check if ball reaches right or top edge
            direction = 3; // Change direction to move towards bottom-right
        }
    }
    else if (direction == 3)
    { // Ball moving towards bottom-right
        center[0] = center[0] + movement;
        center[1] = center[1] - movement;
        if (center[0] >= 0.5f || center[1] <= -0.5f)
        {                  // Check if ball reaches right or bottom edge
            direction = 0; // Change direction to move towards bottom-left
        }
    }
    glutPostRedisplay(); // Trigger display function to redraw the scene
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int vertices = 100; // Number of vertices to approximate the circle

    GLfloat twicePi = 2.0f * 3.14; // Value of 2 * pi

    glColor3f(1, 0, 0); // Set color to red

    glBegin(GL_POLYGON); // Begin drawing a polygon (circle)

    for (int i = 0; i <= vertices; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / vertices)), // Calculate x-coordinate of vertex
            y + (radius * sin(i * twicePi / vertices))  // Calculate y-coordinate of vertex
        );
    }

    glEnd(); // End drawing the polygon
}

void renderFunction()
{
    glClearColor(0, 0, 0, 1);     // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw the circle at the center coordinates with a radius of 0.5
    drawCircle(center[0], center[1], 0.5);

    glFlush(); // Flush the drawing commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);                // Set window size
    glutInitWindowPosition(200, 100);            // Set window position
    glutCreateWindow("Bouncing Ball Animation"); // Create a window with the given title
    glutDisplayFunc(renderFunction);             // Set the display function
    glutIdleFunc(bounceBall);                    // Set the idle function
    glutMainLoop();                              // Enter the main loop
    return 0;
}
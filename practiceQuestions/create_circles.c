#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    GLfloat x, y;
} Point;

typedef struct
{
    Point centre;
    int color;
} Circle;

typedef struct
{
    float r, g, b;
} Color;

Circle circles[100]; // Array to store circles
int count = 0;       // Counter for the number of circles

Color colors[5] = {
    {1.0, 0.0, 0.0}, // Red
    {0.0, 1.0, 0.0}, // Green
    {0.0, 0.0, 1.0}, // Blue
    {1.0, 1.0, 0.0}, // Yellow
    {1.0, 0.0, 1.0}  // Magenta
};

void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && count < 100)
    {
        // Convert mouse coordinates to OpenGL coordinates
        circles[count].centre.x = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        circles[count].centre.y = 1 - (float)y / glutGet(GLUT_WINDOW_HEIGHT) * 2;
        circles[count].color = count % 5; // Assign color based on count
        count++;
        glutPostRedisplay(); // Trigger redisplay
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && count > 0)
    {
        // Change the color of the last added circle
        circles[count - 1].color = (circles[count - 1].color + 1) % 5;
        glutPostRedisplay(); // Trigger redisplay
    }
}

void drawCircle(float x, float y, float radius)
{
    int i;
    int lineAmount = 100;
    float twicePi = 2.0f * 3.14;

    glBegin(GL_POLYGON); // Begin drawing a polygon
    for (i = 0; i <= lineAmount; i++)
    {
        // Calculate the vertex positions of the circle
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount)));
    }
    glEnd(); // End drawing the polygon
}

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT);     // Clear color buffer
    glColor3f(1.0, 1.0, 1.0);         // Set drawing color to white

    for (int i = 0; i < count; i++)
    {
        // Set the color of the circle based on its assigned color
        glColor3f(colors[circles[i].color].r, colors[circles[i].color].g, colors[circles[i].color].b);
        drawCircle(circles[i].centre.x, circles[i].centre.y, 0.25); // Draw the circle
    }
    glFlush(); // Flush drawing commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE);            // Set display mode to single buffer
    glutInitWindowSize(500, 500);                // Set window size to 500x500 pixels
    glutInitWindowPosition(100, 100);            // Set window position
    glutCreateWindow("OpenGL - Create Circles"); // Create window with title
    glutDisplayFunc(renderFunction);             // Set render function
    glutMouseFunc(mouseClick);                   // Set mouse click handler
    glutMainLoop();                              // Enter main event loop
    return 0;
}
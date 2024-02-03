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

Circle circles[100];
int count = 0;

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
        circles[count].centre.x = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        circles[count].centre.y = 1 - (float)y / glutGet(GLUT_WINDOW_HEIGHT) * 2;
        circles[count].color = count % 5;
        count++;
        glutPostRedisplay();
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && count > 0)
    {
        circles[count - 1].color = (circles[count - 1].color + 1) % 5;
        glutPostRedisplay();
    }
}

void drawCircle(float x, float y, float radius)
{
    int i;
    int lineAmount = 100;
    float twicePi = 2.0f * 3.14;

    glBegin(GL_POLYGON);
    for (i = 0; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount)));
    }
    glEnd();
}

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT);     // Clear color buffer
    glColor3f(1.0, 1.0, 1.0);         // Set drawing color to white

    for (int i = 0; i < count; i++)
    {
        glColor3f(colors[circles[i].color].r, colors[circles[i].color].g, colors[circles[i].color].b);
        drawCircle(circles[i].centre.x, circles[i].centre.y, 0.25);
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
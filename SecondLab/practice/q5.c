#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    GLfloat x1, y1, x2, y2;
} Line;

Line *lines = NULL;                        // Array to store the lines drawn by the user
int linesCount = 0;                        // Number of lines drawn
int isButtonDown = 0;                      // Flag to indicate if the left mouse button is pressed
int windowWidth = 500, windowHeight = 500; // Width and height of the window
GLfloat lastX = 0, lastY = 0;              // Last recorded mouse position

// Function to handle mouse button events
void MyMouseFunc(int button, int state, int x, int y)
{
    GLfloat mappedX = (float)x / windowWidth * 2 - 1;  // Map the x-coordinate to OpenGL coordinate system
    GLfloat mappedY = 1 - (float)y / windowHeight * 2; // Map the y-coordinate to OpenGL coordinate system

    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            printf("Left button clicked at (%f, %f)\n", mappedX, mappedY);
            isButtonDown = 1;
            lastX = mappedX;
            lastY = mappedY;
        }
        else if (state == GLUT_UP)
        {
            printf("Left button released at (%f, %f)\n", mappedX, mappedY);
            isButtonDown = 0;
        }
    }
}

// Function to handle mouse motion events
void MyMotionFunc(int x, int y)
{
    GLfloat mappedX = (float)x / windowWidth * 2 - 1;  // Map the x-coordinate to OpenGL coordinate system
    GLfloat mappedY = 1 - (float)y / windowHeight * 2; // Map the y-coordinate to OpenGL coordinate system

    if (isButtonDown)
    {
        printf("Mouse moved while button down at (%f, %f)\n", mappedX, mappedY);
        // Add the new line to the lines array
        lines = realloc(lines, sizeof(Line) * (linesCount + 1));
        lines[linesCount].x1 = lastX;
        lines[linesCount].y1 = lastY;
        lines[linesCount].x2 = mappedX;
        lines[linesCount].y2 = mappedY;
        linesCount++;
        // Update the last recorded mouse position
        lastX = mappedX;
        lastY = mappedY;
        // Redraw the screen
        glutPostRedisplay();
    }
}

// Function to render the lines on the screen
void renderFunction()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glClear(GL_COLOR_BUFFER_BIT);     // Clear the color buffer
    glColor3f(0.0, 0.0, 0.0);         // Set the drawing color to black

    for (int i = 0; i < linesCount; i++)
    {
        glBegin(GL_LINES);                    // Start drawing lines
        glVertex2f(lines[i].x1, lines[i].y1); // Set the starting point of the line
        glVertex2f(lines[i].x2, lines[i].y2); // Set the ending point of the line
        glEnd();                              // End drawing lines
    }

    glFlush(); // Flush the drawing commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE);              // Set the display mode to single buffer
    glutInitWindowSize(windowWidth, windowHeight); // Set the window size
    glutInitWindowPosition(100, 100);              // Set the window position
    glutCreateWindow("OpenGL - Mouse Path");       // Create a window with the specified title
    glutDisplayFunc(renderFunction);               // Set the display callback function
    glutMouseFunc(MyMouseFunc);                    // Set the mouse button callback function
    glutMotionFunc(MyMotionFunc);                  // Set the mouse motion callback function
    glutMainLoop();                                // Enter the main event loop

    free(lines); // Free the memory allocated for lines array
    return 0;
}
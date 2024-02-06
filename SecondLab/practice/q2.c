#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point
{
    GLfloat x, y;
};

struct Point p[10]; // Array to store points
int count = 0;      // Counter for number of points

void readInput()
{
    FILE *fptr = fopen("input2.txt", "r"); // Open input file in read mode
    if (fptr)
    {
        while (fscanf(fptr, "%f %f", &(p[count].x), &(p[count].y)) != EOF) // Read points from file
        {
            count++; // Increment point counter
        }
        fclose(fptr); // Close file
    }
}

void renderFunction()
{
    int i = 0;
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glClear(GL_COLOR_BUFFER_BIT);     // Clear color buffer
    glColor3f(0.0, 0.0, 1.0);         // Set drawing color to blue
    glPointSize(5);                   // Set point size to 5 pixels
    while (i < count - 1)
    {
        glBegin(GL_LINES);                  // Begin drawing lines
        glColor3f(0.5, 0.5, 1.0);           // Set line color to light blue
        glVertex2f(p[i].x, p[i].y);         // Set starting point of line
        glVertex2f(p[i + 1].x, p[i + 1].y); // Set ending point of line
        i++;
    }
    glEnd();   // End drawing lines
    glFlush(); // Flush drawing commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE);               // Set display mode to single buffer
    glutInitWindowSize(500, 500);                   // Set window size to 500x500 pixels
    glutInitWindowPosition(100, 100);               // Set window position
    readInput();                                    // Read input points from file
    glutCreateWindow("OpenGL - First window demo"); // Create window with title
    glutDisplayFunc(renderFunction);                // Set render function
    glutMainLoop();                                 // Enter main event loop
    return 0;
}
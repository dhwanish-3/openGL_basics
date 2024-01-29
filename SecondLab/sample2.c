#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point
{
    GLfloat x,y;
};

struct Point p[100000]; // Array to store points
int count = 0; // Counter to keep track of number of points

void readInput()
{
    FILE *fptr = fopen("sample2-input.txt", "r"); // Open input file in read mode
    if(fptr)
    {
        while(fscanf(fptr, "%f %f", &(p[count].x), &(p[count].y))!=EOF) // Read points from file until end of file is reached
        {
            count++; // Increment counter
        }
        fclose(fptr); // Close file
    }
}

void renderFunction()
{
    int i=0;
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer
    glColor3f(0.0, 0.0, 1.0); // Set drawing color to blue
    glPointSize(5); // Set point size to 5 pixels
    glBegin(GL_POINTS); // Begin drawing points
    while(i < count)
    {
        glVertex2f(p[i].x, p[i].y); // Draw each point
        i++;
    }
    glEnd(); // End drawing points
    glFlush(); // Flush drawing commands
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE); // Set display mode to single buffer
    glutInitWindowSize(500,500); // Set window size to 500x500 pixels
    glutInitWindowPosition(100,100); // Set window position
    readInput(); // Read input points from file
    glutCreateWindow("OpenGL - First window demo"); // Create window with title
    glutDisplayFunc(renderFunction); // Set render function
    glutMainLoop(); // Enter main event loop
    return 0;
}
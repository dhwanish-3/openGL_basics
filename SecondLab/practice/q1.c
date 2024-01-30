#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point
{
    GLfloat r,g,b,a; // RGBA color values for a point
};

struct Point p[10]; // Array of Point structures to store color values
int count = 0; // Counter to keep track of the number of points read from the file

void readInput()
{
    FILE *fptr = fopen("input1.txt", "r"); // Open the file "input1.txt" in read mode
    if(fptr)
    {
        while(fscanf(fptr, "%f %f %f %f", &(p[count].r), &(p[count].g), &(p[count].b), &(p[count].a))!=EOF)
        {
            count++; // Read RGBA color values from the file and increment the count
        }
        fclose(fptr); // Close the file
    }
}

void renderFunction()
{
    glClearColor(p[0].r, p[0].g, p[0].b, p[0].a); // Set the clear color for the window
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glColor3f(0.0, 0.0, 1.0); // Set the current color to blue
    glEnd(); // End any previous glBegin() calls
    glFlush(); // Flush the OpenGL pipeline to display the rendered image
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE); // Set the display mode to single buffer mode
    glutInitWindowSize(500,500); // Set the initial window size
    glutInitWindowPosition(100,100); // Set the initial window position
    readInput(); // Read RGBA color values from the file
    glutCreateWindow("OpenGL - First window demo"); // Create a window with the specified title
    glutDisplayFunc(renderFunction); // Set the display function
    glutMainLoop(); // Enter the main event loop
    return 0;
}
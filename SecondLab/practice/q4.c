#include <GL/glut.h>
#include <stdio.h>

struct Point {
    float x, y, z;
};

struct Point p[4]; // Array to store the points of the rectangle
int count = 0; // Counter to keep track of the number of points read

void readInput() {
    FILE *fptr = fopen("input4.txt", "r"); // Open the input file in read mode
    if (fptr) {
        while (fscanf(fptr, "%f %f %f", &(p[count].x), &(p[count].y), &(p[count].z)) != EOF && count < 4) {
            count++; // Read the points from the file and increment the counter
        }
        fclose(fptr); // Close the file
    }
}

void renderFunction() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set the clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0, 0.0, 0.0); // Set the drawing color to red

    // Drawing the rectangle strip
    glBegin(GL_QUADS); // Begin drawing quads
    for (int i = 0; i < count; i++) {
        glVertex3f(p[i].x, p[i].y, p[i].z); // Set the vertex coordinates
    }
    glEnd(); // End drawing quads

    glFlush(); // Flush the drawing commands
}

int main(int argc, char** argv) {
    readInput(); // Read the input points from the file

    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE); // Set the display mode to single buffer
    glutInitWindowSize(500, 500); // Set the window size
    glutInitWindowPosition(100, 100); // Set the window position
    glutCreateWindow("OpenGL - Rectangular Strip"); // Create a window with the specified title
    glutDisplayFunc(renderFunction); // Set the display function
    glutMainLoop(); // Enter the main loop

    return 0;
}
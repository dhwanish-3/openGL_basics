#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point{
    GLfloat x, y;
};

struct Point p[10];
int count = 0;

void readInput() {
    FILE *fptr = fopen("input3.txt", "r"); // Open the input file in read mode
    if (fptr) {
        while (fscanf(fptr, "%f %f", &(p[count].x), &(p[count].y)) != EOF) {
            count++; // Increment the count for each point read from the file
        }
        fclose(fptr); // Close the file
    }
}

void renderFunction() {
    int i = 0;
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(0.0, 0.0, 1.0); // Set the drawing color to blue

    // Drawing the polygon
    glBegin(GL_POLYGON); // Begin drawing a polygon
    glColor3f(0.5, 0.5, 1.0); // Set the color for the polygon
    while (i < count) {
        glVertex2f(p[i].x, p[i].y); // Add each point of the polygon
        i++;
    }
    glEnd(); // End drawing the polygon

    // Drawing diagonals to the polygon
    i = 0;
    glBegin(GL_LINES); // Begin drawing lines
    glColor3f(1.0, 0.0, 1.0); // Set the color for the lines
    glLineWidth(5); // Set the line width to 5
    while (i < count - 1) {
        int j = (i + 2) % (count);
        while (j != i) {
            // Skip the adjacent vertices and the vertices on the opposite side
            if (j == i + 1 || (j + 1) % (count - 1) == i || (j + 1) % (count - 1) == 1) {
                j = (j + 1) % (count);
                continue;
            }
            glVertex2f(p[i].x, p[i].y); // Add the starting point of the diagonal
            glVertex2f(p[j].x, p[j].y); // Add the ending point of the diagonal
            j = (j + 1) % (count);
        }
        i++;
    }
    glEnd(); // End drawing the lines
    glFlush(); // Flush the drawing commands
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE); // Set the display mode to single buffer
    glutInitWindowSize(800, 800); // Set the window size
    glutInitWindowPosition(400, 80); // Set the window position

    readInput(); // Read the input points from the file

    glutCreateWindow("Polygon with diagonals"); // Create a window with the given title
    glutDisplayFunc(renderFunction); // Set the display function
    glutMainLoop(); // Enter the main loop
    return 0;
}
#include <GL/glut.h>

// coordinates of tetrahedron
GLfloat tetrahedron[4][3] = {
    {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0, 0.5, 0.5}, {0, -0.05, -0.5}};

// gradient colors for the tetrahedron sides
GLfloat colors[4][3][3] = {
    {{1, 0, 0}, {1, 0.5, 0}, {1, 1, 0}},        // red to orange to yellow
    {{0, 0, 1}, {0, 0.5, 1}, {0, 1, 1}},        // blue to light blue to cyan
    {{0, 1, 0}, {0.5, 1, 0}, {1, 1, 0}},        // green to lime to yellow
    {{0, 0.5, 0.5}, {0, 0.75, 0.75}, {0, 1, 1}} // teal to light teal to cyan
};

// Function to draw a triangle face
void drawTriangleFace(GLfloat first[], GLfloat second[], GLfloat third[], GLfloat color[][3])
{
    glBegin(GL_TRIANGLES);
    glColor3fv(color[0]); // Set color for the first vertex
    glVertex3fv(first);   // Set position for the first vertex
    glColor3fv(color[1]); // Set color for the second vertex
    glVertex3fv(second);  // Set position for the second vertex
    glColor3fv(color[2]); // Set color for the third vertex
    glVertex3fv(third);   // Set position for the third vertex
    glEnd();
}

// Function to draw the tetrahedron
void drawTetrahedron(GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[])
{
    drawTriangleFace(V1, V2, V3, colors[0]); // Draw the first face
    drawTriangleFace(V1, V3, V4, colors[1]); // Draw the second face
    drawTriangleFace(V2, V3, V4, colors[2]); // Draw the third face
    drawTriangleFace(V1, V2, V4, colors[3]); // Draw the fourth face
}

// Function to render the scene
void renderFunction()
{
    glClearColor(0, 0, 0, 1);                           // Set the clear color to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers

    // Draw the tetrahedron
    drawTetrahedron(tetrahedron[0], tetrahedron[1], tetrahedron[2], tetrahedron[3]);

    glutSwapBuffers(); // Swap the front and back buffers
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                    // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Set the display mode
    glutInitWindowSize(500, 500);                             // Set the window size
    glutInitWindowPosition(200, 100);                         // Set the window position
    glutCreateWindow("Tetrahedron");                          // Create a window with the specified title
    glutDisplayFunc(renderFunction);                          // Set the display callback function
    glutMainLoop();                                           // Enter the event processing loop
    return 0;
}
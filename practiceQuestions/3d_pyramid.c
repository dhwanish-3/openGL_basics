#include <GL/glut.h>

// coordinates for the pyramid with 4 trianglur faces
GLfloat pyramid[4][3] = {
    {0, 0.6, 0}, // top
    {-0.75, -0.5, 0}, // bottom left
    {0.5, -0.5, 0.6}, // bottom right
    {0.5, -0.5, -0.6} // bottom back
};

// gradient colors for the pyramid sides
GLfloat colors[4][3][3] = {
    {{1, 0, 0}, {1, 0.5, 0}, {1, 1, 0}}, // red to orange to yellow
    {{0, 0, 1}, {0, 0.5, 1}, {0, 1, 1}}, // blue to light blue to cyan
    {{0, 1, 0}, {0.5, 1, 0}, {1, 1, 0}}, // green to lime to yellow
    {{0, 0.5, 0.5}, {0, 0.75, 0.75}, {0, 1, 1}} // teal to light teal to cyan
};

// angle of rotation
GLfloat angle = 10;

void drawTriangleFace(GLfloat first[], GLfloat second[], GLfloat third[], GLfloat color[][3])
{
    glBegin(GL_TRIANGLES);
    glColor3fv(color[0]);
    glVertex3fv(first);
    glColor3fv(color[1]);
    glVertex3fv(second);
    glColor3fv(color[2]);
    glVertex3fv(third);
    glEnd();
}

void renderFunction()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // drawing pyramid
    glLoadIdentity();
    glRotatef(angle, 0, 1, 0);
    glShadeModel(GL_SMOOTH); // enable smooth shading

    drawTriangleFace(pyramid[0], pyramid[1], pyramid[2], colors[0]);
    drawTriangleFace(pyramid[0], pyramid[2], pyramid[3], colors[1]);
    drawTriangleFace(pyramid[0], pyramid[3], pyramid[1], colors[2]);
    drawTriangleFace(pyramid[1], pyramid[2], pyramid[3], colors[3]);

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("3D Pyramid");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}
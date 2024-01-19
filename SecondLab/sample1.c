#include <GL/freeglut.h>
#include <GL/gl.h>

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // clears the color buffer for the window
    glClear(GL_COLOR_BUFFER_BIT); // sets bitplane area to previously selected by glColor
    glColor3f(1.0, 1.0, 1.0); // sets the current color of the pen
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush(); // forces execution of GL commands in finite time
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}
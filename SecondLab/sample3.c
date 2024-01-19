#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

GLfloat r=0.0,g = 0.0,b = 0.0,a =0.0;

void MyKeyboardFunc(unsigned char Key, int x, int y);

void renderFunction()
{
    int i=0;
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    // Registering a keyboard event callback.
    // MyKeyboardFunc will now get called on any key board button press.
    glutKeyboardFunc(MyKeyboardFunc);
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}

void MyKeyboardFunc(unsigned char Key, int x, int y)
{
    //Key contains the character we pressed
    //x and y contains the coordinates of the button cursor when the keyboard key
    // was pressed
    switch(Key)
    {
        case 'r':
            r = 1.0;g = 0.0;b = 0.0;a = 1.0;
            glClearColor(r, g, b, a);
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
            break;

        case 'g':
            r = 0.0;g = 1.0;b = 0.0;a = 1.0;
            glClearColor(r, g, b, a);
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
            break;

        case 'y':
            r = 1.0;g = 1.0;b = 0.0;a = 1.0;
            glClearColor(r, g, b, a);
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
            break;

        default: break;
    };
}
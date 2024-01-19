#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point
{
    GLfloat x,y;
};

struct Point p[100000];
int count = 0;

void readInput()
{
    FILE *fptr = fopen("sample2-input.txt", "r");
    if(fptr)
    {
        while(fscanf(fptr, "%f %f", &(p[count].x), &(p[count].y))!=EOF)
        {
            count++;
        }
        fclose(fptr);
    }
}

void renderFunction()
{
    int i=0;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    while(i < count)
    {
        glVertex2f(p[i].x, p[i].y);
        i++;
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    readInput();
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point
{
    GLfloat r,g,b,a;
};

struct Point p[10];
int count = 0;

void readInput()
{
    FILE *fptr = fopen("input1.txt", "r");
    if(fptr)
    {
        while(fscanf(fptr, "%f %f %f %f", &(p[count].r), &(p[count].g), &(p[count].b), &(p[count].a))!=EOF)
        {
            count++;
        }
        fclose(fptr);
    }
}

void renderFunction()
{
    int i=0;
    // printf("%f %f %f\n", p[0].x, p[0].y, p[0].z);
    glClearColor(p[0].r, p[0].g, p[0].b, p[0].a);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
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
#include<GL/freeglut.h>
#include<GL/gl.h>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL - First window demo");

	glBegin(GL_LINES);
	glColor3f(0.5,0.5,1.0);
	glVertex2f(-0.4,0.5);
	glVertex2f(-0.5,0.4);
	glBegin(GL_LINES);
	glColor3f(0.3,0.8,1.0);
	glVertex2f(-0.0,-0.5);
	glVertex2f(0.4,0.1);
	glBegin(GL_LINES);
	glColor3f(0.1,1.0,1.0);
	glVertex2f(0.0,0.8);
	glVertex2f(0.3,-0.4);
	glEnd();
	glFlush();
	glutMainLoop();
	return 0;
}

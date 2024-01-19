#include<GL/freeglut.h>
#include<GL/gl.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL - First window demo");
	glBegin(GL_POLYGON);
    glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0.0,-0.3);
	glVertex2f(0.3,-0.6);
	glVertex2f(0.4,0.0);
	glVertex2f(0.3,0.6);
	glVertex2f(0.0,0.3);
	glVertex2f(-0.3,0.6);
	glVertex2f(-0.4,0.0);
	glVertex2f(-0.3,-0.6);
	glEnd();
	glBegin(GL_POLYGON);
    glPolygonMode(GL_FRONT, GL_LINE);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,-0.3);
	glVertex2f(0.3,-0.6);
	glVertex2f(0.4,0.0);
	glVertex2f(0.3,0.6);
	glVertex2f(0.0,0.3);
	glVertex2f(-0.3,0.6);
	glVertex2f(-0.4,0.0);
	glVertex2f(-0.3,-0.6);
	glEnd();
	glFlush();
	glutMainLoop();
	return 0;
}

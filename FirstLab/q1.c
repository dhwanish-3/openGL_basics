#include<GL/freeglut.h>
#include<GL/gl.h>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL - First window demo");
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glColor3f(0.5,0.5,1.0);
	
	glVertex2f(-1.0,0.99);
	glVertex2f(-1.0,-0.99);
	glVertex2f(0.99,1.0);
	glVertex2f(0.99,-1.0);
	glVertex2f(0.4, 0.4);
	glVertex2f(-0.2, 0.6);
	glVertex2f(0.7, -0.6);
	glEnd();
	glFlush();
	glutMainLoop();
	return 0;
}

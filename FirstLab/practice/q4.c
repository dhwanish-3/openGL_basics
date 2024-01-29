#include<GL/freeglut.h>
#include<GL/gl.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL - First window demo");

	// Draw a filled polygon
	glBegin(GL_POLYGON);
    glPolygonMode(GL_BACK, GL_FILL); // Set the polygon mode to fill the back face
	glColor3f(0.0,1.0,0.0); // Set the color to green
	glVertex2f(0.0,-0.3);
	glVertex2f(0.3,-0.6);
	glVertex2f(0.4,0.0);
	glVertex2f(0.3,0.6);
	glVertex2f(0.0,0.3);
	glVertex2f(-0.3,0.6);
	glVertex2f(-0.4,0.0);
	glVertex2f(-0.3,-0.6);
	glEnd();

	// Draw a wireframe polygon
	glBegin(GL_POLYGON);
    glPolygonMode(GL_FRONT, GL_LINE); // Set the polygon mode to draw only the outline
    glColor3f(1.0,0.0,0.0); // Set the color to red
    glVertex2f(0.0,-0.3);
	glVertex2f(0.3,-0.6);
	glVertex2f(0.4,0.0);
	glVertex2f(0.3,0.6);
	glVertex2f(0.0,0.3);
	glVertex2f(-0.3,0.6);
	glVertex2f(-0.4,0.0);
	glVertex2f(-0.3,-0.6);
	glEnd();

	glFlush(); // Flush the OpenGL pipeline
	glutMainLoop(); // Enter the main event loop
	return 0;
}

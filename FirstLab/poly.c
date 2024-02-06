#include <GL/glut.h>

int main(int argc, char **argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);

	// Set the display mode to single buffer and RGBA color model
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	// Set the initial window size
	glutInitWindowSize(500, 500);

	// Set the initial window position
	glutInitWindowPosition(100, 100);

	// Create a window with the specified title
	glutCreateWindow("Simple Square");

	// Begin drawing a polygon
	glBegin(GL_POLYGON);

	// Set the color of the polygon to light blue
	glColor3f(0.5, 0.5, 1.0);

	// Specify the vertices of the polygon
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);

	// End drawing the polygon
	glEnd();

	// Flush any buffered OpenGL commands
	glFlush();

	// Enter the GLUT event processing loop
	glutMainLoop();

	return 0;
}

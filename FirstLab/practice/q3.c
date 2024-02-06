#include <GL/glut.h>

int main(int argc, char **argv)
{
	// Initialize GLUT library
	glutInit(&argc, argv);

	// Set the display mode to single buffer and RGBA color model
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	// Set the initial window size
	glutInitWindowSize(500, 500);

	// Set the initial window position
	glutInitWindowPosition(100, 100);

	// Create a window with the specified title
	glutCreateWindow("Polygon with two reflex angles");

	// Begin drawing a polygon
	glBegin(GL_POLYGON);

	// Set the color of the polygon to red
	glColor3f(1.0, 0.0, 0.0);

	// Specify the vertices of the polygon
	glVertex2f(0.0, -0.3);
	glVertex2f(0.3, -0.6);
	glVertex2f(0.3, 0.6);
	glVertex2f(0.0, 0.3);
	glVertex2f(-0.3, 0.6);
	glVertex2f(-0.3, -0.6);

	// End drawing the polygon
	glEnd();

	// Flush any pending OpenGL commands
	glFlush();

	// Enter the GLUT event processing loop
	glutMainLoop();

	return 0;
}

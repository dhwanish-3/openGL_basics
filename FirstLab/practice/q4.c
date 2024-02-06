#include <GL/glut.h>

GLfloat poly[8][2] = {
	{0.0, -0.3},
	{0.3, -0.6},
	{0.4, 0.0},
	{0.3, 0.6},
	{0.0, 0.3},
	{-0.3, 0.6},
	{-0.4, 0.0},
	{-0.3, -0.6},
};

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Reflex Polygon with Outline");

	// Draw a filled polygon
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0); // Set the color to green
	for (int i = 0; i < 8; i++)
	{
		glVertex2f(poly[i][0], poly[i][1]);
	}
	glEnd();

	// Draw a wireframe polygon
	glBegin(GL_LINE_LOOP);	  // Set the polygon mode to draw only the outline
	glColor3f(1.0, 0.0, 0.0); // Set the color to red
	for (int i = 0; i < 8; i++)
	{
		glVertex2f(poly[i][0], poly[i][1]);
	}
	glEnd();

	glFlush();		// Flush the OpenGL pipeline
	glutMainLoop(); // Enter the main event loop
	return 0;
}

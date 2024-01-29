#include<GL/freeglut.h>
#include<GL/gl.h>

int main(int argc, char** argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	
	// Set the display mode to single buffer and RGBA color model
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	
	// Set the initial window size
	glutInitWindowSize(500,500);
	
	// Set the initial window position
	glutInitWindowPosition(100,100);
	
	// Create a window with the specified title
	glutCreateWindow("OpenGL - First window demo");

	// Begin drawing lines
	glBegin(GL_LINES);
	
	// Set the color to light blue
	glColor3f(0.5,0.5,1.0);
	
	// Define the first line segment
	glVertex2f(-0.4,0.5);
	glVertex2f(-0.5,0.4);
	
	// Begin drawing lines
	glBegin(GL_LINES);
	
	// Set the color to light blue
	glColor3f(0.3,0.8,1.0);
	
	// Define the second line segment
	glVertex2f(-0.0,-0.5);
	glVertex2f(0.4,0.1);
	
	// Begin drawing lines
	glBegin(GL_LINES);
	
	// Set the color to light blue
	glColor3f(0.1,1.0,1.0);
	
	// Define the third line segment
	glVertex2f(0.0,0.8);
	glVertex2f(0.3,-0.4);
	
	// End drawing lines
	glEnd();
	
	// Flush the drawing commands
	glFlush();
	
	// Enter the GLUT event processing loop
	glutMainLoop();
	
	return 0;
}

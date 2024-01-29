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
	
	// Enable point size control in vertex program
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	
	// Set the point size to 10.0
	glPointSize(10.0);
	
	// Begin drawing points
	glBegin(GL_POINTS);
	
	// Set the color to light blue
	glColor3f(0.5,0.5,1.0);
	
	// Specify the coordinates of the points
	glVertex2f(-1.0,0.99);
	glVertex2f(-1.0,-0.99);
	glVertex2f(0.99,1.0);
	glVertex2f(0.99,-1.0);
	glVertex2f(0.4, 0.4);
	glVertex2f(-0.2, 0.6);
	glVertex2f(0.7, -0.6);
	
	// End drawing points
	glEnd();
	
	// Flush the drawing commands
	glFlush();
	
	// Enter the event processing loop
	glutMainLoop();
	
	return 0;
}

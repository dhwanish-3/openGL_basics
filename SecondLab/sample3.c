#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

GLfloat r = 0.0, g = 0.0, b = 0.0, a = 0.0;

void MyKeyboardFunc(unsigned char Key, int x, int y);

void renderFunction()
{
    int i = 0;
    glClearColor(r, g, b, a);     // Set the clear color for the window
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glColor3f(0.0, 0.0, 1.0);     // Set the current color to blue
    glPointSize(5);               // Set the point size to 5 pixels
    glFlush();                    // Flush the OpenGL pipeline
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    // Set the display mode
    glutInitWindowSize(500, 500);                   // Set the window size
    glutInitWindowPosition(100, 100);               // Set the window position
    glutCreateWindow("OpenGL - First window demo"); // Create a window with the specified title
    // Registering a keyboard event callback.
    // MyKeyboardFunc will now get called on any key board button press.
    glutKeyboardFunc(MyKeyboardFunc); // Register the keyboard event callback function
    glutDisplayFunc(renderFunction);  // Register the display function
    glutMainLoop();                   // Enter the main event loop
    return 0;
}

void MyKeyboardFunc(unsigned char Key, int x, int y)
{
    // Key contains the character we pressed
    // x and y contains the coordinates of the button cursor when the keyboard key
    //  was pressed
    switch (Key)
    {
    case 'r':
        r = 1.0;
        g = 0.0;
        b = 0.0;
        a = 1.0;                      // Set the clear color to red
        glClearColor(r, g, b, a);     // Set the clear color for the window
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
        glFlush();                    // Flush the OpenGL pipeline
        break;

    case 'g':
        r = 0.0;
        g = 1.0;
        b = 0.0;
        a = 1.0;                      // Set the clear color to green
        glClearColor(r, g, b, a);     // Set the clear color for the window
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
        glFlush();                    // Flush the OpenGL pipeline
        break;

    case 'y':
        r = 1.0;
        g = 1.0;
        b = 0.0;
        a = 1.0;                      // Set the clear color to yellow
        glClearColor(r, g, b, a);     // Set the clear color for the window
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
        glFlush();                    // Flush the OpenGL pipeline
        break;

    default:
        break;
    };
}
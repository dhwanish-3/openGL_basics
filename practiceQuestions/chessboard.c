#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int windowWidth = 500, windowHeight = 500;

struct Point
{
    GLfloat x, y;
};

struct Square
{
    struct Point topLeft, topRight, bottomLeft, bottomRight;
};

// calculate the points of the chessboard
struct Square chessBoard[8][4];

// background color of the chessboard is white
// chessBoard array stores the points of the black squares
// the white squares are the ones that are not stored in the array
// We start from the top left corner and draw the black squares

void calculateChessBoard()
{
    GLfloat x = -1.0, y = 1.0; // top left corner of the chessboard
    for (int i = 0; i < 8; i++)
    {
        x = i % 2 == 0 ? -1.0 : -0.75; // alternate between -1.0 and -0.75
        for (int j = 0; j < 4; j++)
        {
            chessBoard[i][j].topLeft.x = x;
            chessBoard[i][j].topLeft.y = y;

            // each square is 0.25 units wide
            chessBoard[i][j].topRight.x = x + 0.25;
            chessBoard[i][j].topRight.y = y;

            chessBoard[i][j].bottomLeft.x = x;
            chessBoard[i][j].bottomLeft.y = y - 0.25;

            chessBoard[i][j].bottomRight.x = x + 0.25;
            chessBoard[i][j].bottomRight.y = y - 0.25;

            x += 0.5; // move to the next square
        }
        y -= 0.25; // move to the next row
    }
}

void drawChessBoard()
{
    // creating the chessboard
    calculateChessBoard();

    glColor3f(0.0, 0.0, 0.0); // Set drawing color to black

    // drawing the chessboard
    glBegin(GL_QUADS);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            glVertex2f(chessBoard[i][j].topLeft.x, chessBoard[i][j].topLeft.y);
            glVertex2f(chessBoard[i][j].topRight.x, chessBoard[i][j].topRight.y);
            glVertex2f(chessBoard[i][j].bottomRight.x, chessBoard[i][j].bottomRight.y);
            glVertex2f(chessBoard[i][j].bottomLeft.x, chessBoard[i][j].bottomLeft.y);
        }
    }
    glEnd();
}

void renderFunction()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Setting background color to white
    glClear(GL_COLOR_BUFFER_BIT);     // Clear color buffer

    // Draw the chessboard
    drawChessBoard();
    glFlush(); // Flush drawing commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE);              // Set display mode to single buffer
    glutInitWindowSize(windowWidth, windowHeight); // Set window size to 500x500 pixels
    glutInitWindowPosition(100, 100);              // Set window position
    glutCreateWindow("OpenGL - Chessboard");       // Create window with title
    glutDisplayFunc(renderFunction);               // Set render function
    glutMainLoop();                                // Enter main event loop
    return 0;
}
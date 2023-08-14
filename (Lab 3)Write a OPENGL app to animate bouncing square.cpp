#include <GL/glut.h>

int transY = 0;
int transX = 0;
bool increasingY = true;
bool increasingX = true;
int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

void displaySquare()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing a Purple Square
    glColor3d(1, 0, 1);
    glBegin(GL_QUADS);
    glVertex2d(0 + transX, 0 + transY);
    glVertex2d(200 + transX, 0 + transY);
    glVertex2d(200 + transX, 200 + transY);
    glVertex2d(0 + transX, 200 + transY);
    glEnd();
    glFlush();
}

void update(int value)
{
    if (increasingX) transX++; else transX--;

    if (increasingY) transY++; else transY--;

    if (transY >= WINDOW_HEIGHT - 200) increasingY = false; // Y UPPER LIMIT
    else if (transY <= -WINDOW_HEIGHT) increasingY = true; // Y LOWER LIMIT

    if (transX >= WINDOW_WIDTH - 200) increasingX = false; // X UPPER LIMIT
    else if (transX <= -WINDOW_WIDTH) increasingX = true; // X LOWER LIMIT

    glutPostRedisplay();
    glutTimerFunc(4, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Lab 3 - Swapnil Lamsal");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WINDOW_WIDTH, WINDOW_WIDTH, -WINDOW_HEIGHT, WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(displaySquare);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}

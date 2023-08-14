#include <GL/glut.h>
#include <iostream>
using namespace std;

int TRANSLATE = 20;
int WIN_WIDTH = 1024;
int WIN_HEIGHT = 768;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);

    int x, y, width, height;
    cout << "Enter the values for a square:" << endl;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "width = "; cin >> width;
    cout << "height = "; cin >> height;

    // Original square
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + width, y);
    glVertex2d(x + width, y + height);
    glVertex2d(x, y + height);
    glEnd();

    // Translated square
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(x + TRANSLATE, y + TRANSLATE);
    glVertex2d(x + width + TRANSLATE, y + TRANSLATE);
    glVertex2d(x + width + TRANSLATE, y + height + TRANSLATE);
    glVertex2d(x + TRANSLATE, y + height + TRANSLATE);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("Lab 11 - Swapnil Lamsal");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIN_WIDTH, WIN_WIDTH, -WIN_HEIGHT, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

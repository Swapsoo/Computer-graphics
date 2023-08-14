#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int WIN_WIDTH = 800;
int WIN_HEIGHT = 600;

void drawPoints(int x, int y, int x1, int y1) {
    glVertex2i(x1 + x, y1 + y);
    glVertex2i(x1 - x, y1 + y);
    glVertex2i(x1 + x, y1 - y);
    glVertex2i(x1 - x, y1 - y);
    glVertex2i(x1 + y, y1 + x);
    glVertex2i(x1 - y, y1 + x);
    glVertex2i(x1 + y, y1 - x);
    glVertex2i(x1 - y, y1 - x);
}


void drawCircle() {
    int x1, y1, r;
    cout << "Enter the coordinates:" << endl;
    cout << "x1 = "; cin >> x1;
    cout << "y1 = "; cin >> y1;
    cout << "Radius = "; cin >> r;

    int x = 0;
    int y = r;
    int d = 1 - r;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3d(0, 0, 0);

    while (x <= y) {
        glPointSize(20.0f);
        drawPoints(x, y, x1, y1);
        if (d < 0) {
            d += 2 * x + 1;
        } else {
            d += 2 * (x - y) + 1;
            y--;
        }
        x++;
    }

    glEnd();
    glFlush();
}

void myInit() {
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Lab 10 - Swapnil Lamsal");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIN_WIDTH, WIN_WIDTH, -WIN_HEIGHT, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    myInit();
    glutDisplayFunc(drawCircle);
    glutMainLoop();
    return 0;
}

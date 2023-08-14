#include <GL/glut.h>
#include <iostream>
using namespace std;

int WIN_WIDTH = 800;
int WIN_HEIGHT = 600;


void drawLine() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);

    int x1, y1, x2, y2;
    cout << "Enter the coordinates:" << endl;
    cout << "x1 = "; cin >> x1;
    cout << "y1 = "; cin >> y1;
    cout << "x2 = "; cin >> x2;
    cout << "y2 = "; cin >> y2;

    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;
    float b = y1 - m * x1;

    glBegin(GL_POINTS);
    if (dx != 0) {
        for (int x = x1; x <= x2; x++) {
            int y = m * x + b;
            glVertex2i(x, y);
        }
    } else {
        for (int y = y1; y <= y2; y++) {
            glVertex2i(x1, y);
        }
    }
    glEnd();
    glFlush();
}

void myInit() {
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Lab 7 - Swapnil Lamsal");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIN_WIDTH, WIN_WIDTH, -WIN_HEIGHT, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    myInit();
    glutDisplayFunc(drawLine);
    glutMainLoop();
    return 0;
}

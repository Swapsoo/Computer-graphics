#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int WIN_WIDTH = 800;
int WIN_HEIGHT = 600;


void drawLineDDA() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);
    glPointSize(2);

    int x1, y1, x2, y2;
    cout << "Enter the coordinates:" << endl;
    cout << "x1 = "; cin >> x1;
    cout << "y1 = "; cin >> y1;
    cout << "x2 = "; cin >> x2;
    cout << "y2 = "; cin >> y2;

    float dx = x2 - x1;
    float dy = y2 - y1;

    float step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float x_inc = step/dx, y_inc = step/dy;

    for (int i = 0; i <= step; i++){
        glBegin(GL_POINTS);
            glVertex2f(round(x1), round(y1));
            x1 += x_inc; y1 += y_inc;
        glEnd();
    }
    glFlush();
}

void myInit() {
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Lab 8 - Swapnil Lamsal");
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
    glutDisplayFunc(drawLineDDA);
    glutMainLoop();
    return 0;
}

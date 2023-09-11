#include <GL/glut.h>

void drawLine(float x1, float y1, float x2, float y2) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Specify the endpoints of the line
    float x1 = 0.1;
    float y1 = 0.1;
    float x2 = 0.9;
    float y2 = 0.9;

    drawLine(x1, y1, x2, y2);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Lab 7 Swapnil Lamsal");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


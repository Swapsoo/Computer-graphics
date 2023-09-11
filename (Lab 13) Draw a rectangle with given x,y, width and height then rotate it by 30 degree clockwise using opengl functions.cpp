#include <GL/glut.h>
#include <cmath>

float rectangleVertices[4][2] = {{100.0, 100.0}, {300.0, 100.0}, {300.0, 150.0}, {100.0, 150.0}};
float angle = 30.0; // Rotation angle in degrees

void drawRectangle() {
    glColor3f(0.0, 1.0, 0.0); // Green color for the rectangle
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++) {
        glVertex2fv(rectangleVertices[i]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawRectangle();

    // Translate the rectangle to its origin (100, 100)
    glTranslatef(-100.0, -100.0, 0.0);

    // Rotate the rectangle by the specified angle
    glRotatef(angle, 0.0, 0.0, 1.0);

    // Translate the rectangle back to its original position
    glTranslatef(100.0, 100.0, 0.0);

    drawRectangle();
    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("LAB 15 - Swapnil Lamsal");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


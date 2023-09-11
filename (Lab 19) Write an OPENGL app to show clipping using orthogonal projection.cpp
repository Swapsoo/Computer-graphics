#include <GL/glut.h>
GLfloat vertices[][2] = {
    {50.0, 50.0},
    {200.0, 50.0},
    {200.0, 200.0},
    {50.0, 200.0}
};

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 300, 0, 300, -1, 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++) {glVertex2fv(vertices[i]);}
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Lab 19 - Swapnil Lamsal");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

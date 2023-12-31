#include <GL/glut.h>
#include <cmath>

float x, y;
float width, height;
int win_width = 600;
int win_height = 400;

void drawRectangle(float x, float y, float width, float height) {
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawRectangle(x, y, width, height);


    float centerX = x + width / 2;
    float centerY = y + height / 2;


    glPushMatrix();

    glRotatef(30.0, 0.0, 0.0, 1.0);

    drawRectangle(x, y, width, height);
    glPopMatrix();
    glFlush();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, win_width, -100, win_height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char *argv[]) {
    x = 100;
    y = 100;
    width = 200;
    height = 50;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Lab 11 Swapnil Lamsal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}

#include <GL/glut.h>
int SHIFT_WINDOW_X = 350;
int WIN_WIDTH = 512;
int WIN_HEIGHT = 512;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Main Base
    glColor3f(0.1, 0.75, 0.3);
    glBegin(GL_POLYGON);
        glVertex2d(-400, -300);
        glVertex2d(400, -300);
        glVertex2d(400, 300);
        glVertex2d(-400, 300);
    glEnd();

    // Roof
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2d(-400, 300);
        glVertex2d(0, 500);
        glVertex2d(400, 300);
    glEnd();

    // Windows
    for (int i = 0; i < 2; i++){
        glColor3f(0, 0.5, 1);
        glBegin(GL_POLYGON);
            glVertex2d(-300 + SHIFT_WINDOW_X*i, 0);
            glVertex2d(-50 + SHIFT_WINDOW_X*i, 0);
            glVertex2d(-50 + SHIFT_WINDOW_X*i, 200);
            glVertex2d(-300 + SHIFT_WINDOW_X*i, 200);
        glEnd();
    }

    // Door
    glColor3f(0.25, 0.20, 0);
    glBegin(GL_POLYGON);
        glVertex2d(-100, -300);
        glVertex2d(-100, -50);
        glVertex2d(100, -50);
        glVertex2d(100, -300);
    glEnd();

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("LAB 5 - A HUT IN OPENGL");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluOrtho2D(-WIN_WIDTH, WIN_WIDTH, -WIN_HEIGHT, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

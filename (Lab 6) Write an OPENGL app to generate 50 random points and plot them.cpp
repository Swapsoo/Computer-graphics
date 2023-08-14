#include <GL/glut.h>
#include <GL/gl.h>
#include <cstdlib>
#include <ctime>

int pointFreq = 50;
int WIN_WIDTH = 1024;
int WIN_HEIGHT = 768;

void display(){
    srand(time(0));
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(5.0f);
    glBegin(GL_POINTS);


    for (int i = 0; i < pointFreq; i++) {
        int pointX = rand() % WIN_WIDTH;
        int pointY = rand() % WIN_HEIGHT;
        glVertex2f(pointX, pointY);
    }

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("Lab 6 - Swapnil Lamsal");
    glLoadIdentity();
    gluOrtho2D(0, WIN_WIDTH, 0, WIN_HEIGHT);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

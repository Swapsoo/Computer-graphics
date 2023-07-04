#include<GL/glut.h>

void myInit()
{

    glutInitWindowSize(500,500);
    glutInitWindowPosition(350,50);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("Lab 2 (Swapnil)");
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

}

void draw()
{
    glBegin(GL_QUADS);
    glColor3d(1,0,0);
    glVertex2f(0.3,0.6);
    glVertex2f(0.0,0.6);
    glVertex2f(0.0,0.3);
    glVertex2f(0.3,0.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(0,0,1);
    glVertex2f(0.3,0.5);
    glVertex2f(0.1,0.2);
    glVertex2f(0.5,0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(0,1,0);
    glVertex2f(0.6,0.4);
    glVertex2f(0.4,0.4);
    glVertex2f(0.3,0.2);
    glVertex2f(0.4,0.0);
    glVertex2f(0.6,0.0);
    glVertex2f(0.7,0.2);

    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

// Write a OPENGL app to display following vehicle.
#include<gl/glut.h>

void myInit()
{
    glutInitWindowSize(500,500);
    glutInitWindowPosition(350,50);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("LABWORK 2 (Swapnil)");
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

}

void Draw()
{
    glLineWidth(7);

    glBegin(GL_TRIANGLES);
    glColor3d(0,0,1);
    glVertex2f(0.0,0.8);
    glVertex2f(-0.5,0.3);
    glVertex2f(0.5,0.3);
    glEnd();


    glBegin(GL_QUADS);
    glColor3d(0,1,1);
    glVertex2f(0.5,0.3);
    glVertex2f(-0.5,0.3);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3d(1,0,0);
    glVertex2f(-0.1,0.1);
    glVertex2f(-0.3,0.1);
    glVertex2f(-0.3,-0.1);
    glVertex2f(-0.1,-0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3d(1,0,0);
    glVertex2f(0.3,0.1);
    glVertex2f(0.1,0.1);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.3,-0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3d(1,0,0);
    glVertex2f(0.1,-0.2);
    glVertex2f(-0.1,-0.2);
    glVertex2f(-0.1,-0.5);
    glVertex2f(0.1,-0.5);
    glEnd();



    glFlush();

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    myInit();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

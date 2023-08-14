#include <GL/glut.h>

void displayPrimitives(void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing a Red Square
    glColor3d(1, 0, 0);
    glBegin(GL_QUADS);
        glVertex2d(0, 0);
        glVertex2d(200, 0);
        glVertex2d(200, 200);
        glVertex2d(0, 200);
    glEnd();
    glFlush();

    // Drawing a Green Triangle
    glColor3d(0, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex2d(200, 100);
        glVertex2d(100, -100);
        glVertex2d(300, -100);
    glEnd();
    glFlush();

    // Drawing a Blue Hexagon
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex2d(200, -100);
        glVertex2d(250, -200);
        glVertex2d(350, -200);
        glVertex2d(400, -100);
        glVertex2d(350, 0);
        glVertex2d(250, 0);
        /*        glVertex2d(200, -100);
        glVertex2d(300, -200);
        glVertex2d(400, -200);
        glVertex2d(500, -100);
        glVertex2d(400, 0);
        glVertex2d(300, 0);*/

    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lab 2 - Swapnil Lamsal");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(displayPrimitives);
    glutMainLoop();
    return 0;
}

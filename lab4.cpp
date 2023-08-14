#include <GL/glut.h>

// LAB 4 - MOUSECLICK

int WIN_WIDTH = 640;
int WIN_HEIGHT = 480;
int SQUARE_WIDTH = 50;
int mouseX = 0;
int mouseY = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2d(mouseX, WIN_HEIGHT - mouseY);
        glVertex2d(mouseX + SQUARE_WIDTH, WIN_HEIGHT - mouseY);
        glVertex2d(mouseX + SQUARE_WIDTH, WIN_HEIGHT - mouseY + SQUARE_WIDTH);
        glVertex2d(mouseX, WIN_HEIGHT - mouseY + SQUARE_WIDTH);
    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
        mouseX = x;
        mouseY = y;
        glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("LAB 4 - CREATE SQUARE ON CLICK");
    glClearColor(0, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluOrtho2D(0, WIN_WIDTH, 0, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);

    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}



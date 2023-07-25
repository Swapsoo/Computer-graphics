*
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



/*
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;
float xi, yi, xf, yf;
void plotPixel()
{
	float x, y, dx, dy, m, c, xend;
	dx = xf - xi;
	dy = yf - yi;
	m = dy / dx;
	c = yi - m * xi;

	if(xi > xf)
        {
		x = xf;
		y = yf;
		xend = xi;
	    }

    else
        {
		x = xi;
		y = yi;
		xend = xf;
	    }

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);

	while(x <= xend)
        {
		glVertex2f(round(x), round(y));
		x += 1;
		y = m * x + c;
        }

	glEnd();
	glFlush();
}
int main(int argc, char * argv[])
{
	cout << "Enter the initial points: ";
	cin >> xi >> yi;
	cout << "Enter the final points: ";
	cin >> xf >> yf;

	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Drawing Shapes");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glutDisplayFunc(plotPixel);
	glutMainLoop();
	return 0;
}
*/

/*

#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;
float xf, yf, xi, yi;
void drawLine()
{
    float steps, dx = xf - xi, dy = yf - yi;
    if (abs(dx) < abs(dy))
    {
        steps = abs(dy);
    }
    else
    {
        steps = abs(dx);
    }
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = xi;
    float y = yi;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(round(x), round(y));

    for (int i = 0; i <= steps; i++)
    {
        x += xIncrement;
        y += yIncrement;
        glVertex2f(round(x), round(y));
    }

    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    cout << "Enter the initial point (x1, y1): ";
    cin >> xi >> yi;
    cout << "Enter the final point (x2, y2): ";
    cin >> xf >> yf;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("DDA Algorithm - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(drawLine);
    glutMainLoop();
    return 0;
}
*/


/*
#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

float xi, yi, xf, yf;

void bresenham()
{
    float x, y, dx, dy, p, xend;
    dx = xf - xi;
    dy = yf - yi;
    if (dx < 0)
    {
        dx = -dx;
    }
    if (dy < 0)
    {
        dy = -dy;
    }
    if (xi > xf)
    {
        x = xf;
        y = yf;
        xend = xi;
    }
    else
    {
        x = xi;
        y = yi;
        xend = xf;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    if (dx < dy)
    {
        p = 2 * dx - dy;
        while (x <= xend)
        {

            if (p < 0)
            {
                p += 2 * dx;
            }
            else
            {
                p += 2 * (dx - dy);
                y += (yf > yi) ? 1 : -1;
            }
            x += 1;
            glVertex2f(x, y);
        }
    }
    else
    {
        p = 2 * dy - dx;
        while (x <= xend)
        {

            if (p < 0)
            {
                p += 2 * dy;
            }
            else
            {
                p += 2 * (dy - dx);
                x += (xf > xi) ? 1 : -1;
            }
            y += 1;
            glVertex2f(x, y);
        }
    }
    glEnd();
    glFlush();
}

void dda()
{
    int steps;
    int dx = xf - xi;
    int dy = yf - yi;
    if (abs(dx) >= abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;
    float x = xi;
    float y = yi;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(round(x), round(y));
    for (int i = 0; i <= steps; i++)
    {
        x += xIncrement;
        y += yIncrement;
        glVertex2f(round(x), round(y));
    }
    glEnd();
    glFlush();
}

void direct()
{
    float x, y, dx, dy, m, c, xend;
    dx = xf - xi;
    dy = yf - yi;
    m = dy / dx;
    c = yi - m * xi;
    if (xi > xf)
    {
        x = xf;
        y = yf;
        xend = xi;
    }
    else
    {
        x = xi;
        y = yi;
        xend = xf;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(round(x), round(y));
    while (x <= xend)
    {

        x += 1;
        y = m * x + c;
        glVertex2f(round(x), round(y));
    }
    glEnd();
    glFlush();
}

void plotPixel()
{
    clock_t dda_start, dda_end, bresenham_start, bresenham_end, direct_start, direct_end;

    dda_start = clock();
    dda();
    dda_end = clock();
    bresenham_start = clock();
    bresenham();
    bresenham_end = clock();
    direct_start = clock();
    direct();
    direct_end = clock();

    cout << endl;
    cout << "The time taken by DDA is " << (float)(dda_end - dda_start) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "The time taken by Bresenham is " << (float)(bresenham_end - bresenham_start) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "The time taken by Direct is " << (float)(direct_end - direct_start) / CLOCKS_PER_SEC << " seconds" << endl;
}

int main(int argc, char *argv[])
{
    cout << "Enter the initial points: ";
    cin >> xi >> yi;
    cout << "Enter the final points: ";
    cin >> xf >> yf;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Algorithm - Aakash Dhakal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(plotPixel);
    glutMainLoop();

    return 0;
}
*/


/*

#include <iostream>
#include <GL/glut.h>
using namespace std;

int xi, yi, radius;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + xi, y + yi);
    glEnd();
}

void drawCircle()
{
    int x = 0;
    int y = radius;
    float decision = 1 - radius;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    plot(x, y);

    while (x <= y)
    {
        x++;
        if (decision < 0)
        {
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            decision += 2 * (x - y) + 1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Enter the coordinates of the center (x,y): ";
    cin >> xi >> yi;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Line Drawing Alogrithms");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(drawCircle);
    glutMainLoop();
}

*/

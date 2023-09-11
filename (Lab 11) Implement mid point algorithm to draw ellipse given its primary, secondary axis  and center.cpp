#include <GL/glut.h> 
#include <iostream>
using namespace std;
int WIN_WIDTH = 800;
int WIN_HEIGHT = 600; 
void drawPoints(int x, int y, int x1, int y1) 
{ 
glBegin(GL_POINTS);
glColor3d(0, 0, 0);
glVertex2i(x1 + x, y1 + y);
glVertex2i(x1 - x, y1 + y);
glVertex2i(x1 + x, y1 - y);
glVertex2i(x1 - x, y1 - y);
glEnd(); 
} 
// Midpoint Circle Algorithm 
void drawCircle() 
{
int x1, y1, a, b;
cout << "Enter the coordinates for ellipse:" << endl;
cout << "x1 = "; 
cin >> x1;
cout << "y1 = ";
cin >> y1; 
cout << "a = "; 
cin >> a; 
cout << "b = "; 
cin >> b;
float p, x = 0, y = b;
p = b * b - a * a * b + 0.25 * a * a;
while (2 * b * b * x < 2 * a * a * y) 
{ 
drawPoints(x, y, x1, y1);
x++; 
if (p < 0) { p += b * b * (2 * x + 1);
} 
else 
{ 
y--; 
p += b * b * (2 * x + 1) - a * a * (2 * y);
}
}
p = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b; 
while (y >= 0) 
{ 
drawPoints(x, y, x1, y1);
y--;
if (p > 0) { p += a * a * (1 - 2 * y); 
}
else { x++; p += b * b * (2 * x + 1) + a * a * (1 - 2 * y); 
} } 
glFlush(); 
} 
Void myInit() 
{ 
glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("SWAPNIL LAMSAL !"); 
glClearColor(1, 1, 1, 1); 
glClear(GL_COLOR_BUFFER_BIT);
glColor3d(0, 0, 0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-WIN_WIDTH, WIN_WIDTH, -WIN_HEIGHT, WIN_HEIGHT); 
glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) 
{ 
glutInit(&argc, argv);
myInit(); 
glutDisplayFunc(drawCircle);
glutMainLoop(); 
return 0;
}

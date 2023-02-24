#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

GLdouble x1, Y1, x2, y2;
void display() {
	GLdouble dx, dy, steps;
	float xinc, yinc, x, y;
	x = x1;
	y = Y1;
	dx = x2 - x1;
	dy = y2 - Y1;
	steps = (abs(dx) > abs(dy) ? dx : dy);
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2d(x, y);

	for (int i = 0; i < steps; i++) {
		x = x + xinc;
		y = y + yinc;
		glVertex2d(x, y);
	}
	glEnd();
	glFlush();
	
}

void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,50.0,0.0,100.0);
}


int main(int argc, char **argv)
{
	cout << "Enter the two points of the line";
	cout << "\nEnter the first point";
	cin >> x1 >> Y1;
	cout << "\nEnter the second point";
	cin >> x2 >> y2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 300);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("DDA Line");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
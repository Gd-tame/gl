#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include<GLUT/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

void circle() {
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	float r = 100;
	float x = 0, y = r;
	float d = 3 - 2*r;
	glBegin(GL_POINTS);
	while (x != y) {
		x++;
		if (d < 0) {
			d += 4*x + 6;
		}
		else {
			y--;
			d += 4 * (x - y) + 10;
		}
		glVertex2i(x, y);
		glVertex2i(-x, y);
		glVertex2i(x, -y);
		glVertex2i(-x, -y);
		
		glVertex2i(y, x);
		glVertex2i(-y, x);
		glVertex2i(-y, -x);
		glVertex2i(y, -x);
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham's Circle Algorithm");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-250, 250, -250, 250);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 500, 500);

	glutDisplayFunc(circle);
	glutMainLoop();
	return 0;
}
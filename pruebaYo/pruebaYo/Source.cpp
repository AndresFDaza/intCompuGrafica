#include "glut.h"

void pixel() {
	glClearColor(1, 0, 1,1);
	glPointSize(50);

	glBegin(GL_POINTS);
	glColor3f(0,1,0);
	glVertex2f(250, 250);
	glEnd();

	glutSwapBuffers();
}

void dibujaPixel() {

	//glClear(GL_COLOR_BUFFER_BIT);

	pixel();

	glFlush();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("Hola hola hola");

	gluOrtho2D(0,500,500,0);
	//glOrtho(0, 500, 500, 0, 0, 1);

	glutDisplayFunc(dibujaPixel);


	glutMainLoop();
	return 0;

}
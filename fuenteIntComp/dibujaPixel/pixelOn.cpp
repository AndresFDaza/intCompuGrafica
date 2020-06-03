#include "glut.h"


void pixel(float xPos, float yPos, float RedColor, float GreenColor, float BlueColor) { //pinta un pixel en posicion y color por parametro
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(RedColor, GreenColor, BlueColor);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

void map() {

	pixel(200, 200, 1, 0, 0);
	glFlush();
}

int main(int argc, char * argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowSize(400, 400);
	glutInitWindowPosition(300, 200);

	glutCreateWindow("aprendiendo codear un bitmap");

	glOrtho(0, 400, 400, 0, 0, 1);
	glutDisplayFunc(map);


	glutMainLoop();
	return 0;

}
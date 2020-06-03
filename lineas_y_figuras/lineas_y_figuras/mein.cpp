#include "glut.h"

int tam[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}

};

void pixel(float xPos, float yPos, float RedColor, float GreenColor, float BlueColor) { //pinta un pixel en posicion y color por parametro
	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(RedColor, GreenColor, BlueColor);
	glVertex2f(xPos, yPos);
	glEnd();

	glutSwapBuffers();
}

void map() {

	//pixel(200, 200, 0, 1, 0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tam[i][j] == 0) {
				pixel(j*50-10, i*50-10, 0, 0, 0);
			}
			else {
				pixel(j*50-10, i*50-10, 1, 0, 0);

			}
		}
	}

	glFlush();

}

int main(int argc, char * argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 200);

	glutCreateWindow("aprendiendo codear un bitmap");

	glOrtho(0, 400, 400, 0, 0, 1);
	glutDisplayFunc(map);


	glutMainLoop();
	return 0;

}
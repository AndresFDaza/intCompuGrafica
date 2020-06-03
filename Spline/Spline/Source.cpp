// ANDRÉS FELIPE DAZA MORENO - 1201956
// SANTIAGO RAMIREZ - 1202229

using namespace std;

#include <iostream>
#include "glut.h"


int xPantalla = 800, yPantalla = 800;

int cuentaClicks = 0, xClick, yClick;
int vectorCoordenadas[5][2], tamVector = 0;

bool mensajeConsola = false;


void pintaPixel(float xPos, float yPos, int tamPoint, float RedColor, float GreenColor, float BlueColor) {
	glPointSize(tamPoint);
	glBegin(GL_POINTS);
	glColor3f(RedColor, GreenColor, BlueColor);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

void calcularTamanoVector() {
	int tamano = 0;
	for (int i = 0; i <= 4; i++) {
		if (vectorCoordenadas[i][0] != 0 ) {
			tamano = tamano + 1;
		}
	}
	tamVector = tamano;
}
void reiniciaVector() {
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 1; j++) {
			vectorCoordenadas[i][j] = 0;
		}
	}
}

void pintaSpline(int vector[5][2], int tamanoDelVector) {

	float a = 0, b = 0, t = 0;


	switch (tamanoDelVector)
	{
	case 3:
		do {

			a = ((((1 - t) * (1 - t)) * vector[1 - 1][0]) + 
				((2 * t) * (1 - t) * vector[2 - 1][0]) + 
				((t * t) * vector[3 - 1][0]));


			b = ((((1 - t) * (1 - t)) * vector[1 - 1][1]) + ((2 * t) * (1 - t) * vector[2 - 1][1]) + ((t * t) * vector[3 - 1][1]));

			t = t + 0.001;
			pintaPixel(a, b, 2, 1, 0, 1);

		} while (t <= 1);
		break;


	default:
		break;
	}


	
	
}



void ingresaMouse(int btn, int state, int x, int y) {

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//calcularTamanoVector();
		pintaPixel(x, y, 5, 1, 0.5, 0);
		//vectorCoordenadas[tamVector][0] = x;
		//vectorCoordenadas[tamVector][1] = y;
		cout << "ingreso x: " + x << endl;
		cout << "ingreso y: " + y << endl;
	}

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		calcularTamanoVector();
		pintaPixel(x, y, 5, 1, 0.5, 0);
		vectorCoordenadas[tamVector - 1][0] = x;
		vectorCoordenadas[tamVector - 1][1] = y;

		//pintaSpline(vectorCoordenadas, tamVector);
		reiniciaVector();
	}

}

void displayInit() {
	//mostrarInstrucciones();
	glFlush();
}



int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(700, 200);
	glutCreateWindow("CURVAS SPLINE");
	gluOrtho2D(0, xPantalla, yPantalla, 0);
	glutDisplayFunc(displayInit);
	glutMouseFunc(ingresaMouse);
	glutMainLoop();
	return 0;
}
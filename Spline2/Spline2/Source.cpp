// ANDRÉS FELIPE DAZA MORENO - 1201956
// SANTIAGO RAMIREZ - 1202229

using namespace std;

#include <iostream>
#include "glut.h"


int xPantalla = 800, yPantalla = 800;


float vectorCoorX[5] = { 0,0,0,0,0 }, vectorCoorY[5] = { 0,0,0,0,0 };
int opcion, tamVector, cuentaClicks = 1;



void pintaPixel(float xPos, float yPos, int tamPoint, float RedColor, float GreenColor, float BlueColor) {
	glPointSize(tamPoint);
	glBegin(GL_POINTS);
	glColor3f(RedColor, GreenColor, BlueColor);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}


void pintaSpline(float vectorX[5], float vectorY[5], int tamanoDelVector) {

	float a = 0, b = 0, t = 0;


	switch (tamanoDelVector)
	{
	case 3:
		do {

			a = ((((1 - t) * (1 - t)) * vectorCoorX[0]) + ((2 * t) * (1 - t) * vectorCoorX[1]) + ((t * t) * vectorCoorX[2]));


			b = ((((1 - t) * (1 - t)) * vectorCoorY[0]) + ((2 * t) * (1 - t) * vectorCoorY[1]) + ((t * t) * vectorCoorY[2]));


			t = t + 0.001;
			pintaPixel(a, b, 1, 1, 0, 1);

		} while (t <= 1);
	
		break;
	case 4:
		
		do {
			a = (vectorCoorX[0] * ((1 - t) * (1 - t) * (1 - t))) + (3 * vectorCoorX[1] * t * ((1 - t) * (1 - t))) + (3 * vectorCoorX[2] * (t * t) * (1 - t)) + (vectorCoorX[3] * (t * t * t));
			b = (vectorCoorY[0] * ((1 - t) * (1 - t) * (1 - t))) + (3 * vectorCoorY[1] * t * ((1 - t) * (1 - t))) + (3 * vectorCoorY[2] * (t * t) * (1 - t)) + (vectorCoorY[3] * (t * t * t));
			t = t + 0.001;
			pintaPixel(a, b, 1, 0, 0, 1);
		} while (t <= 1);

		glFlush();

		glFlush();

		break;


	case 5:
		do {

			a = (vectorX[1 - 1] * ((1 - t) * (1 - t) * (1 - t) * (1 - t))) + (4 * vectorX[2 - 1] * t * ((1 - t) * (1 - t) * (1 - t))) + (4 * vectorX[3 - 1] * (t * t) * (1 - t) * (1 - t)) + (4 * vectorX[4 - 1] * (t * t * t) * (1 - t)) + (vectorX[5 - 1] * (t * t * t * t));
			b = (vectorY[1 - 1] * ((1 - t) * (1 - t) * (1 - t) * (1 - t))) + (4 * vectorY[2 - 1] * t * ((1 - t) * (1 - t) * (1 - t))) + (4 * vectorY[3 - 1] * (t * t) * (1 - t) * (1 - t)) + (4 * vectorY[4 - 1] * (t * t * t) * (1 - t)) + (vectorY[5 - 1] * (t * t * t * t));

			t = t + 0.001;
			pintaPixel(a, b, 2, 1, 0, 1);

		} while (t <= 1);

		break;
	default:
		break;
	}




}

void instrucciones() {

	cout << "Ingrese la opcion que mas le interese ejecutar para la linea spline" << endl << endl;
	cout << "1. Spline de 3 puntos" << endl;
	cout << "2. Spline de 4 puntos" << endl;
	cout << "3. Spline de 5 puntos" << endl << endl;
	cout << "Su Opcion: ";
	cin >> opcion;

	cout <<  opcion << endl;

}

void ingresaMouse(int button, int state, int x, int y) {

	switch (opcion)
	{
	case 1:
		tamVector = 3;


		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if (cuentaClicks == 1) {
				pintaPixel(x, y, 4, 1, 0, 0);
				vectorCoorX[0] = x;
				vectorCoorY[0] = y;
				cout << vectorCoorX[0] << endl;
				cout << vectorCoorY[0] << endl;
			}
			else if (cuentaClicks == 2) {
				pintaPixel(x, y, 2, 1, 0.5, 0);
				vectorCoorX[1] = x;
				vectorCoorY[1] = y;
				cout << vectorCoorX[1] << endl;
				cout << vectorCoorY[1] << endl;
			}
			else if (cuentaClicks == 3) {
				pintaPixel(x, y, 4, 1, 0, 0);
				vectorCoorX[2] = x;
				vectorCoorY[2] = y;
				cout << vectorCoorX[2] << endl;
				cout << vectorCoorY[2] << endl;
				cuentaClicks = 0;
				cout << "fin linea" << endl;
				pintaSpline(vectorCoorX, vectorCoorY, tamVector);
			}

			cuentaClicks = cuentaClicks + 1;

		}

		break;

	case 2:

		tamVector = 4;

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if (cuentaClicks == 1) {
				pintaPixel(x, y, 4, 1, 0, 0);
				vectorCoorX[0] = x;
				vectorCoorY[0] = y;
				cout << vectorCoorX[0] << endl;
				cout << vectorCoorY[0] << endl;
			}
			else if (cuentaClicks == 2) {
				pintaPixel(x, y, 2, 1, 0.8, 0);
				vectorCoorX[1] = x;
				vectorCoorY[1] = y;
				cout << vectorCoorX[1] << endl;
				cout << vectorCoorY[1] << endl;
			}
			else if (cuentaClicks == 3) {
				pintaPixel(x, y, 2, 1, 0.8, 0);
				vectorCoorX[2] = x;
				vectorCoorY[2] = y;
				cout << vectorCoorX[2] << endl;
				cout << vectorCoorY[2] << endl;
			}
			else if (cuentaClicks == 4) {
				pintaPixel(x, y, 4, 1, 0, 0);
				vectorCoorX[3] = x;
				vectorCoorY[3] = y;
				cout << vectorCoorX[3] << endl;
				cout << vectorCoorY[3] << endl;
				cuentaClicks = 0;
				cout << "fin linea" << endl;
				pintaSpline(vectorCoorX, vectorCoorY, tamVector);
			}

			cuentaClicks = cuentaClicks + 1;

		}

		break;

	case 3:

		tamVector = 5;


		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if (cuentaClicks == 1) {
				pintaPixel(x, y, 4, 1, 0, 0);
				vectorCoorX[0] = x;
				vectorCoorY[0] = y;
				cout << vectorCoorX[0] << endl;
				cout << vectorCoorY[0] << endl;
			}
			else if (cuentaClicks == 2) {
				pintaPixel(x, y, 2, 1, 0.5, 0);
				vectorCoorX[1] = x;
				vectorCoorY[1] = y;
				cout << vectorCoorX[1] << endl;
				cout << vectorCoorY[1] << endl;
			}
			else if (cuentaClicks == 3) {
				pintaPixel(x, y, 2, 1, 0.5, 0);
				vectorCoorX[2] = x;
				vectorCoorY[2] = y;
				cout << vectorCoorX[2] << endl;
				cout << vectorCoorY[2] << endl;
			}
			else if (cuentaClicks == 4) {
				pintaPixel(x, y, 4, 1, 0.5, 0);
				vectorCoorX[3] = x;
				vectorCoorY[3] = y;
				cout << vectorCoorX[3] << endl;
				cout << vectorCoorY[3] << endl;
			}
			else if (cuentaClicks == 5) {
				pintaPixel(x, y, 4, 1, 0, 0);
				vectorCoorX[4] = x;
				vectorCoorY[4] = y;
				cout << vectorCoorX[4] << endl;
				cout << vectorCoorY[4] << endl;
				cuentaClicks = 0;
				cout << "fin linea" << endl;
				pintaSpline(vectorCoorX, vectorCoorY, tamVector);
			}

			cuentaClicks = cuentaClicks + 1;

		}

		break;


	default:

		cout << "ALERTA, EL NUMERO DE PUNTOS INGRESADO ES UN VALOR NO CONTEMPLADO EN EL PROGRAMA" << endl;

		break;
	}


}

void displayInit() {
	glutMouseFunc(ingresaMouse);
	glFlush();
}


int main(int argc, char* argv[]) {
	instrucciones();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(700, 200);
	glutCreateWindow("CURVAS SPLINE");
	gluOrtho2D(0, xPantalla, yPantalla, 0);
	glutDisplayFunc(displayInit);
	glutMainLoop();
	return 0;
}
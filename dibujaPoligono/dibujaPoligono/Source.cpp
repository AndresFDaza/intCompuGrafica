//ANDRÉS FELIPE DAZA MORENO - 1201956

using namespace std;

#include <iostream>
#include "glut.h"

const int xPantalla = 700, yPantalla = 500; //global para cambio tamaño pantalla

int xi, yi, xf, yf; // global de puntos linea
bool clickActivo = false;

int matrizPixeles[xPantalla][yPantalla];
int vectorSize = 0, cuentaClicks = 0;
int x1Poligono, y1Poligono, x2Poligono, y2Poligono, Xmin, Xmax, Ymin, Ymax; //globar insercion puntos poligono

int* verticeCX = new int[vectorSize];
int* verticeCY = new int[vectorSize];



// dibuja pixel individual
void pintaPixel(float xPos, float yPos, float RedColor, float GreenColor, float BlueColor, int tamPoint) {
	glPointSize(tamPoint);
	glColor3f(RedColor, GreenColor, BlueColor);
	glBegin(GL_POINTS);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

void pintaLinea() {
	float m = 0, dx = 0, dy = 0, b = 0, Fx = 0, Fy = 0;
	dx = xf - xi;
	dy = yf - yi;

	if (dx != 0) {
		m = dy / dx;
		b = yi - (m * xi);


		// Línea horizontal
		if (dy == 0) {
			if (xi > xf) {
				for (int i = xf; i < xi; i++) {
					pintaPixel(i, yf, 1, 1, 1, 2);
				}
			}
			else {
				for (int i = xi; i < xf; i++) {
					pintaPixel(i, yi, 1, 1, 1, 2);
				}
			}
		}

		//linea pendiente positiva
		if (m > 0) {

			//funcion a graficacion en Fx
			if (fabs(dx) > fabs(dy)) {
				if (xi > xf) {
					for (int i = xf; i < xi; i++) {
						Fx = m * i + b;
						pintaPixel(i, Fx, 1, 0.08, 0.6, 2);
					}
				}
				else {
					for (int i = xi; i < xf; i++) {
						Fx = m * i + b;
						pintaPixel(i, Fx, 1, 0.08, 0.6, 2);
					}
				}
			}
			//funcion a graficacion en Fy
			else {
				if (yi > yf) {
					for (int i = yf; i < yi; i++) {
						Fy = (i - b) / m;
						pintaPixel(Fy, i, 1, 0.08, 0.6, 2);
					}
				}
				else {
					for (int i = yi; i < yf; i++) {
						Fy = (i - b) / m;
						pintaPixel(Fy, i, 1, 0.08, 0.6, 2);
					}
				}
			}


		}


		//Linea pendiente negativa
		if (m < 0) {

			//funcion a graficacion en Fx
			if (fabs(dx) > fabs(dy)) {
				if (xi > xf) {
					for (int i = xf; i < xi; i++) {
						Fx = m * i + b;
						pintaPixel(i, Fx, 0.3, 0, 0.51, 2);
					}
				}
				else {
					for (int i = xi; i < xf; i++) {
						Fx = m * i + b;
						pintaPixel(i, Fx, 0.3, 0, 0.51, 2);
					}
				}
			}
			//funcion a graficacion en Fy
			else {
				if (yi > yf) {
					for (int i = yf; i < yi; i++) {
						Fy = (i - b) / m;
						pintaPixel(Fy, i, 0.3, 0, 0.51, 2);
					}
				}
				else {
					for (int i = yi; i < yf; i++) {
						Fy = (i - b) / m;
						pintaPixel(Fy, i, 0.3, 0, 0.51, 2);
					}
				}
			}


		}
	}


	// Línea vertical
	else {
		if (yi < yf) {
			for (int i = yi; i < yf; i++) {
				pintaPixel(xi, i, 1, 1, 1, 2);
			}
		}
		else {
			for (int i = yf; i < yi; i++) {
				pintaPixel(xf, i, 1, 1, 1, 2);
			}
		}
	}
}

void calcularMaxMin() {
	Xmin = xPantalla;
	Xmax = 0;
	Ymin = yPantalla;
	Ymax = 0;

	for (int i = 0; i < vectorSize; i++) {

		if (Xmin > verticeCX[i])
			Xmin = verticeCX[i];

		if (Xmax > verticeCX[i])
			Xmax = verticeCX[i];

		if (Ymin > verticeCY[i])
			Ymin = verticeCY[i];

		if (Ymax > verticeCY[i])
			Ymax = verticeCY[i];
	}

}

void ressetAllValues() {

	cuentaClicks = 0;
	vectorSize = 0;
	clickActivo = false;

	x2Poligono = NULL;
	y2Poligono = NULL;
}

void rellenarPoligono() {

	int cuentaPixel = 1;

	for (int j = Ymin; j <= Ymax; j++) {
		cuentaPixel = 1;

		for (int i = Xmin; i <= Xmax; i++) {

			if (cuentaPixel <= 2) {

				if (matrizPixeles[j][i] == 1) {
					if (cuentaPixel % 2 != 0) {
						if (matrizPixeles[i][j + 1] == 0) {
							xi = i;
							yf = j;
							cuentaPixel = cuentaPixel + 1;
						}
					}


					else if (cuentaPixel % 2 == 0) {
						if (matrizPixeles[j][i - 1] == 0) {
							xf = i;
							yf = j;
							pintaLinea();
							cuentaPixel = cuentaPixel + 1;
						}
					}
				}

			}

		}


	}

}

void insertaPuntosPoligono(int btn, int state, int x, int y) {


	if (clickActivo == false) {
		if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{

			xi = x;
			yi = y;
			verticeCX[cuentaClicks] = xi;
			verticeCY[cuentaClicks] = yi;

			if (x2Poligono != NULL && y2Poligono != NULL) {

				pintaPixel(x1Poligono, x2Poligono, 0, 1, 0, 10);

			}
			else {
				pintaLinea();

			}

			cuentaClicks = cuentaClicks + 1;
			vectorSize = vectorSize + 1;

			clickActivo = true;
		}
	}
	else if (clickActivo == true) {

		if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			xf = x;
			yf = y;
			verticeCX[cuentaClicks] = xf;
			verticeCY[cuentaClicks] = yf;
			pintaLinea();

			cuentaClicks = cuentaClicks + 1;
			vectorSize = vectorSize + 1;

			clickActivo = false;
		}


	}
	if (cuentaClicks > 2) {
		
		if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			xi = verticeCX[vectorSize - 1];
			yi = verticeCY[vectorSize - 1];
			xf = verticeCX[0];
			yf = verticeCY[0];

			pintaLinea();

			calcularMaxMin();

			rellenarPoligono();

			ressetAllValues();
			

		}

	}

}

void EMPTYdisplayFunc(){
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rellenado de un poligono");
	gluOrtho2D(0, xPantalla, yPantalla, 0);
	glutMouseFunc(insertaPuntosPoligono);
	glutDisplayFunc(EMPTYdisplayFunc);
	glutMainLoop();
	return 0;
}
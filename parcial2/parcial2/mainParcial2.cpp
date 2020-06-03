//ANDRÉS FELIPE DAZA MORENO - 1201956

using namespace std;

#include <iostream>
#include "glut.h"
#include <math.h>

int xi = 0, yi = 0, xf = 0, yf = 0; // global de puntos linea

int a = 0, b = 0, x = 0, y = 0, radio=0;  // global de puntos circulo

int xPantalla, yPantalla; //global para cambio tamaño pantalla

// dibuja pixel individual
void pintaPixel(float xPos, float yPos, float RedColor, float GreenColor, float BlueColor, int tamPoint) {
	glPointSize(tamPoint);
	glColor3f(RedColor, GreenColor, BlueColor);
	glBegin(GL_POINTS);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

// dibuja linea
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

//dibuja circunferencia
void pintaCircunferencia() {
	
	double circX = 0, circY = 0;

	int grosorCirculo = 2;

	radio = sqrt(pow(x - a, 2) + pow(y - b, 2));

	do{
		circY = sqrt(pow(radio, 2) - pow(circX, 2));

		//primer cuadrante
		pintaPixel(circX + a, circY + b, 1, 1, 1, grosorCirculo);
		glFlush();
		pintaPixel(circY + a, circX + b, 1, 1, 1, grosorCirculo);
		glFlush();


		//segundo cuadrante
		pintaPixel(circX + a, -circY + b, 1, 1, 1, grosorCirculo);
		glFlush();

		pintaPixel(circY + a, -circX + b, 1, 1, 1, grosorCirculo);
		glFlush();


		//tercer cuadrante
		pintaPixel(-circX + a, -circY + b, 1, 1, 1, grosorCirculo);
		glFlush();

		pintaPixel(-circY + a, -circX + b, 1, 1, 1, grosorCirculo);
		glFlush();


		//cuarto cuadrante
		pintaPixel(-circX + a, circY + b, 1, 1, 1, grosorCirculo);
		glFlush();

		pintaPixel(-circY + a, circX + b, 1, 1, 1, grosorCirculo);
		glFlush();


		circX = circX + 1;


	} while (circX <= radio);
}

//funciones dibujan formas (3)
void marcoExterior() {
	// dibujar marco exterior

	// superior
	xi = (-xPantalla / 2 + (xPantalla * 0.02));
	yi = (yPantalla / 2 - (xPantalla * 0.02));

	xf = (xPantalla / 2 - (xPantalla * 0.02));
	yf = (yPantalla / 2 - (xPantalla * 0.02));

	pintaLinea();

	//derecha

	xi = xf;
	yi = yf;

	xf = (xPantalla / 2 - (xPantalla * 0.02));
	yf = (-yPantalla / 2 + (xPantalla * 0.02));

	pintaLinea();

	//inferior
	xi = xf;
	yi = yf;

	xf = (-xPantalla / 2 + (xPantalla * 0.02));
	yf = (-yPantalla / 2 + (xPantalla * 0.02));

	pintaLinea();

	//izquierda

	xi = xf;
	yi = yf;

	xf = (-xPantalla / 2 + (xPantalla * 0.02));
	yf = (yPantalla / 2 - (xPantalla * 0.02));

	pintaLinea();
}
void marcoInterior() {

	//dibujar marco interior

		// superior
	xi = (-xPantalla / 2 + (xPantalla * 0.04));
	yi = (yPantalla / 2 - (xPantalla * 0.04));

	xf = (xPantalla / 2 - (xPantalla * 0.12));
	yf = (yPantalla / 2 - (xPantalla * 0.04));

	pintaLinea();

	//derecha

	xi = xf;
	yi = yf;

	xf = (xPantalla / 2 - (xPantalla * 0.12));
	yf = (-yPantalla / 2 + (xPantalla * 0.04));

	pintaLinea();

	//inferior
	xi = xf;
	yi = yf;

	xf = (-xPantalla / 2 + (xPantalla * 0.04));
	yf = (-yPantalla / 2 + (xPantalla * 0.04));

	pintaLinea();

	//izquierda

	xi = xf;
	yi = yf;

	xf = (-xPantalla / 2 + (xPantalla * 0.04));
	yf = (yPantalla / 2 - (xPantalla * 0.04));

	pintaLinea();
}
void botones() {
	//constantes eje x
	a = (xPantalla / 2 - (xPantalla * 0.07));
	x = (xPantalla / 2 - (xPantalla * 0.04));


	// dibuja circulo 1
	b = (yPantalla / 2 - (xPantalla * 0.07));
	y = b;
	glFlush();
	pintaCircunferencia();

	//dibuja circulo 2
	b = (yPantalla / 2 - (xPantalla * 0.18));
	y = b;
	glFlush();
	pintaCircunferencia();


	// dibuja circulo 3
	b = (yPantalla / 2 - (xPantalla * 0.29));
	y = b;
	glFlush();
	pintaCircunferencia();
}


//dibuja la pantalla basado en el tamaño relativo al ingresado por consola
void pintaPantalla() {

	marcoExterior();
	marcoInterior();
	botones();

}

int main(int argc, char* argv[]) {

	cout << "Ingrese tamaño en pixeles del ancho de pantalla: " << endl;
	cin >> xPantalla;

	cout << "Ingrese tamaño en pixeles del alto de pantalla: " << endl;
	cin >> yPantalla;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Evaluacion practica II");
	gluOrtho2D(-xPantalla / 2, xPantalla / 2, -yPantalla / 2, yPantalla / 2);
	glutDisplayFunc(pintaPantalla);
	glutMainLoop();
	return 0;
}
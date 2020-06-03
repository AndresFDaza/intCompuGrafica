#include <iostream>
#include <math.h>
#include "glut.h"

int a = 0, b = 0, x = 0, y = 0, z = 0, cuentaClicks=0;
double radioA = 0, radioB = 0, foco = 0;  // global de puntos insertados

int xPantalla = 800, yPantalla = 800; //global para cambio tamaño pantalla

// Funcion pinta pixel individual
void pixel(float xPos, float yPos, float RedColor, float GreenColor, float BlueColor, int tamPoint) {
	glPointSize(tamPoint);
	glColor3f(RedColor, GreenColor, BlueColor);
	glBegin(GL_POINTS);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

//Funcion pinta ejes x y y
void pintaPlano() {
	//pintar plano, lineas por mitad del tamaño total - color gris

	for (int i = -xPantalla / 2; i < xPantalla / 2; i++) {
		pixel(i, 0, 0.5, 0.5, 0.5, 2);
	}
	for (int i = -xPantalla / 2; i < xPantalla / 2; i++) {
		pixel(0, i, 0.5, 0.5, 0.5, 2);
	}
}

//Funcion para pintar un circulo
void pintaOvalo() {

	double XOvalo = 0, YOvalo = 0;

	int grosorOvalo = 3;

	radioA = sqrt((x - a) * (x - a));
	radioB = sqrt((z - b) * (z - b));

	if (radioA <= radioB) {

		foco = sqrt(pow(radioB, 2) - pow(radioA, 2));

		do {

			XOvalo = radioA * sqrt(1 - (pow(YOvalo, 2) / pow(radioB, 2)));

			pixel(XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);

			pixel(XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);

			pixel(-XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);

			pixel(-XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);

			

			YOvalo = YOvalo + 1;

		} while (YOvalo <= foco);

		do {

			YOvalo = radioB * sqrt(1 - (pow(XOvalo, 2) / pow(radioA, 2)));

			pixel(XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);

			pixel(XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);

			pixel(-XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);

			pixel(-XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);


			XOvalo = XOvalo - 1;

		} while (XOvalo > 0);


	}

	if (radioA > radioB) {

		foco = sqrt(pow(radioA, 2) - pow(radioB, 2));

		do {

			YOvalo = radioB * sqrt(1 - (pow(XOvalo, 2) / pow(radioA, 2)));

			//primer cuadrante
			pixel(XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);
		

			//segundo cuadrante
			pixel(XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);
			

			//tercer cuadrante
			pixel(-XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);
			

			//cuarto cuadrante
			pixel(-XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);
			


			XOvalo = XOvalo + 1;

		} while (XOvalo <= foco);

		do {

			XOvalo = radioA * sqrt(1 - (pow(YOvalo, 2) / pow(radioB, 2)));

			//primer cuadrante
			pixel(XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);
			//pixel(YOvalo + a, XOvalo + b, 1, 1, 1, grosorOvalo);

			//segundo cuadrante
			pixel(XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);
			//pixel(YOvalo + a, -XOvalo + b, 1, 1, 1, grosorOvalo);

			//tercer cuadrante
			pixel(-XOvalo + a, -YOvalo + b, 1, 1, 1, grosorOvalo);
			//pixel(-YOvalo + a, -XOvalo + b, 1, 1, 1, grosorOvalo);

			//cuarto cuadrante
			pixel(-XOvalo + a, YOvalo + b, 1, 1, 1, grosorOvalo);
			//pixel(-YOvalo + a, XOvalo + b, 1, 1, 1, grosorOvalo);


			YOvalo = YOvalo - 1;

		} while (YOvalo > 0);

	}

}

//Funcion lee puntos central y de radio
void clickeaMouse(int button, int state, int xPos, int yPos)	 {

	xPos = xPos - xPantalla / 2;
	yPos = yPantalla / 2 - yPos;


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (cuentaClicks == 0) {
			a = xPos;
			b = yPos;
			pixel(a, b, 0, 0, 1, 6);
			cuentaClicks++;
		}
		else if (cuentaClicks == 1) {
			x = xPos;
			y = yPos;
			pixel(x, y, 1, 0, 0, 6);
			cuentaClicks++;
		}
		else if (cuentaClicks == 2) {
			z = y - yPos;
			pintaOvalo();
			cuentaClicks = 0;
		}
	
	}

	/*
	
	//punto centro
	if (click == false) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			a = xPos;
			b = yPos;
			pixel(a, b, 0, 0, 1, 6);
			click = true;
		}
	}
	//punto radio
	else {
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			x = xPos;
			y = yPos;
			pixel(x, y, 1, 0, 0, 6);
			z = 40;
			pintaOvalo();
			click = false;
			glFlush();
		}
	}
	
	*/

}

//Funcion principal (main)
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("ALGORITMO PARA DIBUJAR UN OVALO");
	gluOrtho2D(-xPantalla / 2, xPantalla / 2, -yPantalla / 2, yPantalla / 2); //origen "vista- camara" en el centro de la pantalla (tamaño en global)
	glutDisplayFunc(pintaPlano);
	glutMouseFunc(clickeaMouse);
	glutMainLoop();
	return 0;
}
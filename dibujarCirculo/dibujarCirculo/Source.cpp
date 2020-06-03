#include <iostream>
#include <math.h>
#include "glut.h"

bool click = false;
int a = 0, b = 0, x = 0, y = 0, radio = 0;  // global de puntos insertados

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
void pintaCirculo() {

	double radio, circX, circY;

	int grosorCirculo = 3;

	radio = sqrt(pow(x - a, 2) + pow(y - b, 2));

	circX = a;

	while (circX <= radio) {
		circY = sqrt(pow(radio, 2) - pow(circX, 2));

		//primer cuadrante
		pixel(circX + a, circY + b, 1, 1, 1, grosorCirculo);
		pixel(circY + a, circX + b, 1, 1, 1, grosorCirculo);

		//segundo cuadrante
		pixel(circX + a, -circY + b, 1, 1, 1, grosorCirculo);
		pixel(circY + a, -circX + b, 1, 1, 1, grosorCirculo);

		//tercer cuadrante
		pixel(-circX + a, -circY + b, 1, 1, 1, grosorCirculo);
		pixel(-circY + a, -circX + b, 1, 1, 1, grosorCirculo);

		//cuarto cuadrante
		pixel(-circX + a, circY + b, 1, 1, 1, grosorCirculo);
		pixel(-circY + a, circX + b, 1, 1, 1, grosorCirculo);

		circX = circX + 1;

	}


}

//Funcion lee puntos central y de radio
void clickeaMouse(int button, int state, int xPos, int yPos) {

	xPos = xPos - xPantalla / 2;
	yPos = yPantalla / 2 - yPos;

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
			pintaCirculo();
			click = false;
			glFlush();
		}
	}

}

//Funcion principal (main)
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("ALGORITMO PARA DIBUJAR UN CIRCULO");
	gluOrtho2D(-xPantalla / 2, xPantalla / 2, -yPantalla / 2, yPantalla / 2); //origen "vista- camara" en el centro de la pantalla (tamaño en global)
	glutDisplayFunc(pintaPlano);
	glutMouseFunc(clickeaMouse);
	glutMainLoop();
	return 0;
}
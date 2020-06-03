#include <iostream>
#include "glut.h"
#include <math.h>


int xPantalla = 800, yPantalla = 800; //global para cambio tamaño pantalla

void pintaPixel(float xPos, float yPos, float RedColor, float GreenColor, float BlueColor) { //pinta un pixel en posicion y color por parametro
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(RedColor, GreenColor, BlueColor);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

void pintaFuncion() {
	//pintar funcion, amplia el plano al 80% del original


	float fx, gx; //salida funciones g(x) y f(x)

	//como el dominio de la funcion es de -2 a 2 se requieren dibujar pixeles entre cada 0.001% de la escala original

	for (float i = -2 ; i < 2 ; i+=0.001) {
		gx = (acos(1 - abs(i)) - 3.1416) * 80;	
		pintaPixel(i*80, gx, 1, 0, 0);
	}

	for (float i = 2; i > -2; i -= 0.001) {
		fx = (sqrt(1- pow((abs(i) - 1),2))) * 80;
		pintaPixel(i * 80, fx, 1, 0, 0);
	}

	//pintar plano, lineas por mitad del tamaño total - color gris

	for (int i = -xPantalla / 2; i < xPantalla / 2; i++) {
		pintaPixel(i, 0, 0.5, 0.5, 0.5);
	}
	for (int i = -xPantalla / 2; i < xPantalla / 2; i++) {
		pintaPixel(0, i, 0.5, 0.5, 0.5);

	}

}


int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("Funcion Corazón. ALGORITMO 3. DIBUJAR UNA FUNCION MATEMÁTICA");
	gluOrtho2D(-xPantalla / 2, xPantalla / 2, -yPantalla / 2, yPantalla / 2); //origen "vista- camara" en el centro de la pantalla (tamaño en global)
	glutDisplayFunc(pintaFuncion);
	glutMainLoop();
	return 0;
}
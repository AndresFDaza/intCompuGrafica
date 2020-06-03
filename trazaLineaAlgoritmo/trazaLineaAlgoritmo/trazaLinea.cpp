#include "glut.h"
#include <math.h>

bool click = false;
int xi = 0, yi = 0, xf = 0, yf = 0;


void pixel(float xPos, float yPos, float RedColor, float GreenColor, float BlueColor, int tamPoint) { 
	glPointSize(tamPoint);
	glColor3f(RedColor, GreenColor, BlueColor);
	glBegin(GL_POINTS);
	glVertex2f(xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

//dibuja linea basandose en los puntos marcados
void dibujaLinea() {
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
					pixel(i, yf, 1, 0, 0, 2);
				}
			}
			else {
				for (int i = xi; i < xf;  i++) {
					pixel(i, yi, 1, 0, 0, 2);
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
						pixel(i, Fx, 1, 0.08, 0.6, 2);
					}
				}
				else {
					for (int i = xi; i < xf; i++) {
						Fx = m * i + b;
						pixel(i, Fx, 1, 0.08, 0.6, 2);
					}
				}
			}
			//funcion a graficacion en Fy
			else {
				if (yi > yf) {
					for (int i = yf; i < yi; i++) {
						Fy = (i - b) / m;
						pixel(Fy, i, 1, 0.08, 0.6, 2);
					}
				}
				else {
					for (int i = yi; i < yf; i++) {
						Fy = (i - b) / m;
						pixel(Fy, i, 1, 0.08, 0.6, 2);
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
						pixel(i, Fx, 0.3, 0, 0.51, 2);
					}
				}
				else {
					for (int i = xi; i < xf; i++) {
						Fx = m * i + b;
						pixel(i, Fx, 0.3, 0, 0.51, 2);
					}
				}
			}
			//funcion a graficacion en Fy
			else {
				if (yi > yf) {
					for (int i = yf; i < yi; i++) {
						Fy = (i - b) / m;
						pixel(Fy, i, 0.3, 0, 0.51, 2);
					}
				}
				else {
					for (int i = yi; i < yf; i++) {
						Fy = (i - b) / m;
						pixel(Fy, i, 0.3, 0, 0.51, 2);
					}
				}
			}


		}
	}


	// Línea vertical
	else {
			if (yi < yf) {
				for (int i = yi; i < yf; i++) {
					pixel(xi, i, 0, 0, 1, 2);
				}
			}
			else {
				for (int i = yf; i < yi; i++) {
					pixel(xf, i, 0, 0, 1, 2);
				}
			}
	}
}


//marca puntos inicial y final
void clickeaMouse(int button, int state, int xPos, int yPos) {
	xPos = xPos - 400;
	yPos = 400 - yPos;

	//punto inicial
	if (click == false) {
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			xi = xPos;
			yi = yPos;
			pixel(xi, yi, 1, 0, 0, 6);
			click = true;
		}
	}
	//punto final
	else {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			xf = xPos;
			yf = yPos;
			pixel(xf, yf, 0, 0, 1, 6);
			dibujaLinea();
			click = false;
		}
	}
}

void windowFunc() {

}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Linea de la forma y=mx+b ");
	gluOrtho2D(-400, 400, -400, 400);
	glutMouseFunc(clickeaMouse);
	glutDisplayFunc(windowFunc);

	glutMainLoop();
	return 0;

}
#include <iostream>
#include<stdio.h>
#include <time.h>

#include "glut.h"


using namespace std;

int contador = 0, detector = 0;
int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
int tipo = 0;

void dibujar_pixel2(int x1, int y1) {
	glBegin(GL_POINTS);
	glVertex2i(x1, y1);
	glEnd();
	glFlush();

}

void display() {
	dibujar_pixel2(x1, y1);
}
void dispaly() {
	dibujar_pixel2(x1, y1);
}

void bres(int x1, int y1, int x2, int y2) {
	glColor3f(0.2, 1, 0.2);
	int dx, dy, i, e, x, y;
	int incx, incy, inc1, inc2;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)dx = -dx;
	if (dy < 0)dy = -dy;
	incx = 1;
	if (x2 < x1)incx = -1;
	incy = -1;
	if (y2 < y1)incx = -1;
	x = x1;
	y = y1;
	if (dx > dy) {
		dibujar_pixel2(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else e += inc2;
			x += incx;
			dibujar_pixel2(x, y);
		}
	}
	else {
		dibujar_pixel2(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else e += inc2;
			y += incy;
			dibujar_pixel2(x, y);
		}
	}

}

void DDA(int lx1, int ly1, int lx2, int ly2) {
	glColor3f(1, 0.0, 0.2);
	double n = 0.0, b = 0.0; int Dx, Dy;
	Dx = lx2 - lx1; Dy = ly2 - ly1;
	int re = contador % 2;
	float ax, ay, x, y, luz;
	int i, absx, absy;
	if (contador != 0) {
		absx = lx2 - lx1; absy = ly2 - ly1;
		if (absx < 0) {
			absx = -absx;
		}
		if (absy < 0) {
			absy = -absy;
		}

		if (absx > -absy)
			luz = absx;
		else
			luz = absy;
		ax = (lx2 - lx1) / luz;
		ay = (ly2 - ly1) / luz;

		x = (float)lx1;
		y = (float)ly1;

		i = 1;
		while (i <= luz) {
			dibujar_pixel2(x, y);
			x = x + ax;
			y = y + ay;
			i = i + 1;
		}
	}
}

void inicio() {
	glClearColor(1, 0, 0, 0);
	gluOrtho2D(0, 500, 500, 0);
	glPointSize(8);
}

void Raton(int boton, int status, int x, int y) {
	if (boton == GLUT_LEFT_BUTTON && status == GLUT_UP) {
		contador++;
		if (detector == 0) {
			x1 = x; y1 = y;
			dibujar_pixel2(x, y);
			detector = 1;
			contador = 1;
		}
		else {
			x2 = x; y2 = y;
			dibujar_pixel2(x, y);
			detector = 0;
			contador = 2;
		}
	}
	if (x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0) {
		if (tipo == 1) {
			DDA(x1, y1, x2, y2);
		}
		if (tipo == 2) {
			bres(x1, y1, x2, y2);
		}
		x1 = x2 = y1 = y2 = 0;
	}
	glutPostRedisplay();
}

void main_Display() {
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(80, 60);
	glutInitWindowSize(500, 500);
	if (tipo == 1) { glutCreateWindow("DDA"); }
	if (tipo == 2) { glutCreateWindow("BRESENHAM"); }
	inicio();
	glutMouseFunc(Raton);
	glutDisplayFunc(display);
	glutMainLoop();
}

int coor_x = 0, coor_y = 0, coor_x1 = 0, coor_y1 = 0;
int detect = 0;
int cont = 0;
void dibujapixel(int coor_x, int coor_y);

void iniciar() {
	glClearColor(0.5, 0.2, 1, 1);
	glPointSize(6);
	gluOrtho2D(0, 500, 500, 0);
}

void dibujar_pixel(int, int) {
	dibujapixel(coor_x, coor_y);

}
void dibuja_linea(int coor_lix, int coor_liy, int coor_lix1, int coor_liy1) {
	double m = 0.0, b = 0.0, Dx, Dy;
	Dx = coor_x1 - coor_x; Dy = coor_y1 - coor_y;
	int re = cont % 2;
	if (cont != 0) {
		if (re == 0) {
			if (Dx != 0) {
				if (coor_x1 > coor_x&& coor_y1 > coor_y || coor_x1 > coor_x&& coor_y1 < coor_y) {
					double y = 0.0;
					m = Dy / Dx;
					b = coor_y1 - m * coor_x1;
					for (double i - coor_x; i < -coor_x1; i - i + 0.1) {
						y = m * i + b;
						glColor3f(1, 0, 0);
						dibujapixel(i, y);
					}
				}
				if (coor_x1 > coor_x&& coor_y1 > coor_y || coor_x1 > coor_x&& coor_y1 < coor_y) {
					double y = 0.0;
					m = Dy / Dx;
					b = coor_y1 - m * coor_x1;
					for (double i - coor_x; i < -coor_x1; i - i + 0.1) {
						y = m * i + b;
						glColor3f(1, 0, 0);
						dibujapixel(i, y);
					}

				}
			}
		}
	}}

void controlRaton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		cont++;
		if (detect == 0) {
			coor_x = x; coor_y = y;
			detect = 1;
			cont = 1;

		}
		else {
			coor_x1 = x; coor_y1 = y;
			dibujapixel(x, y);
			detect = 0;
			cont = 2;
		}
		dibuja_linea(coor_x1, coor_x, coor_y1, coor_y1 - y);
		glutPostRedisplay;
	}
}

void dibuja_pixel() {}

void dibujapixel(int coor_x, int coor_y) {
	glBegin(GL_POINTS);
	glVertex2i(coor_x, coor_y);
	glEnd();
	glFlush();
}
int main1() {
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DBUJAR LINEA");
	glutDisplayFunc(dibujar_pixel);
	glutMouseFunc(controlRaton);
	iniciar();
	glutMainLoop();
	return 0;
}

int main() {
	int op = 0;
	do {
		printf("MENU");
		printf("1-ALGORITMO DDA");
		printf("2-ALGORITMO BRESENHAM");
		printf("3-DIBUJAR LINEA");
		printf("4-SALIR");
		scanf_s("%d", &op);

		switch (op) {
		default:
			printf("Esta opcion no es valida");
			break;
		case 1:
			tipo = 1;
			main_Display();
			break;
		case 2:
			tipo = 2;
			main_Display();
			break;
		case 3:
			main1();
			break;
		case 4:
			printf("Gracias");
			break;
		}
	} while (op != 4);
}
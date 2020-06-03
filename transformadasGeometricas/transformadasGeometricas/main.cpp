//ANDRÉS FELIPE DAZA MORENO - 1201956
// SERGIO 

using namespace std;

#include <iostream>
#include "glut.h"
#include <math.h>

//int xi = 0, yi = 0, xf = 0, yf = 0; // global de puntos linea
int xPantalla = 1280, yPantalla = 720; //global para cambio tamaño pantalla

int Poligono3X3[8][3] = { {0,0,1} , {100,0,1} , {100,0,1} , {100,100,1} , 
						{100,100,1} , {0,100,1} , {0,100,1} , {0,0,1} };

double XTranslacion = 0, YTranslacion = 0, movimientoTranslacion = 3;

double XEscalacion = 1, YEscalacion = 1, aumentoEscalacion = 0.1;

double gradoRotacion = 0;

double XPivote, YPivote;

double aux1[8][3], aux2[8][3];


double traslacion[3][3] = { { 1,0,0 } , { 0,1,0 } , { XTranslacion, YTranslacion,1 } };

double escalacionPP[3][3] = { { XEscalacion,0,0 },
							{ 0,YEscalacion,0 },
							{ XPivote - (XPivote * aumentoEscalacion) , YPivote - (YPivote * YEscalacion) , 1 } };

double rotacionPP[3][3] = { { cos(gradoRotacion)  ,  -sin(gradoRotacion)  ,   XPivote * (1 - cos(gradoRotacion)) + (YPivote * sin(gradoRotacion)) },
							{ sin(gradoRotacion)  ,  cos(gradoRotacion)   ,   YPivote * (1 - cos(gradoRotacion) - XPivote * sin(gradoRotacion)) },
							{ 0,0,1 } };


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
/*
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
*/

void pintaLinea(float xi, float yi, float xf, float yf)
{
	glBegin(GL_LINES);
	glVertex2d(xi, yi);
	glVertex2d(xf, yf);
	glColor3f(1, 1, 1);
	glEnd();
	glFlush();
}


/*
void poligonoEjemplo() {


		xi = 0;
		yi = 0;

		xf = xi + 100;
		yf = yi;

		pintaLinea();


		xi = xf;
		yi = yf;

		xf = xi;
		yf = yi + 100;

		pintaLinea();

		xi = xf;
		yi = yf;

		xf = xi - 100;
		yf = yi;

		pintaLinea();

		xi = xf;
		yi = yf;

		xf = xi;
		yf = yi - 100;

		pintaLinea();

}

*/


void dibujaPoligono() {
	for (int i = 0; i < 7; i++)
	{
		pintaLinea(aux1[i][0], aux1[i][1], aux1[i + 1][0], aux1[i + 1][1]);
	}
	glFlush();
}

void obtenerMatrices()
{
	for (int i = 0; i < 8; i++)
	{
		aux1[i][0] = Poligono3X3[i][0];
		aux1[i][1] = Poligono3X3[i][1];
		aux1[i][2] = Poligono3X3[i][2];

		aux2[i][0] = Poligono3X3[i][0];
		aux2[i][1] = Poligono3X3[i][1];
		aux2[i][2] = Poligono3X3[i][2];
	}
}

void multiplicaMatriz(double matrizTransformada[3][3], int matrizPoligono[3][3]) {



	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			aux1[j][i] = aux2[j][0] * matrizTransformada[0][i] + aux2[j][1] * matrizTransformada[1][i] + aux2[j][2] * matrizTransformada[2][i];
		}
	}
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			aux2[j][i] = aux1[j][i];
		}
	}
	XPivote = aux1[0][0];
	YPivote = aux1[0][1];



	/*
		for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			matrizPoligono[j][i] = matrizPoligono[j][0] * matrizTransformada[0][i] + matrizPoligono[j][1] * matrizTransformada[1][i] + matrizPoligono[j][2] * matrizTransformada[2][i];
		}
	}

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			aux2[j][i] = aux1[j][i];
		}
	}
	
	XPivote = matrizPoligono[0][0];
	YPivote = matrizPoligono[0][1];
	
	*/

}


void pintaPantalla() {

	glClear(GL_COLOR_BUFFER_BIT);
	obtenerMatrices();
	pintaPixel(XPivote, YPivote, 1, 1, 1, 10);

	multiplicaMatriz(traslacion, Poligono3X3);
	multiplicaMatriz(escalacionPP, Poligono3X3 );
	multiplicaMatriz(rotacionPP, Poligono3X3);

	dibujaPoligono();
	glFlush();
}



void transformadaTeclado( unsigned char key, int x, int y) {

	bool keyESC = false;

	switch (key)
	{
	case 't':		

		//translacion circular infinita hasta la tecla esc
		
		XTranslacion = XTranslacion + 300;
		traslacion[2][0] = XTranslacion;
		traslacion[2][1] = YTranslacion;
		pintaPantalla();
		
		for  (int i = 0; i < 500; i++){

			for (int j = 0; j < 10000000; j++) {

				switch (key)
				{
				case 27:
					i = 500;
					break;
				default:
					continue;
					break;
				}

			}
			transformadaTeclado('r', 0, 0);
		}

		XTranslacion = XTranslacion - 300;
		traslacion[2][0] = XTranslacion;
		pintaPantalla();
	
		
	

		
		break;

	case 'e':
		//escalacion del 10%
		
		XEscalacion = XEscalacion + XEscalacion * aumentoEscalacion;
		YEscalacion = YEscalacion + YEscalacion * aumentoEscalacion;
		escalacionPP[0][0] = XEscalacion;
		escalacionPP[1][1] = YEscalacion;
		escalacionPP[2][0] = XPivote - (XPivote * XEscalacion);
		escalacionPP[2][1] = YPivote - (YPivote * YEscalacion);
		pintaPantalla();
		break;
		
		
		case'r':
		//rotacion de 10° a la derecha
		gradoRotacion = gradoRotacion - 10*(3.1416/180);

		rotacionPP[0][0] = cos(gradoRotacion);
		rotacionPP[0][1] = -sin(gradoRotacion);
		rotacionPP[0][2] = XPivote * (1 - cos(gradoRotacion)) + (YPivote * sin(gradoRotacion));
		rotacionPP[1][0] = sin(gradoRotacion);
		rotacionPP[1][1] = cos(gradoRotacion);
		rotacionPP[1][2] = YPivote * (1 - cos(gradoRotacion) - XPivote * sin(gradoRotacion));
		pintaPantalla();

		break;

	default:
		break;
	}



}

int main(int argc, char* argv[]) {


	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("TRANSFORMADAS 2D");
	gluOrtho2D(-xPantalla/2, xPantalla/2, yPantalla/2, -yPantalla/2);
	glutDisplayFunc(pintaPantalla);
	glutKeyboardFunc(transformadaTeclado);
	glutMainLoop();
	return 0;
}
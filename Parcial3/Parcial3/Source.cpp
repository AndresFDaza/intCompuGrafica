//ANDRÉS FELIPE DAZA MORENO - 1201956
// SANTIAGO RAMIREZ - 1202219


using namespace std;

#include <iostream>
#include "glut.h"
#include <math.h>

int cuentaClicks = 1;
double xP1, yP1, xP2, yP2, xP3, yP3, xP4, yP4;

int xPantalla = 1000, yPantalla = 800; //global cambio tamaño pantalla

const int tamCamionPuntos = 16, tamVentanaPuntos = 8, tamCargaPuntos = 12;

double aux1[tamCamionPuntos][3], aux2[tamVentanaPuntos][3], aux3[tamCargaPuntos][3];

int circA = 0, circB = 0, x = 0, y = 0, radio = 0;  // global de puntos circulo


int camionPoligono[tamCamionPuntos][3] = {
{76,246,1},{76,195,1},{76,195,1},{117,122,1},{117,122,1},{197,122,1},
{197,122,1},{197,222,1},{197,222,1},{391,222,1},{391,222,1},{391,249,1},

{391,249,1},{83,249,1},{80,249,1},{76,246,1},
};

int VentanaPoligono[tamVentanaPuntos][3] = {
{104,184,1},{131,137,1},{131,137,1},{166,137,1},{166,137,1},{166,184,1},
{166,184,1},{104,184,1},
};

int CargaPoligono[tamCargaPuntos][3] = {
{202,217,1},{202,97,1},{202,97,1},{207,90,1},{207,90,1},{378,90,1},
{378,90,1},{385,97,1},{385,97,1},{385,217,1},{385,217,1},{202,217,1},

};



void pintaPixel(int xPos, int yPos, int tamPoint, int redColor, int greenColor, int blueColor) {
	glColor3f(redColor, greenColor, blueColor);
	glPointSize(tamPoint);
	glBegin(GL_POINTS);
	glVertex2f(xPos, yPos);
	glEnd();
}

void pintaLinea(float xi, float yi, float xf, float yf)
{
	glBegin(GL_LINES);
	glVertex2d(xi, yi);
	glVertex2d(xf, yf);
	glColor3f(1, 1, 1);
	glEnd();
	glFlush();
}



void pintaCircunferencia(int redColor, int greenColor, int blueColor) {

	double circX = 0, circY = 0;

	int grosorCirculo = 1;

	radio = sqrt(pow(x - circA, 2) + pow(y - circB, 2));

	do {
		circY = sqrt(pow(radio, 2) - pow(circX, 2));

		//primer cuadrante
		pintaPixel(circX + circA, circY + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();
		pintaPixel(circY + circA, circX + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();


		//segundo cuadrante
		pintaPixel(circX + circA, -circY + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();

		pintaPixel(circY + circA, -circX + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();


		//tercer cuadrante
		pintaPixel(-circX + circA, -circY + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();

		pintaPixel(-circY + circA, -circX + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();


		//cuarto cuadrante
		pintaPixel(-circX + circA, circY + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();

		pintaPixel(-circY + circA, circX + circB, grosorCirculo ,redColor, greenColor, blueColor);
		glFlush();


		circX = circX + 1;


	} while (circX <= radio);
}

void ruedas() {



	// dibuja llanta 1
	circA = 144;
	circB = 250;
	x = circA+30;
	y = circB;
	glFlush();
	pintaCircunferencia(1,1,1);

	//dibuja llanta 2
	circA = 330;
	circB = 250;
	x = circA + 30;
	y = circB;
	glFlush();
	pintaCircunferencia(1,1,1);

	// dibuja rin 1
	circA = 144;
	circB = 250;
	x = circA + 10;
	y = circB;
	glFlush();
	pintaCircunferencia(1,1,1);

	//dibuja rin 2
	circA = 330;
	circB = 250;
	x = circA + 10;
	y = circB;
	glFlush();
	pintaCircunferencia(1,1,1);

	//dibuja luz

	circA = 90;
	circB = 205;
	x = circA + 7.5;
	y = circB;
	glFlush();
	pintaCircunferencia(1,1,1);
}

void dibujaPoligono() {
	for (int i = 0; i < tamCamionPuntos - 1; i++)
	{
		pintaLinea(aux1[i][0], aux1[i][1], aux1[i + 1][0], aux1[i + 1][1]);
	}
	glFlush();

	for (int i = 0; i < tamVentanaPuntos - 1; i++)
	{
		pintaLinea(aux2[i][0], aux2[i][1], aux2[i + 1][0], aux2[i + 1][1]);
	}
	glFlush();

	for (int i = 0; i < tamCargaPuntos - 1; i++)
	{
		pintaLinea(aux3[i][0], aux3[i][1], aux3[i + 1][0], aux3[i + 1][1]);
	}
	glFlush();

	ruedas();
}

void obtenerMatrices()
{
	for (int i = 0; i < tamCamionPuntos; i++)
	{
		aux1[i][0] = camionPoligono[i][0];
		aux1[i][1] = camionPoligono[i][1];
		aux1[i][2] = camionPoligono[i][2];

		aux2[i][0] = VentanaPoligono[i][0];
		aux2[i][1] = VentanaPoligono[i][1];
		aux2[i][2] = VentanaPoligono[i][2];

		aux3[i][0] = CargaPoligono[i][0];
		aux3[i][1] = CargaPoligono[i][1];
		aux3[i][2] = CargaPoligono[i][2];
	}
}

void pintaPOLIGONO() {

	glClear(GL_COLOR_BUFFER_BIT);
	obtenerMatrices();
	dibujaPoligono();

	glFlush();

	
}

void pintaSpline(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	float a = 0, b = 0, t = 0;

	do {
		a = (x1 * ((1 - t) * (1 - t) * (1 - t))) + (3 * x2 * t * ((1 - t) * (1 - t))) + (3 * x3 * (t * t) * (1 - t)) + (x4 * (t * t * t));
		b = (y1 * ((1 - t) * (1 - t) * (1 - t))) + (3 * y2 * t * ((1 - t) * (1 - t))) + (3 * y3 * (t * t) * (1 - t)) + (y4 * (t * t * t));
		t = t + 0.001;
		pintaPixel(a, b, 1, 0, 0, 1);
	} while (t <= 1);

	glFlush();

}

void ingresaClicks(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
		if (cuentaClicks == 1) {
			pintaPixel(x, y, 2, 1, 0.7, 0);
			xP1 = x;
			yP1 = y;
		}
		else if (cuentaClicks == 2) {
			//pintaPixel(x, y, 2, 1, 0.7, 0);
			xP2 = x;
			yP2 = y;
		}
		else if (cuentaClicks == 3) {
			//pintaPixel(x, y, 2, 1, 0.7, 0);
			xP3 = x;
			yP3 = y;
		}
		else if (cuentaClicks == 4) {
			pintaPixel(x, y, 2, 1, 0.7, 0);
			xP4 = x;
			yP4 = y;
			cuentaClicks = 0;
			pintaSpline(xP1, yP1, xP2, yP2, xP3, yP3, xP4, yP4);
		}

		cuentaClicks = cuentaClicks + 1;

	}

}



int main(int argc, char* argv[]) {


	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(10, 200);
	glutCreateWindow("PARCIAL 3");
	gluOrtho2D(0, xPantalla , yPantalla , 0);
	glutDisplayFunc(pintaPOLIGONO);
	glutMouseFunc(ingresaClicks);
	glutMainLoop();
	return 0;
}
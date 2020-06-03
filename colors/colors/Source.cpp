
#include <iostream>
#include <math.h>
#include "glut.h"

using namespace std;

int ancho = 1800, alto = 900;

float Xo = 0, Yo = 0;



void pintaPixel(float x, float y, int octant, float redColor, float greenColor, float blueColor) {

	switch (octant) {
	case 1: glColor3f(redColor, greenColor, blueColor ) ; break; //abajo abajo derecha -> CUARTO
	case 2: glColor3f(redColor, greenColor, blueColor); break; // abajo abajo izquierda -> quinto
	case 3: glColor3f(redColor, greenColor, blueColor); break; // arriba arriba izquierda -> octabo

	case 4: glColor3f(redColor, greenColor, blueColor); break; // arriba arriba derecha -> PRIMERO

	case 5: glColor3f(redColor, greenColor, blueColor); break; // abajo medio derecha -> TERCERO

	case 6: glColor3f(redColor, greenColor, blueColor); break; //arriba medio derecha -> SEGUNDO

	case 7: glColor3f(redColor, greenColor, blueColor); break; // arriba medio izquierda -> septimo
	case 8: glColor3f(redColor, greenColor, blueColor); break; // abajo medio izquierda -> sexto
	default: break;
	}
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();

}


void pintaCirculoNormal(double a, double b, int Xo, int Yo) {

	double dx, dy;

	int r, y = 0;

	dx = (Xo - a);
	dy = (Yo - b);

	r = sqrt(pow(dx, 2) + pow(dy, 2));

	float x = 0, RC = 1, GC = 1, BC = 1;

	int cuentaPixel = 1;
		

	
	do {

		y = (sqrt(pow(r, 2) - pow(x, 2)));

		pintaPixel(x + a, y + b, 1, 0, GC, 0);
		glFlush();

		pintaPixel(-x + a, y + b, 2, 0, GC, BC);
		glFlush();

		pintaPixel(-x + a, -y + b, 3, RC, 0, BC);
		glFlush();

		pintaPixel(x + a, -y + b, 4, RC, 0, 0);
		glFlush();

		pintaPixel(y + a, x + b, 5, RC, GC, 0);
		glFlush();

		pintaPixel(y + a, -x + b, 6, RC, GC/2, 0);
		glFlush();

		pintaPixel(-y + a, -x + b, 7, RC/2, 0, BC/2);
		glFlush();

		pintaPixel(-y + a, x + b, 8, 0, 0, BC);
		glFlush();

		x++;

		cuentaPixel++;
		

	} while (x <= y);

	cout << cuentaPixel << endl;

}

void pintaCirculoDegradaOctante(double a, double b, int Xo, int Yo, int radioSize) {

	double dx, dy;

	int r, y = 0;

	dx = (Xo - a);
	dy = (Yo - b);

	r = sqrt(pow(dx, 2) + pow(dy, 2));

	float x = 0, RC = 1, GC = 1, BC = 1;

	float linearDecrease = 0.014;

	int cuentaPixel = 1;

	do {

		y = (sqrt(pow(r, 2) - pow(x, 2)));

		pintaPixel(x + a, y + b, 1, 0, GC, 0);
		glFlush();

		pintaPixel(-x + a, y + b, 2, 0, GC, BC);
		glFlush();

		pintaPixel(-x + a, -y + b, 3, RC, 0, BC);
		glFlush();

		pintaPixel(x + a, -y + b, 4, RC, 0, 0);
		glFlush();

		pintaPixel(y + a, x + b, 5, RC, GC, 0);
		glFlush();

		pintaPixel(y + a, -x + b, 6, RC, GC / 2, 0);
		glFlush();

		pintaPixel(-y + a, -x + b, 7, RC / 2, 0, BC / 2);
		glFlush();

		pintaPixel(-y + a, x + b, 8, 0, 0, BC);
		glFlush();

		x++;

		RC = RC - linearDecrease;
		GC = GC - linearDecrease;
		BC = BC - linearDecrease;


		cuentaPixel++;


	} while (x <= y);

	cout << cuentaPixel << endl;

}

void pintaCirculoDegradaCentro(double a, double b, int Xo, int Yo, float radioSize) {

	double dx, dy;

	int r, y = 0;

	dx = (Xo - a);
	dy = (Yo - b);

	r = sqrt(pow(dx, 2) + pow(dy, 2));

	float x = 0, RC = 1, GC = 1, BC = 1;

	RC = 0.0125 * radioSize;
	GC = 0.0125 * radioSize;
	BC = 0.0125 * radioSize;



	do {

		y = (sqrt(pow(r, 2) - pow(x, 2)));

		pintaPixel(x + a, y + b, 1, 0, GC, 0);
		glFlush();

		pintaPixel(-x + a, y + b, 2, 0, GC, BC);
		glFlush();

		pintaPixel(-x + a, -y + b, 3, RC, 0, BC);
		glFlush();

		pintaPixel(x + a, -y + b, 4, RC, 0, 0);
		glFlush();

		pintaPixel(y + a, x + b, 5, RC, GC, 0);
		glFlush();

		pintaPixel(y + a, -x + b, 6, RC, GC / 2, 0);
		glFlush();

		pintaPixel(-y + a, -x + b, 7, RC / 2, 0, BC / 2);
		glFlush();

		pintaPixel(-y + a, x + b, 8, 0, 0, BC);
		glFlush();

		x++;

	} while (x <= y);


}

void pintaCirculoDegradaRGB(double a, double b, int Xo, int Yo, int radioSize)	 {

	double dx, dy;

	int r, y = 0;

	dx = (Xo - a);
	dy = (Yo - b);

	r = sqrt(pow(dx, 2) + pow(dy, 2));

	float x = 0, RC = 1, GC = 1, BC = 1;

	float IncRED = 0, IncGREEN = 0, IncBLUE = 0;
	float DecRED = 1, DecGREEN = 1, DecBLUE = 1;
	 
	float cuentapixel = 1;

	do {
		y = (sqrt(pow(r, 2) - pow(x, 2)));
		x++;
		cuentapixel++;

	} while (x <= y);

	x = 0;

	cout << cuentapixel << endl;

	float linearDecrease = 1 / cuentapixel;

	cout << "linear decrease :";
	cout << linearDecrease;


	do {

		y = (sqrt(pow(r, 2) - pow(x, 2)));

		pintaPixel(x + a, -y + b, 4, RC, IncGREEN/2, 0);
		glFlush();

		pintaPixel(y + a, -x + b, 6, RC, DecGREEN , 0);
		glFlush();

		pintaPixel(y + a, x + b, 5, DecRED, GC, 0);
		glFlush();

		pintaPixel(x + a, y + b, 1, 0, GC, DecBLUE);
		glFlush();

		pintaPixel(-x + a, y + b, 2, 0, DecGREEN, BC);
		glFlush();

		pintaPixel(-y + a, x + b, 8, (DecRED/4)*3, 0, BC);
		glFlush();

		pintaPixel(-y + a, -x + b, 7, ((RC/4)*3)+IncRED, 0, BC);
		glFlush();

		pintaPixel(-x + a, -y + b, 3, RC, 0, IncBLUE);
		glFlush();

		x++;

		IncRED = IncRED + linearDecrease;
		DecRED = DecRED - linearDecrease;

		IncGREEN = IncGREEN + linearDecrease;
		DecGREEN = DecGREEN - linearDecrease;

		IncBLUE = IncBLUE + linearDecrease;
		DecBLUE = DecBLUE - linearDecrease;

	} while (x <= y);


}


void displayColors() {
	glClear(GL_COLOR_BUFFER_BIT);

	/*
	for (int i = 40; i > 0; i-=2) {

		Xo = ancho/4;
		Yo = alto/2;

		float Xf = Xo + i;
		float Yf = Yo + 0;
		pintaCirculoNormal(Xo, Yo, Xf, Yf);
		glFlush();
	}
	//*/

	/*
	for (int i = 80; i > 0; i -= 2) {

		Xo = (ancho/4)*2;
		Yo = alto/3;

		float Xf = Xo + i;
		float Yf = Yo + 0;
		pintaCirculoDegradaOctante(Xo, Yo, Xf, Yf, i);
		glFlush();
	}
	//*/

	/*
	for (int i = 80; i > 0; i -= 2) {

		Xo = (ancho / 4) * 2;
		Yo = (alto / 3) * 2;

		float Xf = Xo + i;
		float Yf = Yo + 0;
		pintaCirculoDegradaCentro(Xo, Yo, Xf, Yf,i);
		glFlush();
	}
	//*/

	//*
	for (int i = 140; i > 0; i -= 2) {

		Xo = (ancho / 4) * 3;
		Yo = alto / 2;

		float Xf = Xo + i;
		float Yf = Yo + 0;
		pintaCirculoDegradaRGB(Xo, Yo, Xf, Yf, i);
		glFlush();
	}
	//*/
}


//Funcion principal (main)
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(ancho, alto);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("ALGORITMO PARA MODELO DE COLOR");
	gluOrtho2D(0, ancho, alto, 0); //origen "vista- camara" en el centro de la pantalla (tamaño en global)
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(displayColors);
	glutMainLoop();
	return 0;
}
//ANDRÉS FELIPE DAZA MORENO - 1201956
// SANTIAGO RAMIREZ - 1202229

using namespace std;

#include <iostream>
#include "glut.h"
#include <math.h>


int xPantalla = 500, yPantalla = 400; //global cambio tamaño pantalla

const int tamPoligonoPuntos = 138;

int Poligono3X3[tamPoligonoPuntos][3] = { 
{101,127,1},{133,108,1},{133,108,1},{139,158,1},{139,158,1},{158,133,1}, //rojo
{158,133,1},{174,168,1},{174,168,1},{187,136,1},{187,136,1},{177,105,1},

{177,105,1},{158,133,1},{158,133,1,},{133,108,1},{133,108,1},{177,105,1,},//naranja
{177,105,1},{211,130,1},{211,130,1},{209,164,1},{209,164,1},{217,196,1},

{217,196,1},{177,240,1},{177,240,1},{197,196,1},{197,196,1},{217,196,1}, // amarillo
{217,196,1},{212,240,1},{212,240,1},{202,213,1},{202,213,1},{217,196,1},

{217,196,1},{199,174,1},{199,174,1},{209,164,1},{209,164,1},{187,136,1}, // Verde
{187,136,1},{199,174,1},{199,174,1},{197,196,1},{197,196,1},{174,168,1},

{174,168,1},{199,174,1},{199,174,1},{209,164,1},{209,164,1},{211,130,1}, // Azul
{211,130,1},{187,136,1},{187,136,1},{158,133,1},{158,133,1},{174,168,1},

{174,168,1},{139,158,1},{139,158,1},{113,168,1},{113,168,1},{90,239,1}, // AzulOscuro
{90,239,1},{94,183,1},{94,183,1},{113,168,1},{113,168,1},{81,145,1},

{81,145,1},{94,183,1},{ 94,183,1 },{90,239,1},{90,239,1},{81,145,1}, // Morado
{81,145,1},{101,127,1},{101,127,1},{113,168,1},{113,168,1},{139,158,1},

{139,158,1},{101,127,1},{101,127,1},{88,95,1},{88,95,1},{56,113,1}, // AzulClaro
{56,113,1},{62,69,1},{62,69,1},{36,85,1},{36,85,1},{77,2,1},

{77,2,1},{47,16,1},{47,16,1},{66,24,1},{66,24,1},{62,69,1}, // Lima
{62,69,1},{53,51,1},{53,51,1},{3,69,1},{3,69,1},{36,85,1},

{36,85,1},{5,79,1},{5,79,1},{3,69,1},{3,69,1},{51,39,1}, // Amarillo oscuro
{51,39,1},{47,16,1},{47,16,1},{53,51,1},{53,51,1},{62,69,1},

{62,69,1},{36,85,1},{36,85,1},{56,113,1},{56,113,1},{81,145,1}, // Rosado
{81,145,1},{101,127,1},{101,127,1},{56,113,1},{56,113,1},{62,69,1},

{62,69,1},{88,95,1},{88,95,1},{133,108,1},{133,108,1},{101,127,1}, // Café
};


double aux1[tamPoligonoPuntos][3], aux2[tamPoligonoPuntos][3];

void pintaLinea(float xi, float yi, float xf, float yf)
{
	glBegin(GL_LINES);
	glVertex2d(xi, yi);
	glVertex2d(xf, yf);
	glColor3f(1, 1, 1);
	glEnd();
	glFlush();
}

void dibujaPoligono() {
	for (int i = 0; i < tamPoligonoPuntos; i++)
	{
		pintaLinea(aux1[i][0], aux1[i][1], aux1[i + 1][0], aux1[i + 1][1]);
	}
	glFlush();
}

void obtenerMatrices()
{
	for (int i = 0; i < tamPoligonoPuntos; i++)
	{
		aux1[i][0] = Poligono3X3[i][0];
		aux1[i][1] = Poligono3X3[i][1];
		aux1[i][2] = Poligono3X3[i][2];

		aux2[i][0] = Poligono3X3[i][0];
		aux2[i][1] = Poligono3X3[i][1];
		aux2[i][2] = Poligono3X3[i][2];
	}
}

void pintaPOLIGONO() {

	glClear(GL_COLOR_BUFFER_BIT);
	obtenerMatrices();
	dibujaPoligono();

	glFlush();
}

int main(int argc, char* argv[]) {


	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(xPantalla, yPantalla);
	glutInitWindowPosition(10, 200);
	glutCreateWindow("FIGURA POLIGONOS");
	gluOrtho2D(0, xPantalla / 2, yPantalla / 2, 0);
	glutDisplayFunc(pintaPOLIGONO);

	glutMainLoop();
	return 0;
}
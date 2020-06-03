#include "glut.h"

void dibujar() {

	glFlush(); // limpia la pantalla, el buffer

}


int main(int argc, char * args[]) {

	glutInit(&argc, args); // inicializa glut

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // inicializa un display del modo indicado, como estamos empezando se usa el glut_rgb con un buffer sencillo

	glutInitWindowSize(800, 600); // Inicia la ventana, en este caso con el tamaño especificado

	glutInitWindowPosition(50, 50); //posicion en la que se inicializa la ventana

	glutCreateWindow("primera base para usar glut y openGL"); // crea ventana con el nombre indicado

	glutDisplayFunc(dibujar); // funcion que va a usar glut para dibujar

	glutMainLoop(); //genera un loop que escuchará constantemente las funciones de dibujado y etc.

	return 0;

}
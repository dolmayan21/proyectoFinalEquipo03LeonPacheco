/*
	LABORATORIO DE COMPUTACÓN GRÁFICA

		PROYECTO FINAL 
			
			> PARQUE DE DIVERSIONES <

			PACHECO FRANCO JESÚS ENRIQUE
			LEÓN DEL VILLAR RUBÉN ALEJANDRO

			GRUPO: 02
			SEMESTRE: 2018-2

			VISUAL STUDIO 2017
*/

// BIBLIOTECAS

//#include <GL/glut.h>
//#include <stdlib.h>

#include "Main.h"
#include "renders.h"
#include "texture.h"

/* VARIABLES GLOBALES */

float rotX = 0.0f, rotY = 0.0f;

Render renders;

/* TEXTURAS */

CTexture wood;

void InitGL (GLvoid) {
	 glClearDepth(1.0f);		// Activamos el valor de inicio del buffer de profundidad
	 glEnable(GL_DEPTH_TEST);	// Hacemos la prueba de profundidad
	 glDepthFunc(GL_LEQUAL);	// Tipo de prueba de profundidad a hacer

	 /* TEXTURAS */

	 wood.LoadTGA("texturas/wood.tga");
	 wood.BuildGLTexture();
	 wood.ReleaseImage();

	 // glEnable(GL_TEXTURE_2D);

	 return;
}

void reshape(int width, int height) {
	 if (!height)
		return;
	 glViewport(0, 0,  (GLsizei)width, (GLsizei)height);
	 glMatrixMode(GL_PROJECTION); // Activamos la matriz de proyeccion. 
	 glLoadIdentity();// "limpiamos" esta con la matriz identidad.

	 gluPerspective(45, (GLfloat)width / (GLfloat)height, 0.01, 100.0);

	 glMatrixMode(GL_MODELVIEW); // Activamos la matriz de modelado/visionado. 
	 glLoadIdentity();  // "Limpiamos" la matriz
	 return;
}

void display(void) { 
	 
	// "Limpiamos" el frame buffer con el color de "Clear", en este caso negro. 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();

	////////// AREA DE DIBUJO //////////////////////////////////////////////////////////////////////////////////////

	glTranslatef(0.0, 0.0, -20.0); // Trasladamos en Z para que se vea todo lo que viene.

	// EJES DE REFERENCIA

	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(1000.0f, 0.0f, 0.0f);
		glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 1000.0f, 0.0f);
		glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 1000.0f);		 
	glEnd();

	// FIN EJES DE REFERENCIA

	glColor3f(1.0, 1.0, 1.0);
	//glutWireSphere(1.0f, 30, 30);
	
	glRotatef(rotX, 1.0, 0.0, 0.0);
	glRotatef(rotY, 0.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);
	renders.cube(10.0, 10.0, 10.0, wood.GLindex, wood.GLindex, wood.GLindex, wood.GLindex, wood.GLindex, wood.GLindex);
	glDisable(GL_TEXTURE_2D);

	glFlush();
	glutSwapBuffers ( );
	return;
} 

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27: exit(0);
		break;

		case 'x':
		break;
	}
	glutPostRedisplay();
	return;
}  

void specialKeys(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_UP:
			rotX += 2.0f;
			break;
		case GLUT_KEY_DOWN:
			rotX -= 2.0f;
			break;
		case GLUT_KEY_LEFT:
			rotY += 2.0f;
			break;
		case GLUT_KEY_RIGHT:
			rotY -= 2.0f;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) { 
	glutInit(&argc, argv); // Se inicializa openGL

	// Se activa el buffer simple y colores tipo RGB. (GLUT_SINGLE -> GLUT_DOUBLE ?)
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH); 

	glutInitWindowSize (1200, 720); // Se define el tamaño de la ventana.
	glutInitWindowPosition (0, 0); // Se posiciona la ventana en la esquina superior izquierda.
	glutCreateWindow ("Parque de Diversiones"); // Se crea la ventana con su respectivo nombre.

	InitGL(); // Inicializacion del sistema.

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	 
	return 0; // ANSI C requiere que main retorne un valor entero.
}




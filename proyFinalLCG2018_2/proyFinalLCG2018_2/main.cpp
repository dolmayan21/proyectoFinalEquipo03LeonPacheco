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

/*
	TECLAS

		w/w: Mover camara adelante.
		s/S: Mover camara atras.
		a/A: Mover camara izquierda.
		d/D: Mover camara derecha.
		q/Q: Mover camara arriba.
		e/E: Mover camara abajo.
		<: Rotar camara izquierda.
		>: Rotar camara derecha.
		^: Rotar camara arriba.
		v: Rotar camara abajo.

*/

// BIBLIOTECAS

//#include <GL/glut.h>
//#include <stdlib.h>

#include "Main.h"
#include "texture.h"
#include "Camera.h"
#include "figuras.h"

#include "renders.h"


/* VARIABLES GLOBALES */

float movX = 0.0f, movY = 0.0f, movZ = 0.0f;
float sideSkyBox = 0.0f;

/* RENDERS */

Render renders;

Superman superman;

//CFiguras figuras;

/* TEXTURAS */

CTexture none;
CTexture wood;
CTexture skyBox;
CTexture tabiqueMarron;
CTexture entradaTabiqueMarron;
CTexture grass;
CTexture asfalto;
CTexture taquilla;

/* CAMARA */

CCamera camera;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 


void InitGL (GLvoid) {

	 glClearDepth(1.0f);		// Activamos el valor de inicio del buffer de profundidad
	 glEnable(GL_DEPTH_TEST);	// Hacemos la prueba de profundidad
	 glDepthFunc(GL_LEQUAL);	// Tipo de prueba de profundidad a hacer

	 /* TEXTURAS */

	 none.LoadTGA("texturas/none.tga");
	 none.BuildGLTexture();
	 none.ReleaseImage();
	 
	 wood.LoadTGA("texturas/wood.tga");
	 wood.BuildGLTexture();
	 wood.ReleaseImage();

	 skyBox.LoadTGA("texturas/skyBox.tga");
	 skyBox.BuildGLTexture();
	 skyBox.ReleaseImage();

	 tabiqueMarron.LoadTGA("texturas/tabiqueMarron.tga");
	 tabiqueMarron.BuildGLTexture();
	 tabiqueMarron.ReleaseImage();

	 entradaTabiqueMarron.LoadTGA("texturas/entradaTabiqueMarron.tga");
	 entradaTabiqueMarron.BuildGLTexture();
	 entradaTabiqueMarron.ReleaseImage();

	 grass.LoadTGA("texturas/grass.tga");
	 grass.BuildGLTexture();
	 grass.ReleaseImage();

	 asfalto.LoadTGA("texturas/asfalto.tga");
	 asfalto.BuildGLTexture();
	 asfalto.ReleaseImage();

	 taquilla.LoadTGA("texturas/taquilla.tga");
	 taquilla.BuildGLTexture();
	 taquilla.ReleaseImage();

	 /* CAMARA */

	camera.Position_Camera(0.0f, 2.5f, 3.0f, 0.0f, 2.5f, 0.0f, 0.0f, 1.0f, 0.0f);

	 //camera.Position_Camera(0.0f, 8.5f, 0.0f, 0.0f, -1.0f, 0.3f, 0.0f, 1.0f, 0.0f);

	 // glEnable(GL_TEXTURE_2D);

	 return;
}

void reshape(int width, int height) {
	 if (!height)
		return;
	 glViewport(0, 0,  (GLsizei)width, (GLsizei)height);
	 glMatrixMode(GL_PROJECTION); // Activamos la matriz de proyeccion. 
	 glLoadIdentity();// "limpiamos" esta con la matriz identidad.

	 gluPerspective(45, (GLfloat)width / (GLfloat)height, 0.01, 1000.0);

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

	// CAMARA //

	glRotatef(g_lookupdown, 1.0f, 0.0f, 0.0f); // Mover camara arriba/abajo

	gluLookAt(camera.mPos.x, camera.mPos.y, camera.mPos.z,
				camera.mView.x, camera.mView.y, camera.mView.z,
				camera.mUp.x, camera.mUp.y, camera.mUp.z);

	glTranslatef(0.0 + movX, 0.0 + movY, -20.0 + movZ); // Trasladamos en Z para que se vea todo lo que viene.

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

	glEnable(GL_TEXTURE_2D);
	
	//// SKYBOX ///

	renders.skyBox(120.0, 100.0, 100.0, skyBox.GLindex, grass.GLindex, skyBox.GLindex, sideSkyBox);

	

	glPushMatrix(); // Entrada
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);

		glTranslatef(0.0f, -48.0f, 28.5f);
		renders.cube(5.0, 4.0, 3.0,
						tabiqueMarron.GLindex, none.GLindex, tabiqueMarron.GLindex,
						tabiqueMarron.GLindex, entradaTabiqueMarron.GLindex, entradaTabiqueMarron.GLindex);

		glDisable(GL_ALPHA_TEST);
	glPopMatrix(); // Fin Entrada

	/* TAQUILLAS */

	glPushMatrix();
		glTranslatef(3.5f,-49.0f, 28.5f);
			renders.cube(2.0f, 2.0f, 3.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex,tabiqueMarron.GLindex,
							tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
		glTranslatef(-7.0f, 0.0f, 0.0f);
			renders.cube(2.0f, 2.0f, 3.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex, tabiqueMarron.GLindex,
							tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
	glPopMatrix();

	/* FIN TAQUILLAS */

	/* MONTAÑA RUSA - SUPERMAN */

	glPushMatrix();
		glTranslatef(10.0, -46.0, -10.0);

		superman.carril(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		
		superman.carril(9.0, 0.5, 0.0, 0.0, 45.0, 1.0, 1.0);
		superman.carril(10.0, 1.5, 0.0, 0.0, 45.0, 1.0, 1.0);
		superman.carril(11.0, 2.5, 0.0, 0.0, 45.0, 1.0, 1.0);
		superman.carril(12.0, 3.5, 0.0, 0.0, 45.0, 1.0, 1.0);
		superman.carril(13.0, 4.5, 0.0, 0.0, 45.0, 1.0, 1.0);
		superman.carril(14.0, 5.5, 0.0, 0.0, 45.0, 1.0, 1.0);
		superman.carril(15.0, 6.5, 0.0, 0.0, 45.0, 1.0, 1.0);

		superman.carril(16.0, 7.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(17.0, 7.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(18.0, 7.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(19.0, 7.0, 0.0, 0.0, 0.0, 1.0, 1.0);
		superman.carril(20.0, 7.0, 0.0, 0.0, 0.0, 1.0, 1.0);

	glPopMatrix();

	/* FIN - MONTAÑA RUSA - SUPERMAN */

	glDisable(GL_TEXTURE_2D);
	
	

	glFlush();
	glutSwapBuffers ( );
	return;
} 

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27: exit(0);
			break;
		case 'w':   //Movimientos de camara
		case 'W':
			camera.Move_Camera(CAMERASPEED + 0.2);
			break;

		case 's':
		case 'S':
			camera.Move_Camera(-(CAMERASPEED + 0.2));
			break;

		case 'a':
		case 'A':
			camera.Strafe_Camera(-(CAMERASPEED + 0.4));
			break;

		case 'd':
		case 'D':
			camera.Strafe_Camera(CAMERASPEED + 0.4);
			break;

		case 'q':
		case 'Q':
			camera.UpDown_Camera(CAMERASPEED + 0.02);
			break;

		case 'e':
		case 'E':
			camera.UpDown_Camera(-(CAMERASPEED + 0.02));
			break;

		case 'x':
			movX += 1.0;
			break;
		case 'y':
			movY += 1.0;
			break;
		case 'z':
			movZ += 1.0;
			break;
		case 'X':
			movX -= 1.0;
			break;
		case 'Y':
			movY -= 1.0;
			break;
		case 'Z':
			movZ -= 1.0;
			break;
	}

	glutPostRedisplay();
	return;

}  

void specialKeys(int key, int x, int y) {

	switch(key) {
		case GLUT_KEY_PAGE_UP:
			camera.UpDown_Camera(CAMERASPEED);
			break;

		case GLUT_KEY_PAGE_DOWN:
			camera.UpDown_Camera(-CAMERASPEED);
			break;

		case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
			g_lookupdown -= 1.0f;
			break;

		case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
			g_lookupdown += 1.0f;
			break;

		case GLUT_KEY_LEFT:
			camera.Rotate_View(-CAMERASPEED);
			break;

		case GLUT_KEY_RIGHT:
			camera.Rotate_View(CAMERASPEED);
			break;

		default:
			break;
	}

	glutPostRedisplay();

}

void animation() {

	/* ANIMACION SKYBOX --> MOVIMIENTO DEL CIELO */

	if (sideSkyBox >= 1.0)
		sideSkyBox = 0.0;
	else
		sideSkyBox += 0.00001;

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

	glutDisplayFunc		( display ); 
	glutReshapeFunc		( reshape );
	glutKeyboardFunc	( keyboard );
	glutSpecialFunc		( specialKeys );
	glutIdleFunc		( animation );
	glutMainLoop();
	 
	return 0; // ANSI C requiere que main retorne un valor entero.
}




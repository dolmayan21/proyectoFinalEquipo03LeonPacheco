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

#include "cmodel/CModel.h"

/* VARIABLES GLOBALES */

float movX = 0.0f, movY = 0.0f, movZ = 0.0f;
float sideSkyBox = 0.0f;

/* RENDERS */

Render renders;

Superman superman;

CFiguras figura;

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

/* MODELOS 3DS */

CModel carro;

/* CAMARA */

CCamera camera;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

void renderSuperman() {

	/* MONTAÑA RUSA - SUPERMAN */

	glPushMatrix();
	//glTranslatef(10.0, -28.0, 10.0);

	glTranslatef(25.0, -26.0, 10.0);

	//glScalef(0.50, 0.50, 0.50);

	superman.carrilConexion(1.0, 0.0, 0.0, 0.0, 1);

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

	superman.carril(21.0, 6.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(22.0, 5.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(23.0, 4.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(24.0, 3.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(25.0, 2.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(26.0, 1.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(27.0, 0.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(28.0, -0.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(29.0, -1.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(30.0, -2.5, 0.0, 0.0, -45.0, 1.0, 1.0);
	superman.carril(31.0, -3.5, 0.0, 0.0, -45.0, 1.0, 1.0);

	superman.carril(32.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	superman.carril(33.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	superman.carril(34.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	superman.carril(35.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	superman.carril(36.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	superman.carril(37.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	superman.carril(38.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	superman.carril(39.0, -4.0, 0.0, 0.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(41.0, -4.0, 0.0, 0.0, 0); // Centro de la primera vuelta

	glPushMatrix();

	glTranslatef(41.75, -4.0, -0.75); // Centro de la esquina vetical primera vuelta

	superman.carrilConexion(0.0, 0.0, 0.0, 90.0, 1);

	superman.carril(0.0, 0.0, -2.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -3.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -4.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -5.0, 90.0, 0.0, 1.0, 1.0);

	superman.carril(0.0, 0.5, -6.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 1.5, -7.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 2.5, -8.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 3.5, -9.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 4.5, -10.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 5.5, -11.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 6.5, -12.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 7.5, -13.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 8.5, -14.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 9.5, -15.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 10.5, -16.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 11.5, -17.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 12.5, -18.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 13.5, -19.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 14.5, -20.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 15.5, -21.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 16.5, -22.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 17.5, -23.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 18.5, -24.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 19.5, -25.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 20.5, -26.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 21.5, -27.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 22.5, -28.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 23.5, -29.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 24.5, -30.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 25.5, -31.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 26.5, -32.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 27.5, -33.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 28.5, -34.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 29.5, -35.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 30.5, -36.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 31.5, -37.0, 90.0, 45.0, 1.0, 1.0);

	superman.carril(0.0, 32.0, -38.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 32.0, -39.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 32.0, -40.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 32.0, -41.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 32.0, -42.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 32.0, -43.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 32.0, -44.0, 90.0, 0.0, 1.0, 1.0);

	superman.carril(0.0, 31.5, -45.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 30.5, -46.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 29.5, -47.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 28.5, -48.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 27.5, -49.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 26.5, -50.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 25.5, -51.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 24.5, -52.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 23.5, -53.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 22.5, -54.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 21.5, -55.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 20.5, -56.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 19.5, -57.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 18.5, -58.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 17.5, -59.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 16.5, -60.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 15.5, -61.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 14.5, -62.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 13.5, -63.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 12.5, -64.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 11.5, -65.0, 90.0, -45.0, 1.0, 1.0);
	superman.carril(0.0, 10.5, -66.0, 90.0, -45.0, 1.0, 1.0);

	superman.carril(0.0, 10.0, -67.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 10.0, -68.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 10.0, -69.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 10.0, -70.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 10.0, -71.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 10.0, -72.0, 90.0, 0.0, 1.0, 1.0);

	superman.carril(0.0, 10.5, -73.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 11.5, -74.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 12.5, -75.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 13.5, -76.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 14.5, -77.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(0.0, 15.5, -78.0, 90.0, 45.0, 1.0, 1.0);

	superman.carril(0.0, 16.0, -79.0, 90.0, 0.0, 1.0, 1.0);

	// SEGUNDA CONEXION

	superman.carrilConexion(0.0, 16.0, -81.0, -90.0, 1);
	superman.carrilConexion(0.75, 16.0, -81.75, 180.0, 0); // Centro figura 

	superman.carril(2.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(3.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(4.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(5.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(6.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(7.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(8.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(9.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(10.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(11.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(12.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(13.75, 16.0, -81.75, 0.0, 0.0, 1.0, 1.0);

	// TERCERA CONEXION

	superman.carrilConexion(15.75, 16.0, -81.75, 0.0, 0);
	superman.carrilConexion(16.5, 16.0, -82.5, 90.0, 1);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(58.25, 12.0, -83.25); // Centro de la conexion || a Z

	superman.carril(0.0, 0.0, -2.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -3.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -4.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -5.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -6.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -7.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -8.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -9.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -10.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -11.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -12.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -13.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -14.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -15.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -16.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(0.0, 0.0, -17.0, 90.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(0.0, 0.0, -19.0, -90.0, 0);
	superman.carrilConexion(-0.75, 0.0, -19.75, 180.0, 1);

	superman.carril(-2.75, 0.0, -19.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-3.75, 0.0, -19.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-4.75, 0.0, -19.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-5.75, 0.0, -19.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-6.75, 0.0, -19.75, 0.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(-8.75, 0.0, -19.75, 180.0, 0);
	superman.carrilConexion(-9.5, 0.0, -19.0, -90.0, 1);

	superman.carril(-9.5, 0.0, -17.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, 0.0, -16.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, 0.0, -15.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, 0.0, -14.0, 90.0, 0.0, 1.0, 1.0);

	superman.carril(-9.5, -0.5, -13.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-9.5, -1.5, -12.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-9.5, -2.5, -11.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-9.5, -3.5, -10.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-9.5, -4.5, -9.0, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-9.5, -5.5, -8.0, 90.0, 45.0, 1.0, 1.0);

	superman.carril(-9.5, -6.0, -7.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, -6.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, -5.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, -4.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, -3.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, -2.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, -1.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 0.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 1.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 2.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 3.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 4.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 5.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 6.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 7.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 8.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 9.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 10.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 11.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 12.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 13.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 14.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 15.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 16.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 17.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 18.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 19.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 20.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 21.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 22.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 23.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 24.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 25.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 26.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 27.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 28.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 29.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 30.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 31.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 32.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 33.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 34.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 35.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 36.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 37.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 38.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 39.0, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-9.5, -6.0, 40.0, 90.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(-9.5, -6.0, 42.0, 90.0, 0);
	superman.carrilConexion(-8.75, -6.0, 42.75, 0.0, 1);

	superman.carril(-6.75, -6.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-5.75, -6.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-4.75, -6.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-3.75, -6.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-2.75, -6.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-1.75, -6.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-0.75, -6.0, 42.75, 0.0, 0.0, 1.0, 1.0);

	superman.carril(0.25, -5.5, 42.75, 0.0, 45.0, 1.0, 1.0);
	superman.carril(1.25, -4.5, 42.75, 0.0, 45.0, 1.0, 1.0);
	superman.carril(2.25, -3.5, 42.75, 0.0, 45.0, 1.0, 1.0);
	superman.carril(3.25, -2.5, 42.75, 0.0, 45.0, 1.0, 1.0);
	superman.carril(4.25, -1.5, 42.75, 0.0, 45.0, 1.0, 1.0);
	superman.carril(5.25, -0.5, 42.75, 0.0, 45.0, 1.0, 1.0);
	superman.carril(6.25, 0.5, 42.75, 0.0, 45.0, 1.0, 1.0);

	superman.carril(7.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(8.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(9.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(10.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(11.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(12.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(13.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(14.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(15.25, 1.0, 42.75, 0.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(17.25, 1.0, 42.75, 180.0, 1);
	superman.carrilConexion(18.0, 1.0, 43.5, -90.0, 0);

	superman.carril(18.0, 1.0, 45.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 46.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 47.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 48.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 49.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 50.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 51.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 52.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 53.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 54.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 55.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 56.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 57.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 58.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 59.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 60.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 61.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 62.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 63.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 64.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, 1.0, 65.5, 90.0, 0.0, 1.0, 1.0);

	superman.carril(18.0, 0.5, 66.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -0.5, 67.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -1.5, 68.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -2.5, 69.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -3.5, 70.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -4.5, 71.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -5.5, 72.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -6.5, 73.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -7.5, 74.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -8.5, 75.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -9.5, 76.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -10.5, 77.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(18.0, -11.5, 78.5, 90.0, 45.0, 1.0, 1.0);

	superman.carril(18.0, -12.0, 79.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 80.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 81.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 82.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 83.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 84.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 85.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 86.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 87.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(18.0, -12.0, 88.5, 90.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(18.0, -12.0, 90.5, 90.0, 1);
	superman.carrilConexion(17.25, -12.0, 91.25, 0.0, 0);

	superman.carril(15.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(14.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(13.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(12.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(11.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(10.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(9.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(8.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(7.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(6.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(5.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(4.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(3.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(2.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(1.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(0.25, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-0.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-1.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-2.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-3.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-4.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-5.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-6.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-7.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-8.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-9.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-10.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-11.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-12.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-13.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-14.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-15.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-16.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-17.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-18.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-19.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-20.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-21.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-22.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-23.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-24.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-25.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-26.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-27.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-28.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-29.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-30.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-31.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-32.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-33.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-34.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-35.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-36.75, -12.0, 91.25, 0.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(-38.75, -12.0, 91.25, 0.0, 1);
	superman.carrilConexion(-39.5, -12.0, 90.5, 90.0, 0);

	superman.carril(-39.5, -12.0, 88.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 87.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 86.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 85.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 84.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 83.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 82.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 81.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 80.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 79.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 78.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 77.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 76.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 75.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 74.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 73.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 72.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 71.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 70.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 69.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 68.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 67.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 66.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 65.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 64.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 63.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 62.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 61.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 60.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 59.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 58.5, 90.0, 0.0, 1.0, 1.0);

	superman.carril(-39.5, -11.5, 57.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -10.5, 56.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -9.5, 55.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -8.5, 54.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -7.5, 53.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -6.5, 52.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -5.5, 51.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -4.5, 50.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -3.5, 49.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -2.5, 48.5, 90.0, 45.0, 1.0, 1.0);
	superman.carril(-39.5, -1.5, 47.5, 90.0, 45.0, 1.0, 1.0);

	superman.carril(-39.5, -1.0, 46.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -1.0, 45.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -1.0, 44.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -1.0, 43.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -1.0, 42.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -1.0, 41.5, 90.0, 0.0, 1.0, 1.0);

	superman.carril(-39.5, -1.5, 40.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -2.5, 39.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -3.5, 38.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -4.5, 37.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -5.5, 36.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -6.5, 35.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -7.5, 34.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -8.5, 33.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -9.5, 32.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -10.5, 31.5, 90.0, -45.0, 1.0, 1.0);
	superman.carril(-39.5, -11.5, 30.5, 90.0, -45.0, 1.0, 1.0);

	superman.carril(-39.5, -12.0, 29.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 28.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 27.5, 90.0, 0.0, 1.0, 1.0);
	superman.carril(-39.5, -12.0, 26.5, 90.0, 0.0, 1.0, 1.0);

	superman.carrilConexion(-39.5, -12.0, 24.5, -90.0, 0);
	superman.carrilConexion(-40.25, -12.0, 23.75, 180.0, 1);

	superman.carril(-42.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-43.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-44.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-45.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-46.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-47.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-48.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-49.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-50.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-51.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-52.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-53.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-54.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);
	superman.carril(-55.25, -12.0, 23.75, 0.0, 0.0, 1.0, 1.0);


	superman.carrilConexion(-57.25, -12.0, 23.75, 180.0, 0);
	superman.carrilConexion(-58.0, -12.0, 24.5, -90.0, 1);

	superman.carril(-58.0, -12.0, 26.5, 90.0, 0.0, 1.0, 1.0);

	for (int i = 1; i <= 54; i++) {
		superman.carril(-58.0, -12.0, 26.5 + i, 90.0, 0.0, 1.0, 1.0);
	}

	superman.carrilConexion(-58.0, -12.0, 82.5, 90.0, 0);

	glPopMatrix();

	glPopMatrix();

	/* FIN - MONTAÑA RUSA - SUPERMAN */
}

void InitGL (GLvoid) {

	 glClearDepth(1.0f);								// Configuramos Depth Buffer
	 glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	 glDepthFunc(GL_LEQUAL);							// Tipo de Depth Testing a realizar
	 glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	 glEnable(GL_AUTO_NORMAL);
	 glEnable(GL_NORMALIZE);

	 glEnable(GL_TEXTURE_2D);

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

	 /* CARGAS DE MODELOS 3DS*/

	 carro._3dsLoad("3ds/kitt.3ds");

	 /* FIN CARGA MODELOS 3DS */

	 /* CAMARA */

	camera.Position_Camera(0.0f, 2.5f, 3.0f, 0.0f, 2.5f, 0.0f, 0.0f, 1.0f, 0.0f);

	 //camera.Position_Camera(0.0f, 1.5f, 3.0f, 0.0f, -1.0f, 0.3f, 0.0f, 1.0f, 0.0f);

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

	renders.skyBox(240.0, 60.0, 200.0, skyBox.GLindex, grass.GLindex, skyBox.GLindex, sideSkyBox);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////// PON AQUI TU CODIGO ENTRE UN PUSH Y POP MATRIX /////////////////////////////////////
	//////////////// LO QUE PONGAS AQUI SE PONDRA EN EL CENTRO DE EL SKYBOX YA DE AHI LO TRASLADAS A
	///////////////// DONDE TU QUIERAS /////////////////////////////////////////////////////////////////

	// ejemplo //

	glDisable(GL_COLOR_MATERIAL);

	glPushMatrix();
		glScalef(0.2, 0.2, 0.2);
		carro.GLrender(NULL, _SHADED, 1);
	glPopMatrix();

	
	glEnable(GL_COLOR_MATERIAL);
	//superman.soporte(25.25, -30.0, 10.0, 1.0); // Punto Central montaña rusa

	//superman.soporte(0.0, 0.0, 0.0, 1.0); // Punto Central montaña rusa

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////
	////////////////

	glPushMatrix(); // Entrada
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);

		glTranslatef(0.0f, -28.0f, 28.5f);
		renders.cube(5.0, 4.0, 3.0,
						tabiqueMarron.GLindex, none.GLindex, tabiqueMarron.GLindex,
						tabiqueMarron.GLindex, entradaTabiqueMarron.GLindex, entradaTabiqueMarron.GLindex);

		glDisable(GL_ALPHA_TEST);
	glPopMatrix(); // Fin Entrada

	/* TAQUILLAS */

	glPushMatrix();
		glTranslatef(3.5f,-29.0f, 28.5f);
			renders.cube(2.0f, 2.0f, 3.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex,tabiqueMarron.GLindex,
							tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
		glTranslatef(-7.0f, 0.0f, 0.0f);
			renders.cube(2.0f, 2.0f, 3.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex, tabiqueMarron.GLindex,
							tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
	glPopMatrix();

	/* FIN TAQUILLAS */

	/* MONTAÑA RUSA - SUPERMAN */

	renderSuperman();

	/* FIN - MONTAÑA RUSA - SUPERMAN */

	/* ESFERA PRUEBA */

	/*glPushMatrix();
		glTranslatef(15.5, -28.0, 5.0);
		glutSolidSphere(0.1, 20, 20);
	glPopMatrix();*/

	/* FIN ESFERA PRUEBA */

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
		sideSkyBox += 0.00005;

	glutPostRedisplay();
}

void audio() {
	PlaySound("feria.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

}

int main(int argc, char **argv) { 
	glutInit(&argc, argv); // Se inicializa openGL


	audio();
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




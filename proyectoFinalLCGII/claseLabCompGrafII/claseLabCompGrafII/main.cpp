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

#include "Main.h"

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "renders.h"
#include "animaciones.h"
#include "cmodel/CModel.h"

////Solo para Visual Studio 2015
//#if (_MSC_VER == 1900)
//#   pragma comment( lib, "legacy_stdio_definitions.lib" )
//#endif

/* VARIABLES GLOBALES */

	float movX = 0.0f, movY = 0.0f, movZ = 0.0f;
	float sideSkyBox = 0.0f;

	GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis

/* FIN VARIABLES GLOBALES */

/* OBJETOS DE CLASES */

	Render renders;
	Superman superman;
	CFiguras figura;
	CFiguras fig1;
	CFiguras fig2;
	CCamera camera;
	AnimacionSuperman animSuperman;

/* FIN OBJETOS DE CLASES */

/* INICIO LUZ */

	GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
	GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
	GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
	GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

/* FIN LUZ */

/* INICIO MATERIALES */

	GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
	GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
	GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
	GLfloat m_s1[] = {18};

/* FIN MATERIALES */

/* INICIO TEXTURAS */

	CTexture none;
	CTexture wood;
	CTexture skyBox;
	CTexture skyBoxSide;
	CTexture tabiqueMarron;
	CTexture entradaTabiqueMarron;
	CTexture grass;
	CTexture asfalto;
	CTexture taquilla;

/* FIN TEXTURAS */

/* MODELOS */

	CModel kit;
	CModel oldhouse;

	CModel banca;
	CModel tree1;
	CModel barda;
	CModel castle;
	CModel trees;
	CModel ent;
	CModel avion;



/* FIN MODELOS */

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
void renderSupermanSoportes() {

	glPushMatrix();
					
		superman.soporte(25.25, -30.0, 10.0, 4.0, 1.0, 1.5, 1.5);
		superman.soporte(33.0, -30.0, 10.0, 4.0, 1.0, 1.0, 1.5);
		superman.soporte(41.0, -30.0, 10.0, 11.0, 1.0, 1.0, 1.5);
		superman.soporte(66.75, -30.0, -31.75, 16.0, 2.0, 1.5, 7.0);
		superman.soporte(66.75, -30.0, -60.25, 10.0, 1.0, 1.5, 6.0);
		superman.soporte(66.75, -30.0, -72.5, 16.0, 1.0, 1.5, 1.5);
		superman.soporte(83.25, -30.0, -72.5, 16.0, 1.0, 1.5, 1.5);
		superman.soporte(83.25, -30.0, -93.0, 16.0, 1.0, 1.5, 1.5);
		superman.soporte(73.75, -30.0, -93.0, 16.0, 1.0, 1.5, 1.5);
		superman.soporte(73.75, -30.0, -87.25, 16.0, 1.0, 1.5, 1.0);
		superman.soporte(73.75, -30.0, -80.25, 10.0, 1.0, 1.5, 1.0);
		superman.soporte(73.75, -30.0, -30.5, 10.0, 1.0, 1.5, 1.5);
		superman.soporte(82.5, -30.0, -30.5, 10.0, 1.0, 1.0, 1.5);
		superman.soporte(90.5, -30.0, -30.5, 17.0, 1.0, 1.0, 1.5);
		superman.soporte(101.25, -30.0, -30.5, 17.0, 1.0, 1.5, 1.5);
		superman.soporte(101.25, -30.0, -7.75, 17.0, 1.0, 1.5, 1.0);
		superman.soporte(101.25, -30.0, 6.25, 4.0, 1.0, 1.5, 1.0);
		superman.soporte(101.25, -30.0, 18.0, 4.0, 1.0, 1.5, 1.5);

		for (int i = 0; i < 54; i = i + 3)
			superman.soporte(97.5 - i, -30.0, 18.0, 4.0, 1.0, 1.0, 1.5);

		superman.soporte(43.75, -30.0, 18.0, 4.0, 1.0, 1.5, 1.5);
		superman.soporte(43.75, -30.0, -14.75, 4.0, 1.0, 1.5, 1.0);
		superman.soporte(43.75, -30.0, -29.25, 15.0, 1.0, 1.5, 6.0);
		superman.soporte(43.75, -30.0, -43.75, 4.0, 1.0, 1.5, 1.0);
		superman.soporte(43.75, -30.0, -49.5, 4.0, 1.0, 1.5, 1.5);
		superman.soporte(25.25, -30.0, -49.5, 4.0, 1.0, 1.5, 1.5);

		for(int i = 0; i < 57; i = i + 3)
			superman.soporte(25.25, -30.0, -45.75 + i, 4.0, 1.0, 1.5, 1.0);

	glPopMatrix();
}
void renderPuntosCarriles() {

	glPushMatrix();
		glTranslatef(25.25,-26.0,10.0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(33.0, -26.0, 10.0);
		glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(41.0, -19.0, 10.0);
		glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(45.0, -19.0, 10.0);
		glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(57.0, -30.0, 10.0);
		glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75,-30.0,10.0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75, -30.0, 4.25);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75, 2.0, -28.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75, 2.0, -34.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75, -20.0, -57.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75, -20.0, -62.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75, -14.0, -69.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(66.75, -14.0, -72.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(83.25, -14.0, -72.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(83.25, -14.0, -93.0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(73.75, -14.0, -93.0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(73.75, -14.0, -87.25);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(73.75, -20.0, -80.25);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(73.75, -20.0, -30.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(82.5, -20.0, -30.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(90.5, -13.0, -30.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(101.25, -13.0, -30.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(101.25, -13.0, -7.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(101.25, -26.0, 6.25);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(101.25, -26.0, 18.0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(43.75, -26.0, 18.0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(43.75, -26.0, -14.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(43.75, -15.0, -26.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(43.75, -15.0, -31.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(43.75, -26.0, -43.75);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(43.75, -26.0, -49.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.25, -26.0, -49.5);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* CARGA TEXTURAS */
    
		none.LoadTGA("texturas/none.tga");
		none.BuildGLTexture();
		none.ReleaseImage();

		wood.LoadTGA("texturas/wood.tga");
		wood.BuildGLTexture();
		wood.ReleaseImage();

		skyBox.LoadTGA("texturas/skyBox.tga");
		skyBox.BuildGLTexture();
		skyBox.ReleaseImage();

		skyBoxSide.LoadTGA("texturas/skyBoxSide.tga");
		skyBoxSide.BuildGLTexture();
		skyBoxSide.ReleaseImage();

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

		

	/* FIN CARGA TEXTURAS */
	
	/* CARGA MODELOS 3DS */

	kit._3dsLoad("3ds/kitt.3ds");	
	
	oldhouse._3dsLoad("3ds/oldhouse/oldhouse.3ds");
	oldhouse.LoadTextureImages();
	oldhouse.GLIniTextures();
	oldhouse.ReleaseTextureImages();
	

	banca._3dsLoad("3ds/b.3ds");
	tree1._3dsLoad("3ds/t.3ds");
	barda._3dsLoad("3ds/f.3ds");
	barda._3dsLoad("3ds/f.3ds");
	ent._3dsLoad("3ds/main.3ds");
	avion._3dsLoad("3ds/airplane.3ds");
	
	/* FIN CARGA MODELOS 3DS*/

	camera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	return;
	
}

void display ( void ) {

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();
	
	glPushMatrix(); // INICIO CAMARA

		glRotatef(g_lookupdown, 1.0f, 0,0);

		gluLookAt(	camera.mPos.x,  camera.mPos.y,  camera.mPos.z,	
					camera.mView.x, camera.mView.y, camera.mView.z,	
					camera.mUp.x,   camera.mUp.y,   camera.mUp.z);
	
		glPushMatrix(); // INICIO AREA DE DIBUJO

			/* SKYBOX */

				glPushMatrix();
					glDisable(GL_LIGHTING);
						renders.skyBox(240.0, 60.0, 200.0, skyBox.GLindex, grass.GLindex, skyBoxSide.GLindex, sideSkyBox);
					glEnable(GL_LIGHTING);
				glPopMatrix();

			/* FIN SKYBOX */

				//		ASFALTO ESTACIONAMIENTO
				glPushMatrix();
							
						glTranslatef(-102.0f, -30.0f, 75.5f);
						glScalef(35, 0.05, 45);
						glDisable(GL_LIGHTING);
						fig1.prisma2(asfalto.GLindex, 0);
						glEnable(GL_LIGHTING);
				
				glPopMatrix();	// TERMINA ASFALTO
				
			

			/* EJES DE REFERENCIA */

				glPushMatrix(); 
					glDisable(GL_TEXTURE_2D);
					glDisable(GL_LIGHTING);
						glBegin(GL_LINES);
							glColor3f(1.0f, 0.0f, 0.0f);
								glVertex3f(0.0f,0.0f,0.0f);
								glVertex3f(100.0f,0.0f,0.0f);
							glColor3f(0.0f, 1.0f, 0.0f);
								glVertex3f(0.0f,0.0f,0.0f);
								glVertex3f(0.0f,100.0f,0.0f);
							glColor3f(0.0f, 0.0f, 1.0f);
								glVertex3f(0.0f,0.0f,0.0f);
								glVertex3f(0.0f,0.0f,100.0f);
							glColor3f(1.0f, 1.0f, 1.0f);
						glEnd();
					glEnable(GL_TEXTURE_2D);
					glEnable(GL_LIGHTING);
				glPopMatrix(); 
		
			/* FIN EJES DE REFERENCIA */

			/* AREA DE PRUEBAS */

				

				
			/* FIN AREA DE PRUEBAS */

			/* ENTRADA 1*/

				glPushMatrix();
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
					
					glTranslatef(-60.0f, -28.0f, 21.5f);
					glRotatef(90, 0, 1, 0);		//		MODIFIQ
					renders.cube(15.0, 4.0, 3.0,
									tabiqueMarron.GLindex, none.GLindex, tabiqueMarron.GLindex,
									tabiqueMarron.GLindex, entradaTabiqueMarron.GLindex, entradaTabiqueMarron.GLindex);


					glDisable(GL_ALPHA_TEST);
				glPopMatrix();

				/* FIN ENTRADA */

				/* ENTRADA 2*/
				glPushMatrix();
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);

				glTranslatef(-60.0f, -28.0f, 41.75f);
				glRotatef(90, 0, 1, 0);		//		MODIFIQ
				renders.cube(15.0, 4.0, 3.0,
					tabiqueMarron.GLindex, none.GLindex, tabiqueMarron.GLindex,
					tabiqueMarron.GLindex, entradaTabiqueMarron.GLindex, entradaTabiqueMarron.GLindex);


				glDisable(GL_ALPHA_TEST);
				glPopMatrix();


			/* FIN ENTRADA 2*/

			/* TAQUILLAS */

				glPushMatrix();
					glTranslatef(-60.0f, -28.0f, 11.0f);
					glRotatef(270, 0, 1, 0);		//		MODIFIQ
						renders.cube(6.0f, 6.0f, 9.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex,tabiqueMarron.GLindex,
										tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
						glPopMatrix();

				glPushMatrix();
					glTranslatef(-60.0f, -28.0f, 32.0f);
					glRotatef(270, 0, 1, 0);		//		MODIFIQ
						renders.cube(6.0f, 6.0f, 9.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex, tabiqueMarron.GLindex,
										tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
				glPopMatrix();


				glPushMatrix();
				glTranslatef(-60.0f, -28.0f, 52.0f);
				glRotatef(270, 0, 1, 0);		//		MODIFIQ
				renders.cube(6.0f, 6.0f, 9.0f, tabiqueMarron.GLindex, tabiqueMarron.GLindex, tabiqueMarron.GLindex,
					tabiqueMarron.GLindex, taquilla.GLindex, tabiqueMarron.GLindex);
				glPopMatrix();
			/* FIN TAQUILLAS */

			/* SUPERMAN */
			
				glPushMatrix();
					glDisable(GL_TEXTURE_2D);
				/*	glDisable(GL_LIGHTING);*/
						renderSuperman();
						renderSupermanSoportes();
					glEnable(GL_TEXTURE_2D);
					/*glEnable(GL_LIGHTING);*/
				glPopMatrix();
			
			/* FIN SUPERMAN */

			//		INICIO DE MODELOS EN 3DS

			glPushMatrix();		// PUSH PRINCIPAL
				glDisable(GL_COLOR_MATERIAL);		//	ACTIVAR COLORES PARA MODELOS 3D

//		BANCAS

				glPushMatrix();
					glTranslatef(-28, -28.7, -90);
					glScalef(1.5, 1.5, 1.5);
					banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-23, -28.7, -90);
					glScalef(1.5, 1.5, 1.5);
					banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


				glPushMatrix();
					glTranslatef(-18, -28.7, -90);
					glScalef(1.5, 1.5, 1.5);
					banca.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

//		TERMINO BANCAS

// BARDAS	SUPERMAN

				glPushMatrix();
					glTranslatef(45,-30.0,-96);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(45, -30.0, -90);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(45, -30.0, -84);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(45, -30.0, -78);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(45, -30.0, -72);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(45, -30.0, -66);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(45, -30.0, -62);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(42, -30.0, -59);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(36, -30.0, -59);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(30, -30.0, -59);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(24, -30.0, -59);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(21, -30.0, -56);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(21, -30.0, -50);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(21, -30.0, -44);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(21, -30.0, -38);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(21, -30.0, -32);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(21, -30.0, -26);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();



						//	ENTRADA EN SUPERMAN
				
				glPushMatrix();
				glTranslatef(18, -30.0, -23);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(12, -30.0, -23);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(6, -30.0, -23);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

							//		entrada
				glPushMatrix();
				glTranslatef(2, -30.0, -17);
				glRotatef(90, 0,1,0);
				ent.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(18, -30.0, -11);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(12, -30.0, -11);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(6, -30.0, -11);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


			// TERMINA ENTRADA EN SUPERMAN
				
			// BARDA SUPERMAN

				glPushMatrix();
					glTranslatef(21, -30.0, -8);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(21, -30.0, -2);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(21, -30.0, 4);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(21, -30.0, 10);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(21, -30.0, 16);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(21, -30.0, 22);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(24, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(30, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(36, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(42, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(48, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(54, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(60, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(66, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(72, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(78, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(84, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(90, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(96, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(102, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(108, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
					glTranslatef(114, -30.0, 25);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


			// TERMINO BARDA SUPERMAN

// COMIENZA AVIÓN 				
				glPushMatrix();
				glTranslatef(24, 0.0, 25);
				avion.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
						
//	TERMINA AVIÓN
	
//		ARBOLES
				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, 40.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, -20.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();



//		TERMINA ALBOLES

				
				glEnable(GL_COLOR_MATERIAL); //	DESACTIVAR COLORES PARA MODELOS 3D

			
		glPopMatrix();		// POP PRINCIPAL

			glColor3f(1.0,1.0,1.0);
		
		glPopMatrix(); // FIN AREA DE DIBUJO
	glPopMatrix(); // FIN CAMARA
	
	/* Nota: Es peligrosisimo dejar esto al final "glDisable(GL_TEXTURE_2D);", 
		ya que cuando vuelvo a llamar a display ya estan deshabilitas las texturas,
		siempre se deben dejar habilitadas las texturas al final */

	glutSwapBuffers ( );
}


void reshape(int width, int height) {

	// Prevenir division entre 0

	if (!height)
		return;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION); // Activamos la matriz de proyeccion. 
	glLoadIdentity();// "limpiamos" esta con la matriz identidad.

	gluPerspective(45, (GLfloat)width / (GLfloat)height, 0.01, 1000.0);

	glMatrixMode(GL_MODELVIEW); // Activamos la matriz de modelado/visionado. 
	glLoadIdentity();  // "Limpiamos" la matriz
	return;
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0);
		break;
	case 'w':   //Movimientos de camara
	case 'W':
		camera.Move_Camera(CAMERASPEED + 2.2);
		break;

	case 's':
	case 'S':
		camera.Move_Camera(-(CAMERASPEED + 2.2));
		break;

	case 'a':
	case 'A':
		camera.Strafe_Camera(-(CAMERASPEED + 2.4));
		break;

	case 'd':
	case 'D':
		camera.Strafe_Camera(CAMERASPEED + 2.4);
		break;

	case 'q':
	case 'Q':
		camera.UpDown_Camera(CAMERASPEED + 0.5);
		break;

	case 'e':
	case 'E':
		camera.UpDown_Camera(-(CAMERASPEED + 0.5));
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

	switch (key) {
	case GLUT_KEY_PAGE_UP:
		camera.UpDown_Camera(CAMERASPEED+0.4);
		break;

	case GLUT_KEY_PAGE_DOWN:
		camera.UpDown_Camera(-(CAMERASPEED+0.4));
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

/* ANIMACION SUPERMAN */	

	if (animSuperman.play) {
		if (animSuperman.currSteps >= animSuperman.maxSteps) { /* Termino animacion entre frames? */
			animSuperman.currentFrameIndex++;
			if (animSuperman.currentFrameIndex >= animSuperman.finalFrameIndex) { /* Termino la animacion completa? */
				printf("TERMINA ANIMACION SUPERMAN\n");
				animSuperman.currentFrameIndex = 0;
				animSuperman.play = false;
			} else { /* ¡ No ha terminado la animacion !, me preparo para nueva animacion entre frames*/
				animSuperman.currSteps = 0; // Reseteo el contador de pasos
				animSuperman.interpolation(); // Calculo los nuevos incrementos
			}
		} else {

			// Dibujo Animación

			animSuperman.posX += animSuperman.keyFrame[animSuperman.currentFrameIndex].posXInc;
			animSuperman.posY += animSuperman.keyFrame[animSuperman.currentFrameIndex].posYInc;
			animSuperman.posZ += animSuperman.keyFrame[animSuperman.currentFrameIndex].posZInc;
			animSuperman.rotX += animSuperman.keyFrame[animSuperman.currentFrameIndex].rotXInc;
			animSuperman.rotY += animSuperman.keyFrame[animSuperman.currentFrameIndex].rotYInc;
			animSuperman.rotZ += animSuperman.keyFrame[animSuperman.currentFrameIndex].rotZInc;

			animSuperman.currSteps++;
		}

	}

	glutPostRedisplay();
}

void audio() {
	PlaySound("feria.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}


int main ( int argc, char** argv ) {
	
//	audio();

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (1280, 720);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Parque de Diversiones"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( specialKeys );	//Otras
  glutIdleFunc		  ( animation );

  glutMainLoop        ( );          // 

  return 0;
}

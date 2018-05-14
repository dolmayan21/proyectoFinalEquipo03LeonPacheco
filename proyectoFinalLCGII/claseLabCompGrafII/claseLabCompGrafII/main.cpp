/*
	LABORATORIO DE COMPUTAC�N GR�FICA

		PROYECTO FINAL 
			
			> PARQUE DE DIVERSIONES <

			PACHECO FRANCO JES�S ENRIQUE
			LE�N DEL VILLAR RUB�N ALEJANDRO

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
		SPACE : Comenzar con recorrido de monito.

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
	float rotEsfSup = 0.0f;

	typedef struct posRot {
		float posX;
		float posY;
		float posZ;
		float rotX;
		float rotY;
		float rotZ;
	}posRot;

	GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis

	bool playHuracan = false;
	

/* FIN VARIABLES GLOBALES */

/* MAQUINA DE ESTADOS PELOTA */

	float pelotaX = 0.0f, pelotaY = 0.0;

	bool playPelota = false;

	enum pelotaEstados { Y1_, Y2_, Y3_, Y4_, Y5_, STOOOP };
	enum pelotaEstados edoPrePelota, edoSigPelota;


/* FIN MAQUINA DE ESTADOS PELOTA*/

/* MAQUINA DE ESTADOS -- AVION */
	
	bool playAvion = false;

	enum avionEstados { APXRPZ, APX, APXRN, APXRNZ, APXRNZ_2, APX_2, STOP};
	enum avionEstados edoPreAvion, edoSigAvion;

	posRot avionVar;


/* FIN MAQUINA DE ESTADOS -- AVION*/

/* MAQUINA DE ESTADOS -- RECORRIDO */

	bool playRecorrido = false;

	enum recorridoEstados { E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, STOOP };
	enum recorridoEstados edoPreRec, edoSigRec;

/* FIN MAQUINA DE ESTADOS -- RECORRIDO */

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

	CTexture carrMontLat;
	CTexture carrMontFront;
	CTexture carrMontTras;
	CTexture carrMontSuelo;

	CTexture six;
	CTexture super;
	CTexture asiento;
	CTexture supermanLogo;

	CTexture basketball;

/* FIN TEXTURAS */

/* MODELOS */

	CModel kit;
	CModel oldhouse;

	CModel banca;
	CModel tree1;
	CModel barda;
	CModel castle;
	CModel trees;
	CModel tree;
	CModel ent;
	CModel avion;

	CModel barda2;
	CModel table;
	CModel people;
	CModel store;

	CModel car; 
	CModel car2;
	CModel car3;


/* FIN MODELOS */

	//			ANIMACIONES ANIMACION

	//Animaci�n de HURACAN

	DWORD dwFrames = 0;
	DWORD dwCurrentTime = 0;
	DWORD dwLastUpdateTime = 0;
	DWORD dwElapsedTime = 0;

	int anim_soporte = 0.0;
	int anim_soporte2 = 0.0;

	//Animacion Persona
	float movKit = 0.0;
	float voltear = 90.0;
	bool g_persona = false;
	bool g_persona2 = true;


void renderSuperman() {

		/* MONTA�A RUSA - SUPERMAN */

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

		/* FIN - MONTA�A RUSA - SUPERMAN */
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

		wood.LoadTGA("texturas/wood2.tga");
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

		asfalto.LoadTGA("texturas/asfalto2.tga");
		asfalto.BuildGLTexture();
		asfalto.ReleaseImage();

		taquilla.LoadTGA("texturas/taquilla.tga");
		taquilla.BuildGLTexture();
		taquilla.ReleaseImage();

		carrMontLat.LoadTGA("texturas/carrMontLat.tga");
		carrMontLat.BuildGLTexture();
		carrMontLat.ReleaseImage();

		carrMontFront.LoadTGA("texturas/carrMontFront.tga");
		carrMontFront.BuildGLTexture();
		carrMontFront.ReleaseImage();

		carrMontTras.LoadTGA("texturas/carrMontTras.tga");
		carrMontTras.BuildGLTexture();
		carrMontTras.ReleaseImage();

		carrMontSuelo.LoadTGA("texturas/carrMontSuelo.tga");
		carrMontSuelo.BuildGLTexture();
		carrMontSuelo.ReleaseImage();

		six.LoadTGA("texturas/six.tga");
		six.BuildGLTexture();
		six.ReleaseImage();
		
		super.LoadTGA("texturas/super.tga");
		super.BuildGLTexture();
		super.ReleaseImage();

		asiento.LoadTGA("texturas/asientos2.tga");
		asiento.BuildGLTexture();
		asiento.ReleaseImage();

		supermanLogo.LoadTGA("texturas/supermanLogo.tga");
		supermanLogo.BuildGLTexture();
		supermanLogo.ReleaseImage();

		basketball.LoadTGA("texturas/basketball.tga");
		basketball.BuildGLTexture();
		basketball.ReleaseImage();

	/* FIN CARGA TEXTURAS */
	
/* CARGA MODELOS 3DS */

	kit._3dsLoad("3ds/kitt.3ds");	
	
	oldhouse._3dsLoad("3ds/oldhouse/oldhouse.3ds");
	oldhouse.LoadTextureImages();
	oldhouse.GLIniTextures();
	oldhouse.ReleaseTextureImages();
	

	banca._3dsLoad("3ds/b.3ds");
	tree1._3dsLoad("3ds/t.3ds");
	tree._3dsLoad("3ds/tree.3ds");
	barda._3dsLoad("3ds/f.3ds");
	barda._3dsLoad("3ds/f.3ds");
	barda2._3dsLoad("3ds/fence2.3ds");
	ent._3dsLoad("3ds/main.3ds");
	avion._3dsLoad("3ds/airplane.3ds");

	table._3dsLoad("3ds/picnic.3ds");
	people._3dsLoad("3ds/people.3ds");

	store._3dsLoad("3ds/store.3ds");

	car._3dsLoad("3ds/car.3ds");
	car2._3dsLoad("3ds/car2.3ds");
	car3._3dsLoad("3ds/car3.3ds");


/* FIN CARGA MODELOS 3DS*/

/* FRAMES SUPERMAN */

	animSuperman.keyFrame[0] = { 25.25, 0.0, -25.3f, 0.0, -15.0, 0.0, 0.0, 0.0, -90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[1] = { 25.25, 0.0, -25.3f, 0.0, 9.0, 0.0, 0.0, 0.0, -90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[2] = { 26.25, 0.0, -25.3f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[3] = { 33.0, 0.0, -25.3f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[4] = { 33.5, 0.0, -25.0f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 45.0, 0.0 };
	animSuperman.keyFrame[5] = { 40.0, 0.0, -18.5f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 45.0, 0.0 };
	animSuperman.keyFrame[6] = { 41.0, 0.0, -18.3f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[7] = { 45.5, 0.0, -18.3f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[8] = { 46.5, 0.0, -18.9f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, -45.0, 0.0 };
	animSuperman.keyFrame[9] = { 56.5, 0.0, -28.9f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, -45.0, 0.0 };
	animSuperman.keyFrame[10] = { 57.0, 0.0, -29.3f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[11] = { 65.75, 0.0, -29.3f, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[12] = { 66.75, 0.0, -29.3f, 0.0, 9.0, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[13] = { 66.75, 0.0, -29.3f, 0.0, 4.25, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[14] = { 66.75, 0.0, -29.0f, 0.0, 3.75, 0.0, 45.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[15] = { 66.75, 0.0, 2.5f, 0.0, -27.75, 0.0, 45.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[16] = { 66.75, 0.0, 2.7f, 0.0, -28.75, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[17] = { 66.75, 0.0, 2.7f, 0.0, -35.25, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[18] = { 66.75, 0.0, 2.1f, 0.0, -36.25, 0.0, -45.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[19] = { 66.75, 0.0, -18.9f, 0.0, -57.25, 0.0, -45.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[20] = { 66.75, 0.0, -19.3f, 0.0, -57.75, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[21] = { 66.75, 0.0, -19.3f, 0.0, -62.75, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[22] = { 66.75, 0.0, -19.0f, 0.0, -63.25, 0.0, 45.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[23] = { 66.75, 0.0, -13.5f, 0.0, -68.75, 0.0, 45.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[24] = { 66.75, 0.0, -13.3f, 0.0, -69.75, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[25] = { 66.75, 0.0, -13.3f, 0.0, -71.5, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[26] = { 67.75, 0.0, -13.3f, 0.0, -72.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[27] = { 83.25, 0.0, -13.3f, 0.0, -72.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[28] = { 83.25, 0.0, -13.3f, 0.0, -73.5, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[29] = { 83.25, 0.0, -13.3f, 0.0, -93.0, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[30] = { 83.25, 0.0, -13.3f, 0.0, -93.0, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[31] = { 75.25, 0.0, -13.3f, 0.0, -93.0, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[32] = { 73.75, 0.0, -13.3f, 0.0, -92.0, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[33] = { 73.75, 0.0, -13.3f, 0.0, -86.75, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[34] = { 73.75, 0.0, -13.9f, 0.0, -85.75, 0.0, 45.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[35] = { 73.75, 0.0, -18.9f, 0.0, -80.75, 0.0, 45.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[36] = { 73.75, 0.0, -19.3f, 0.0, -80.25, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[37] = { 73.75, 0.0, -19.3f, 0.0, -31.5, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[38] = { 74.75, 0.0, -19.3f, 0.0, -30.5, 0.0, 0.0, 0.0, 360.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[39] = { 82.5, 0.0, -19.3f, 0.0, -30.5, 0.0, 0.0, 0.0, 360.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[40] = { 83.0, 0.0, -19.0f, 0.0, -30.5, 0.0, 0.0, 0.0, 360.0, 0.0, 45.0, 0.0 };
	animSuperman.keyFrame[41] = { 89.5, 0.0, -12.5f, 0.0, -30.5, 0.0, 0.0, 0.0, 360.0, 0.0, 45.0, 0.0 };
	animSuperman.keyFrame[42] = { 90.5, 0.0, -12.3f, 0.0, -30.5, 0.0, 0.0, 0.0, 360.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[43] = { 100.25, 0.0, -12.3f, 0.0, -30.5, 0.0, 0.0, 0.0, 360.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[44] = { 101.25, 0.0, -12.3f, 0.0, -29.5, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[45] = { 101.25, 0.0, -12.3f, 0.0, -7.25, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[46] = { 101.25, 0.0, -12.9f, 0.0, -6.25, 0.0, 0.0, 0.0, 270.0, 0.0, -45.0, 0.0 };
	animSuperman.keyFrame[47] = { 101.25, 0.0, -24.9f, 0.0, 5.75, 0.0, 0.0, 0.0, 270.0, 0.0, -45.0, 0.0 };
	animSuperman.keyFrame[48] = { 101.25, 0.0, -25.3f, 0.0, 6.25, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[49] = { 101.25, 0.0, -25.3f, 0.0, 17.0, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[50] = { 100.25, 0.0, -25.3f, 0.0, 18.0, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[51] = { 44.75, 0.0, -25.3f, 0.0, 18.0, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[52] = { 43.75, 0.0, -25.3f, 0.0, 17.0, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[53] = { 43.75, 0.0, -25.3f, 0.0, -14.75, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[54] = { 43.75, 0.0, -25.0f, 0.0, -15.25, 0.0, 0.0, 0.0, 90.0, 0.0, 45.0, 0.0 };
	animSuperman.keyFrame[55] = { 43.75, 0.0, -14.5f, 0.0, -25.75, 0.0, 0.0, 0.0, 90.0, 0.0, 45.0, 0.0 };
	animSuperman.keyFrame[56] = { 43.75, 0.0, -14.3f, 0.0, -26.75, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[57] = { 43.75, 0.0, -14.3f, 0.0, -32.25, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[58] = { 43.75, 0.0, -14.9f, 0.0, -33.25, 0.0, 0.0, 0.0, 90.0, 0.0, -45.0, 0.0 };
	animSuperman.keyFrame[59] = { 43.75, 0.0, -24.9f, 0.0, -43.25, 0.0, 0.0, 0.0, 90.0, 0.0, -45.0, 0.0 };
	animSuperman.keyFrame[60] = { 43.75, 0.0, -25.3f, 0.0, -43.75, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[61] = { 43.75, 0.0, -25.3f, 0.0, -48.5, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[62] = { 42.75, 0.0, -25.3f, 0.0, -49.5, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[63] = { 26.25, 0.0, -25.3f, 0.0, -49.5, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[64] = { 25.25, 0.0, -25.3f, 0.0, -48.5, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };
	animSuperman.keyFrame[65] = { 25.25, 0.0, -25.3f, 0.0, -15.0, 0.0, 0.0, 0.0, 270.0, 0.0, 0.0, 0.0 };

/* ANIMACION AVION -- INICIALIZACION DE VARIABLES */

	edoPreAvion = APXRPZ;
	edoSigAvion = APXRPZ;

	avionVar.posX = -147.5;
	avionVar.posY = 10.0;
	avionVar.posZ = -38.0;

	avionVar.rotX = 0.0;
	avionVar.rotY = 90.0;
	avionVar.rotZ = 45.0;

/* ANIMACION RECORRIDO -- INICIALIZACION DE VARIABLES */

	edoPreRec = E1;
	edoSigRec = E1;

/* ANIMACION PELOTA -- INICIALIZACION DE VARIABLES */

	pelotaX = 0.0;
	pelotaY = 10.0;

	edoPrePelota = Y1_;
	edoSigPelota = Y1_;

/* CAMARA */
	
	/*camera.Position_Camera(45.0, -15.0f, 30.0, 45.0, -15.0f, -30.0, 0.0, 1.0, 0.0);*/

	camera.Position_Camera(-115.0, 0.0f, 95.0, 115.0, 0.0f, -95.0, 0.0, 1.0, 0.0);

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

			/* ESFERA SUPERMAN */

				glPushMatrix();
					glTranslatef(30.0, -30.0, 20.0);
					glColor3f(0.066, 0.094, 0.305);
					fig2.cilindroVertical(1.0, 20.0, 20, 0);
					glColor3f(1.0, 1.0, 1.0);
					glTranslatef(0.0, 24.5, 0.0);
					glRotatef(rotEsfSup, 0.0, 1.0, 0.0);
					fig2.esfera(5.0, 20, 20, supermanLogo.GLindex);
					glColor3f(1.0, 1.0, 1.0);
				glPopMatrix();

			/* TERMINA ESFERA SUPERMAN */

			/* ANIMACION PELOTA */

				glPushMatrix();
					glRotatef(90.0, 0.0, 1.0, 0.0);
					glTranslatef(0.0, -29.0, -15.0);
					glTranslatef(pelotaX, pelotaY, 0.0);
					fig2.esfera(1.0, 20, 20, basketball.GLindex);
				glPopMatrix();

			/* FIN ANIMACION PELOTA */

			//	SIMBOLO SIX

				glPushMatrix();
					glTranslatef(-85.0f, -29.0f, -20.5f);
					glRotatef(90, 0,1,0);
					glDisable(GL_LIGHTING);
					renders.cube(30.0, 0.2, 30.0,
					six.GLindex, six.GLindex, six.GLindex, six.GLindex, six.GLindex, six.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();


				glPushMatrix();
					glTranslatef(30.0f, -29.0f, -80.5f);
					glRotatef(-90, 0, 1, 0);
					glDisable(GL_LIGHTING);
					renders.cube(20.0, 0.2, 20.0,
					six.GLindex, six.GLindex, six.GLindex, six.GLindex, six.GLindex, six.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();			

			//	TERMINA	SIMBOLOS SIX

			// COMIENZA HURAC�N

				glPushMatrix();
						glTranslatef(92.0f, -29.0f, 65.5f);
						glDisable(GL_LIGHTING);
						renders.cube(25.0, 1.0, 45.0,
							wood.GLindex, wood.GLindex, wood.GLindex,		//	BASE 
							wood.GLindex, wood.GLindex, wood.GLindex);
						glEnable(GL_LIGHTING);
				glPopMatrix();	

				glPushMatrix();
				glTranslatef(90.0f, -19.5f, 85.0f);
				glDisable(GL_LIGHTING);
				renders.cube(3.0, 20.0, 1.5,
					wood.GLindex, wood.GLindex, wood.GLindex,		//	SOPORTE IZQUIERDO
					wood.GLindex, wood.GLindex, wood.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(90.0f, -19.5f, 45.0f);
				glDisable(GL_LIGHTING);
				renders.cube(3.0, 20.0, 1.5,
					wood.GLindex, wood.GLindex, wood.GLindex,		//	SOPORTE DERECHO
					wood.GLindex, wood.GLindex, wood.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();
						
					//		CILINDROS
										
				glPushMatrix();
					glTranslatef(90.0f, -10.0f, 85.0f);		// IZQUIERDO
					glRotatef(90, 0, 1, 0);
					fig2.cilindro(2.0, 2, 20);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(90.0f, -10.0f, 45.0f);			// DERECHO
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(2.0, 2, 20);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(90.0f, -10.0f, 46.0f);			// PEQUE�O DERECHO
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(0.5, 2, 20);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(90.0f, -10.0f, 84.0f);			// PEQUE�O IZQUIERDO
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(0.5, 2, 20);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(90.0f, -10.0f, 48.0f);		//	DERECHO
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(2.0, 2.5, 20);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(90.0f, -10.0f, 82.0f);			//  IZQUIERDO
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(2.0, 2.5, 20);
				glPopMatrix();


				glPushMatrix();
				glTranslatef(90.0f, -10.0f, 82.0f);			//  IZQUIERDO PARTE DE ARRIBA
				glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);		//	CILINDRO animacion
				glTranslatef(0.0f, 10.0f, 0.0f);			//  IZQUIERDO PARTE DE ARRIBA
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(2.0, 2.5, 20);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(90.0f, -10.0f, 48.0f);			//  DERECHO PARTE DE ARRIBA
					glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);		//	CILINDRO animacion
					glTranslatef(0.0f, 10.0f, 0.0f);			//  DERECHO PARTE DE ARRIBA
					glRotatef(90, 0, 1, 0);
					fig2.cilindro(2.0, 2.5, 20);
				glPopMatrix();
				

				glPushMatrix();		//  IZQUIERDO PARTE DE ARRIBA
					glTranslatef(90.0f, -10.0f, 82.0f);	
					glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);		//	CILINDRO animacion
					glTranslatef(0.0f, -10.0f, 0.0f);
					glRotatef(90, 0, 1, 0);
					fig2.cilindro(2.0, 2.5, 20);
				glPopMatrix();

				glPushMatrix();			//  DERECHO PARTE DE ARRIBA
					glTranslatef(90.0f, -10.0f, 48.0f);			
					glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);		//	CILINDRO animacion
					glTranslatef(0.0f, -10.0f, 0.0f);			
					glRotatef(90, 0, 1, 0);
					fig2.cilindro(2.0, 2.5, 20);
				glPopMatrix();
					//	FIN	CILINDROS


				glPushMatrix();
					glTranslatef(90.0f, -10.0f, 48.0f);
					
					glRotatef(anim_soporte +50, 0.0, 0.0, 1.0);		//posterior animacion
					glDisable(GL_LIGHTING);
					renders.cube(3.0, 23.0, 1.5,
						wood.GLindex, wood.GLindex, wood.GLindex,		//	SOPORTES DERECHO
						wood.GLindex, wood.GLindex, wood.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
						glTranslatef(90.0f, -10.0f, 82.0f);
						glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);		//posterior animacion
						glDisable(GL_LIGHTING);
						renders.cube(3.0, 23.0, 1.5,
							wood.GLindex, wood.GLindex, wood.GLindex,		//	SOPORTES IZQUIERDO
							wood.GLindex, wood.GLindex, wood.GLindex);
						glEnable(GL_LIGHTING);
				glPopMatrix();
				
				//		LO QUE LE PUSE

				glPushMatrix();

							glTranslatef(90.0f, -10.0f, 65.0f);

							glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);		//posterior animacion

							glTranslatef(0.0f, -10.0f, 0.0f);

						glRotatef(anim_soporte2 + 100, 0.0, 0.0, 1.0);		//posterior animacion
						glDisable(GL_LIGHTING);
						renders.cube(5.0, 5.0, 31.0,
							 wood.GLindex, wood.GLindex, wood.GLindex,		//	SOPORTES IZQUIERDO
							asiento.GLindex, wood.GLindex, wood.GLindex);
						glEnable(GL_LIGHTING);
				glPopMatrix();


						//	CILINDRO DE ENMEDIO

				glPushMatrix();		
				glTranslatef(90.0f, -10.0f, 65.0f);
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(0.5, 34.0, 20);
				glPopMatrix();

				//		FIN DE LO QUE LE PUSE
			//	TERMINA HURAC�N


				glPushMatrix();

							glTranslatef(90.0f, -10.0f, 65.0f);

							glRotatef(anim_soporte + 50, 0.0, 0.0, 1.0);		//posterior animacion

							glTranslatef(0.0f, -10.0f, 0.0f);

						glRotatef(anim_soporte2 + 100, 0.0, 0.0, 1.0);		//posterior animacion
						glDisable(GL_LIGHTING);
						renders.cube(5.0, 5.0, 31.0,
							 wood.GLindex, wood.GLindex, wood.GLindex,		//	SOPORTES IZQUIERDO
							asiento.GLindex, wood.GLindex, wood.GLindex);
						glEnable(GL_LIGHTING);
				glPopMatrix();


						//	CILINDRO DE ENMEDIO

				glPushMatrix();		
				glTranslatef(90.0f, -10.0f, 65.0f);
				glRotatef(90, 0, 1, 0);
				fig2.cilindro(0.5, 34.0, 20);
				glPopMatrix();

				//		FIN DE LO QUE LE PUSE


				//	TERMINA HURAC�N
				
			/* EJES DE REFERENCIA */

			/*	glPushMatrix(); 
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
				glPopMatrix(); */
		
			/* FIN EJES DE REFERENCIA */

			/* AREA DE PRUEBAS */

					//	ESFERA SUPERMAN
					

			/* AVION -- ANIMACION */

				glPushMatrix();
					
					glDisable(GL_COLOR_MATERIAL);

						glTranslatef(avionVar.posX, avionVar.posY, avionVar.posZ);
						glRotatef(avionVar.rotY, 0.0, 1.0, 0.0);
						glRotatef(avionVar.rotX, 1.0, 0.0, 0.0);
						glRotatef(avionVar.rotZ, 0.0, 0.0, 1.0);
						glTranslatef(2.0, -4.5, 0.0); // Reajustamos mas o menos el pivote
						avion.GLrender(NULL, _SHADED, 1.0); // Modelo 3DS
					glEnable(GL_COLOR_MATERIAL);

				glPopMatrix();

			/* FIN AVION -- ANIMACION */


			/* FIN AREA DE PRUEBAS */

			/* CARRITO SUPERMAN -- ANIMACION -- */

				glPushMatrix();
				
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);

					glTranslatef(animSuperman.posX, animSuperman.posY, animSuperman.posZ);
					glRotatef(animSuperman.rotX, 1.0, 0.0, 0.0);
					glRotatef(animSuperman.rotY, 0.0, 1.0, 0.0);
					glRotatef(animSuperman.rotZ, 0.0, 0.0, 1.0);
					
						renders.cubeII(1.0, 1.0, 1.5,
										none.GLindex, carrMontSuelo.GLindex, carrMontTras.GLindex,
										carrMontFront.GLindex, carrMontLat.GLindex, carrMontLat.GLindex);

					glDisable(GL_ALPHA_TEST);

				glPopMatrix();

			/* FIN CARRITO SUPERMAN -- ANIMACION -- */

			/* ASFALTO ESTACIONAMIENTO */

				glPushMatrix();
							
						glTranslatef(-102.0f, -29.99f, 75.5f);
						glScalef(35, 0.05, 45);
						glDisable(GL_LIGHTING);
						fig1.prisma2(asfalto.GLindex, 0);
						glEnable(GL_LIGHTING);
				
				glPopMatrix();

			/* TERMINA ASFALTO ESTACIONAMIENTO */

		

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

				//		BARDA PARA HURACAN
				glPushMatrix();
					glTranslatef(63, -30.0, 28);
					glRotatef(90, 0, 1, 0);
					barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 34);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 40);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


				glPushMatrix();
				glTranslatef(63, -30.0, 46);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 52);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 58);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


							//	CAMINO PARA HURRICANE

				glPushMatrix();
				glTranslatef(60, -30.0, 61);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(54, -30.0, 61);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(48, -30.0, 61);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(42, -30.0, 61);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(36, -30.0, 61);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

						//	MAIN
				glPushMatrix();
				glTranslatef(33, -30.0, 67);
				glRotatef(90, 0, 1, 0);
				ent.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

						//	TERMINO MAIN

				glPushMatrix();
				glTranslatef(60, -30.0, 73);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(54, -30.0, 73);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(48, -30.0, 73);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(42, -30.0, 73);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(36, -30.0, 73);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


							//	FIN CAMINO

				glPushMatrix();
				glTranslatef(63, -30.0, 76);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 82);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 88);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 94);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(63, -30.0, 100);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

			
				
				//		TERMINO BARDA HURACAN

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
	
//		ARBOLES
				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, 40.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();

				glTranslatef(-112.0f, -30.0f, -20.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


				glTranslatef(-112.0f, -30.0f, -0.5f);

				glTranslatef(-112.0f, -30.0f, 10.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, -20.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, -50.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, -80.5f);
				tree1.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				//		INDIVIDUALES
				glPushMatrix();
				glTranslatef(-0.0f, -30.0f, -85.5f);
				tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-25.0f, -30.0f, -75.5f);
				tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-30.0f, -30.0f, -45.5f);
				tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-0.0f, -30.0f, 85.5f);
				tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-20.0f, -30.0f, 55.5f);
				tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-10.0f, -30.0f, 45.5f);
				tree.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

//		TERMINA ALBOLES

// BARDA PARA ENTRADA

				
				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 57.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 60.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
				
				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 63.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 67.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 70.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 74.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 74.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 77.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 81.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 84.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 88.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 91.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 95.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 98.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


				//	BARDA DE LA DERECHA

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 6.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, 2.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -1.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -4.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -8.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -11.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -15.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -18.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -22.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -25.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -29.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -32.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -36.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -39.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -43.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -46.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -50.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -53.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -57.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -60.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -64.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -67.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -71.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -74.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -78.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -81.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -85.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -88.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -92.0f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-60.0f, -29.5f, -95.5f);
				glRotatef(90, 0, 1.0, 0.0);
				barda2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
// FIN BARDA PARA ENTRADA


// MESA 
				glPushMatrix();
				//HEAD
			//	glTranslatef(-0.0f, -30.0f, 50.5f);

				glTranslatef(0.0f, -30.0f, 70.5f);
				glScalef(2.5,2.5,2.5);
			//	glRotatef(90, 0, 1.0, 0.0);
				table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();

				//glTranslatef(-5.0f, -30.0f, 50.5f);

				glTranslatef(-10.0f, -30.0f, 65.5f);
				glScalef(2.5, 2.5, 2.5);
				//	glRotatef(90, 0, 1.0, 0.0);
				table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


				glPushMatrix();
				//glTranslatef(-10.0f, -30.0f, 50.5f);
				glTranslatef(-20.0f, -30.0f, 70.5f);
				glScalef(2.5, 2.5, 2.5);
				//	glRotatef(90, 0, 1.0, 0.0);
				table.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

//	 FIN DE MESA
		
//		INICIO STORE
				glPushMatrix();

				//glTranslatef(-10.0f, -30.0f, 60.5f);
				glTranslatef(-10.0f, -30.0f, 90.0f);

				glRotatef(180, 0, 1.0, 0.0);
				glScalef(4.0,4.0,4.0);
				store.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
//		FIN STORE

//		INICIO Car
				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, 60.5f);
				glRotatef(90, 0, 1.0, 0.0);
				//glScalef(4.0, 4.0, 4.0);
				car.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, 68.5f);
				glRotatef(90, 0, 1.0, 0.0);
				//glScalef(4.0, 4.0, 4.0);
				car2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-112.0f, -30.0f, 76.5f);
				glRotatef(90, 0, 1.0, 0.0);
				//glScalef(4.0, 4.0, 4.0);
				car3.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();


				glPushMatrix();
				glTranslatef(-90.0f, -30.0f, 85.5f);
				glRotatef(90, 0, 1.0, 0.0);
				//glScalef(4.0, 4.0, 4.0);
				car.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-90.0f, -30.0f, 90.5f);
				glRotatef(90, 0, 1.0, 0.0);
				//glScalef(4.0, 4.0, 4.0);
				car2.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-90.0f, -30.0f, 94.5f);
				glRotatef(90, 0, 1.0, 0.0);
				//glScalef(4.0, 4.0, 4.0);
				car3.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
//		FIN Car

// Barda estacionamiento
				glPushMatrix();
				glTranslatef(-117.0f, -30.0f, 98.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-111.0f, -30.0f, 98.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-105.0f, -30.0f, 98.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-99.0f, -30.0f, 98.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-93.0f, -30.0f, 98.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-87.0f, -30.0f, 98.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-84.0f, -30.0f, 95.5f);
				glRotatef(90, 0,1,0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-84.0f, -30.0f, 77.5f);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-84.0f, -30.0f, 71.5f);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-84.0f, -30.0f, 65.5f);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-84.0f, -30.0f, 59.5f);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-84.0f, -30.0f, 53.5f);
				glRotatef(90, 0, 1, 0);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-87.0f, -30.0f, 50.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-93.0f, -30.0f, 50.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-99.0f, -30.0f, 50.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-105.0f, -30.0f, 50.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-111.0f, -30.0f, 50.5f);
				barda.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
//	Fin Barda estacionamiento


// COMIENZO DE PERSONAS
	
				glPushMatrix();
				glTranslatef(-20.0f, -38.0f, 65.5f);
				glRotatef(180, 0, 1, 0);


				glScalef(2.3, 2.3, 2.3);			///		PRUEBA
				
				glTranslatef(0, 4, movKit);

				people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS

				glPopMatrix();

				//			ANIMACION

				/*
				glPushMatrix();
				glTranslatef(-20.0f, -30.0f, 65.5f);
				glScalef(2.0,2.0,2.0);
				people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
				*/
				

				glTranslatef(-20.0f, -38.0f, 65.5f);
				glRotatef(180, 0, 1, 0);


				glScalef(2.3, 2.3, 2.3);			///		PRUEBA
				
				glTranslatef(0, 4, movKit);

				people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS

				glPopMatrix();

				//			ANIMACION

				/*
				glPushMatrix();
				glTranslatef(-20.0f, -30.0f, 65.5f);
				glScalef(2.0,2.0,2.0);
				people.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
				glPopMatrix();
				*/


// FIN DE PERSONAS

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
			camera.Move_Camera(CAMERASPEED /*+ 2.2*/);
			break;

		case 's':
		case 'S':
			camera.Move_Camera(-(CAMERASPEED/* + 2.2*/));
			break;

		case 'a':
		case 'A':
			camera.Strafe_Camera(-(CAMERASPEED /*+ 2.4*/));
			break;

		case 'd':
		case 'D':
			camera.Strafe_Camera(CAMERASPEED /*+ 2.4*/);
			break;

		case 'q':
		case 'Q':
			camera.UpDown_Camera(CAMERASPEED /*+ 0.5*/-0.3);
			break;

		case 'e':
		case 'E':
			camera.UpDown_Camera(-(CAMERASPEED /*+ 0.5*/ -0.3));
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

		case 'j':
		case 'J':

			if (animSuperman.initialPlay == false && (animSuperman.finalFrameIndex >= 1)) { // Si la animacion esta parada y tengo almenos dos frames

				animSuperman.resetElements();
				animSuperman.interpolation();

				animSuperman.play = true;
				animSuperman.initialPlay = true;
				animSuperman.currentFrameIndex = 0;
				animSuperman.currSteps = 0;

			} else {

				animSuperman.play ^= true;

			}

			break;

		case 'k':
		case 'K':

			playAvion ^= true;

			break;

		case 'p':
		case 'P':

			playPelota ^= true;

			break;

		case 'l':
		case 'L':

			camera.mPos.x = -110.0;
			camera.mPos.y = -27.0;
			camera.mPos.z = 80.0;
			camera.mView.x = 0.0;
			camera.mView.y = -27.0;
			camera.mView.z = 80.0;
			g_lookupdown = 0.0;

			playRecorrido ^= true;

			break;

		case 'h':
		case 'H':

			playHuracan ^= true;

			break;
			
		//			ANIMACION DE PERSONA
		case 'r':
		case 'R':
			movKit = 0.0;
			g_persona2 = true;
			g_persona = false;
			voltear = 90.0;
			break;

		case ' ':		//Poner algo en movimiento
			movKit = 0.0;
			g_persona2 = true;
			g_persona = false;
			voltear = 90.0;



			g_persona ^= true; //Activamos/desactivamos la animac�on
			break;

			//			FIN DE ANIMACION DE PERSONA
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

float Y1(float x) {
	return -2.5 * x * x + 10;
}

float Y2(float x) {
	return -2 * x * x + 16 * x -24;
}

float Y3(float x) {
	return -1.5 * x * x + 24 * x -90;
}

float Y4(float x) {
	return -1 * x * x + 24 * x -140;
}

float Y5(float x) {
	return -0.5 * x * x + 16 * x -126;
}


void animation() {

/* ANIMACION SKYBOX --> MOVIMIENTO DEL CIELO */

	if (sideSkyBox >= 1.0)
		sideSkyBox = 0.0;
	else
		sideSkyBox += 0.0005;

	if (rotEsfSup >= 360)
		rotEsfSup = 0.0;
	else
		rotEsfSup++;

/* ANIMACION PELOTA */

	if (playPelota) {

		edoPrePelota = edoSigPelota;

		switch(edoPrePelota) {
			case Y1_:
				pelotaX = pelotaX + 0.1;
				pelotaY = Y1(pelotaX);

				if (pelotaX >= 2.0)
					edoSigPelota = Y2_;
				else
					edoSigPelota = Y1_;
				break;

			case Y2_:
				pelotaX = pelotaX + 0.1;
				pelotaY = Y2(pelotaX);

				if (pelotaX >= 6.0)
					edoSigPelota = Y3_;
				else
					edoSigPelota = Y2_;
				break;

			case Y3_:
				pelotaX = pelotaX + 0.1;
				pelotaY = Y3(pelotaX);

				if (pelotaX >= 10.0)
					edoSigPelota = Y4_;
				else
					edoSigPelota = Y3_;
				break;

			case Y4_:
				pelotaX = pelotaX + 0.1;
				pelotaY = Y4(pelotaX);

				if (pelotaX >= 14.0)
					edoSigPelota = Y5_;
				else
					edoSigPelota = Y4_;
				break;

			case Y5_:

				pelotaX = pelotaX + 0.1;
				pelotaY = Y5(pelotaX);

				if (pelotaX >= 18.0) {
					edoSigPelota = STOOOP;
					playPelota = false;
				} else {
					edoSigPelota = Y5_;
				}
		
				break;

			case STOOOP:

				if (playPelota) {

					pelotaX = 0.0;
					pelotaY = 10.0;

					edoSigPelota = Y1_;
				} else {
					edoSigPelota = STOOOP;
				}

				break;
		}
		
	}
	
/* ANIMACION SUPERMAN */	

	if (animSuperman.play) {
		if (animSuperman.currSteps >= animSuperman.maxSteps) { /* Termino animacion entre frames? */
			animSuperman.currentFrameIndex++;
			if (animSuperman.currentFrameIndex >= animSuperman.finalFrameIndex) { /* Termino la animacion completa? */
				printf("TERMINA ANIMACION SUPERMAN\n");
				animSuperman.currentFrameIndex = 0;
				animSuperman.initialPlay = false;
				animSuperman.play = false;
			} else { /* � No ha terminado la animacion !, me preparo para nueva animacion entre frames*/
				animSuperman.currSteps = 0; // Reseteo el contador de pasos
				animSuperman.interpolation(); // Calculo los nuevos incrementos
			}
		} else {

			// Dibujo Animaci�n

			animSuperman.posX += animSuperman.keyFrame[animSuperman.currentFrameIndex].posXInc;
			animSuperman.posY += animSuperman.keyFrame[animSuperman.currentFrameIndex].posYInc;
			animSuperman.posZ += animSuperman.keyFrame[animSuperman.currentFrameIndex].posZInc;
			animSuperman.rotX += animSuperman.keyFrame[animSuperman.currentFrameIndex].rotXInc;
			animSuperman.rotY += animSuperman.keyFrame[animSuperman.currentFrameIndex].rotYInc;
			animSuperman.rotZ += animSuperman.keyFrame[animSuperman.currentFrameIndex].rotZInc;

			animSuperman.currSteps++;
		}

	}

/* ANIMACION AVION */

	if (playAvion) {
		edoPreAvion = edoSigAvion;

		switch(edoPreAvion) {
		
			case APXRPZ:

				avionVar.posX = avionVar.posX + 0.5;
				avionVar.rotZ = avionVar.rotZ - 0.3333333;

				if (avionVar.posX >= -80.0)
					edoSigAvion = APX;
				else
					edoSigAvion = APXRPZ;

				break;

			case APX:

				avionVar.posX++;	
			
				if (avionVar.posX >= -40.0)
					edoSigAvion = APXRNZ;
				else
					edoSigAvion = APX;

				break;

			case APXRNZ:
				
				avionVar.posX++;
				avionVar.rotZ = avionVar.rotZ  - 0.45;

				if (avionVar.posX >= 60.0)
					edoSigAvion = APXRNZ_2;
				else
					edoSigAvion = APXRNZ;

				break;

			case APXRNZ_2:

				avionVar.posX++;
				avionVar.rotZ = avionVar.rotZ - 6.3;

				if (avionVar.posX >= 110.0)
					edoSigAvion = APX_2;
				else
					edoSigAvion = APXRNZ_2;
				
				break;

			case APX_2:

				avionVar.posX++;

				if (avionVar.posX >= 135) {
					edoSigAvion = STOP;
					playAvion = false;
				} else {
					edoSigAvion = APX_2;
				}
				
				break;

			case STOP:

				if (playAvion = true) {

					avionVar.posX = -147.5;
					avionVar.posY = 10.0;
					avionVar.posZ = -38.0;

					edoSigAvion = APXRPZ;

				} else {

					edoSigAvion = STOP;

				}

				break;

			default:
				break;
		}
	}

	/* CALCULO DEL NUMERO DE FRAMES POR SEGUNDO */

	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (playHuracan) {

		if (dwElapsedTime >= 30) {

			anim_soporte = (anim_soporte + 20) % 360;
			anim_soporte2 = -anim_soporte;
			anim_soporte2 = (anim_soporte2 + 50) % 360;
			dwLastUpdateTime = dwCurrentTime;

		}

	}

	//		PERSONA

	if (g_persona && movKit <= 10)
	{

		movKit += 0.5;

		if (movKit == 10) {
			g_persona2 = false;
			g_persona = false;
			voltear = -90.0;
			movKit = -10;
		}
	}
	//	voltear;

	if (g_persona2 == false && movKit <= 10)
	{
		movKit += 0.5;

		if (movKit == 10) {
			voltear = 90.0;
			movKit = -10;
			g_persona2 = true;
			g_persona = true;
		}

	}

	glutPostRedisplay();
}

void audio() {
	PlaySound("feria.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}


int main ( int argc, char** argv ) {
	
	//audio();

	glutInit            (&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize  (1280, 720);	// Tama�o de la Ventana
	glutInitWindowPosition (0, 0);	//Posicion de la Ventana
	glutCreateWindow    ("Parque de Diversiones"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL ();						// Parametros iniciales de la aplicacion
	glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc     ( specialKeys );	//Otras
	glutIdleFunc		  ( animation );

	glutMainLoop        ( );          // 

	return 0;

}

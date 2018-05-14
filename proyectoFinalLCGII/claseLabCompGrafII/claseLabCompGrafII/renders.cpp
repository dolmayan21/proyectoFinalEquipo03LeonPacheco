
#include "renders.h"
#include "figuras.h"
#include "math.h"

#define PI 3.14159265359
#define ANCHO_RIEL 1.5
#define ANCHO_TUBO_RIEL 0.1
#define LARGO_CARRIL 1.0
#define RESOLUCION 4

GLfloat rojoSuperman[3] = { 1.0, 0.0, 0.0 };
GLfloat amarilloSuperman[3] = { 1.0, 1.0, 0.0 };
GLfloat azulSuperman[3] = { 0.2, 0.25, 0.80 };

GLfloat blanco[3] = { 1.0, 1.0, 1.0 };

CFiguras figuras;

float distanciaDosPuntos(float aX, float aY, float aZ, float bX, float bY, float bZ) {
	return sqrt(pow(bX - aX, 2) + pow(bY - aY, 2) + pow(bZ - aZ, 2));
}

float radiansToDegrees(float radians) {
	return (radians * 180) / PI;
}

void Render::cube(float lenght, float height, float width,
					GLuint top, GLuint down, GLuint left,
					GLuint right, GLuint front, GLuint back) {

	GLfloat vertexes[8][3] = {
		{-0.5f*lenght, 0.5f*height, 0.5f*width},     // V0
		{ 0.5f*lenght, 0.5f*height, 0.5f*width },    // V1
		{ 0.5f*lenght, 0.5f*height, -0.5f*width },   // V2
		{ -0.5f*lenght, 0.5f*height, -0.5f*width },  // V3
		{ -0.5f*lenght, -0.5f*height, 0.5f*width },  // V4
		{ 0.5f*lenght, -0.5f*height, 0.5f*width },   // V5
		{ 0.5f*lenght, -0.5f*height, -0.5f*width },  // V6
		{ -0.5f*lenght, -0.5f*height, -0.5f*width }, // V7
	};

	glBindTexture(GL_TEXTURE_2D, top);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, down);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[5]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, left);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[0]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, front);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[1]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[3]);
		glEnd();
}

void Render::cubeII(float lenght, float height, float width,
					GLuint top, GLuint down, GLuint left,
					GLuint right, GLuint front, GLuint back) {

	GLfloat vertexes[8][3] = {
		{-0.5f*lenght, 0.5f*height, 0.5f*width},     // V0
		{ 0.5f*lenght, 0.5f*height, 0.5f*width },    // V1
		{ 0.5f*lenght, 0.5f*height, -0.5f*width },   // V2
		{ -0.5f*lenght, 0.5f*height, -0.5f*width },  // V3
		{ -0.5f*lenght, -0.5f*height, 0.5f*width },  // V4
		{ 0.5f*lenght + 0.5, -0.5f*height, 0.5f*width },   // V5
		{ 0.5f*lenght + 0.5, -0.5f*height, -0.5f*width },  // V6
		{ -0.5f*lenght, -0.5f*height, -0.5f*width }, // V7
	};

	glBindTexture(GL_TEXTURE_2D, top);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, down);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[5]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, left);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[0]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, front);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[1]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[3]);
		glEnd();
}

void Render::skyBox(float lenght, float height, float width,
					GLuint top, GLuint down, GLuint side,
					float sideMov) {

	GLfloat vertexes[8][3] = {
		{ -0.5f*lenght, 0.5f*height, 0.5f*width },   // V0
		{ 0.5f*lenght, 0.5f*height, 0.5f*width },    // V1
		{ 0.5f*lenght, 0.5f*height, -0.5f*width },   // V2
		{ -0.5f*lenght, 0.5f*height, -0.5f*width },  // V3
		{ -0.5f*lenght, -0.5f*height, 0.5f*width },  // V4
		{ 0.5f*lenght, -0.5f*height, 0.5f*width },   // V5
		{ 0.5f*lenght, -0.5f*height, -0.5f*width },  // V6
		{ -0.5f*lenght, -0.5f*height, -0.5f*width }, // V7
	};

	glBindTexture(GL_TEXTURE_2D, top);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, down);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 5.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(5.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(5.0f, 5.0f); glVertex3fv(vertexes[6]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // left
		glNormal3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f + sideMov, 1.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f + sideMov, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(0.25f + sideMov, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(0.25f + sideMov, 1.0f); glVertex3fv(vertexes[3]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // right
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.50f + sideMov, 1.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(0.50f + sideMov, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(0.75f + sideMov, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(0.75f + sideMov, 1.0f); glVertex3fv(vertexes[1]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // front
		glNormal3f(0.0f, 0.0f, -1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.75f + sideMov, 1.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(0.75f + sideMov, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f + sideMov, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f + sideMov, 1.0f); glVertex3fv(vertexes[0]);
		glEnd();

	glBindTexture(GL_TEXTURE_2D, side); // back
		glNormal3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.25f + sideMov, 1.0f); glVertex3fv(vertexes[3]);
			glTexCoord2f(0.25f + sideMov, 0.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(0.50f + sideMov, 0.0f); glVertex3fv(vertexes[6]);
			glTexCoord2f(0.50f + sideMov, 1.0f); glVertex3fv(vertexes[2]);
		glEnd();
}

void Render::plane(float lenght, float height, int repeat, GLuint texture) {
	GLfloat vertexes[4][3] = {
		{ -lenght * 0.5f, height * 0.5f, 0.0 },
		{ -lenght * 0.5f, -height * 0.5f, 0.0 },
		{ lenght * 0.5f, -height * 0.5f, 0.0 },
		{ lenght * 0.5f, height * 0.5f, 0.0 },
	};

	glBindTexture(GL_TEXTURE_2D, texture);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 3.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(3.0f, 3.0f); glVertex3fv(vertexes[3]);
		glEnd();
}




/* SUPERMAN */

void Superman::carril(float posX, float posY, float posZ, float rotY, float rotZ, float longRiel1, float longRiel2) {

	float longY, longMY, long1, long2;

	if (rotZ == 0.0) {
		long1 = longRiel1;
		long2 = longRiel2;
	} else {
		long1 = longRiel1 * sqrt(2);
		long2 = longRiel2 * sqrt(2);
	}

	glPushMatrix();
		glTranslatef(posX, posY, posZ);
		
			glRotatef(rotY, 0.0, 1.0, 0.0);
			glRotatef(rotZ, 0.0, 0.0, 1.0);
		
			// RIEL -Z

			glPushMatrix();
				glTranslatef(0.0, 0.0, -ANCHO_RIEL / 2);
					glColor3fv(rojoSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, long1, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

			// RIEL Z

			glPushMatrix();
				glTranslatef(0.0, 0.0, ANCHO_RIEL / 2);
					glColor3fv(rojoSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, long2, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

			// RIEL Y 45°

			longY = distanciaDosPuntos(-long2 / 2, posY, ANCHO_RIEL / 2, long1 / 2, posY, -ANCHO_RIEL / 2 );

			glPushMatrix();
				glTranslatef(-(long2 / 2) + 0.5 * ((long1 + long2) / 2), 0.0, 0.0);
				glRotatef(radiansToDegrees(asin(ANCHO_RIEL / longY)), 0.0, 1.0, 0.0);
					glColor3fv(amarilloSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, longY, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

			// RIEL Y -45°

			longMY = distanciaDosPuntos(-long1 / 2, posY, -ANCHO_RIEL / 2, long2 / 2, posY, ANCHO_RIEL / 2 );

			glPushMatrix();
				glTranslatef(-(long1 / 2) + 0.5 * ((long1 + long2) / 2), 0.0, 0.0);
				glRotatef(radiansToDegrees(asin(ANCHO_RIEL / longMY)), 0.0, -1.0, 0.0);
					glColor3fv(amarilloSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, longMY, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

	glPopMatrix();
}

void Superman::carrilVertical(float long1, float long2, float ancho) {

	float longY, longMY;

	glPushMatrix();

			glRotatef(90, 0.0, 1.0, 0.0);
			glRotatef(90, 0.0, 0.0, 1.0);
			
			glColor3fv(azulSuperman);

			// RIEL -Z

			glPushMatrix();
				glTranslatef(0.0, 0.0, -ancho / 2);
					figuras.cilindro(ANCHO_TUBO_RIEL, long1, RESOLUCION);
			glPopMatrix();

			// RIEL Z

			glPushMatrix();
				glTranslatef(0.0, 0.0, ancho / 2);
					figuras.cilindro(ANCHO_TUBO_RIEL, long2, RESOLUCION);
			glPopMatrix();

			// RIEL Y 45°

			longY = distanciaDosPuntos(-long2 / 2, 0.0, ancho / 2, long1 / 2, 0.0, -ancho / 2 );

			glPushMatrix();
				glTranslatef(-(long2 / 2) + 0.5 * ((long1 + long2) / 2), 0.0, 0.0);
				glRotatef(radiansToDegrees(asin(ancho / longY)), 0.0, 1.0, 0.0);
					figuras.cilindro(ANCHO_TUBO_RIEL, longY, RESOLUCION);
			glPopMatrix();

			// RIEL Y -45°

			longMY = distanciaDosPuntos(-long1 / 2, 0.0, -ancho / 2, long2 / 2, 0.0, ancho / 2 );

			glPushMatrix();
				glTranslatef(-(long1 / 2) + 0.5 * ((long1 + long2) / 2), 0.0, 0.0);
				glRotatef(radiansToDegrees(asin(ancho / longMY)), 0.0, -1.0, 0.0);
					figuras.cilindro(ANCHO_TUBO_RIEL, longMY, RESOLUCION);
			glPopMatrix();

			glColor3fv(blanco);

	glPopMatrix();
}

void Superman::carrilConexion(float posX, float posY, float posZ, float rotY, bool izq ) {

	// DEFAULT

	// ------
	//
	// ------------
	
	float longY, longMenosY;

	glPushMatrix();
		
		glTranslatef(posX, posY, posZ);

			glBegin(GL_LINES);
				glColor3f(1.0, 0.0, 0.0);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(1.5f, 0.0f, 0.0f);
				glColor3f(0.0, 1.0, 0.0);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(0.0f, 1.5f, 0.0f);
				glColor3f(0.0, 0.0, 1.0);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(0.0f, 0.0f, 1.5f);
				glColor3f(1.0, 1.0, 1.0);
			glEnd();
			
			if (izq == true)
				glRotatef(180.0, 0.0, 0.0, 1.0);

			glRotatef(rotY, 0.0, -1.0, 0.0);

			// RIEL -Z

			glPushMatrix();
				glTranslatef(-ANCHO_RIEL/2, 0.0, -ANCHO_RIEL / 2);
					glColor3fv(rojoSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, ANCHO_RIEL, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

			// RIEL Z

			glPushMatrix();
				glTranslatef(0.0, 0.0, ANCHO_RIEL / 2);
					glColor3fv(rojoSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, ANCHO_RIEL*2, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

			// RIEL Y 45°

			longY = distanciaDosPuntos(-ANCHO_RIEL, posY, ANCHO_RIEL / 2, 0, posY, -ANCHO_RIEL / 2);

			glPushMatrix();
				glTranslatef(-0.5*ANCHO_RIEL, 0.0, 0.0);
				glRotatef(radiansToDegrees(asin(ANCHO_RIEL / longY)), 0.0, 1.0, 0.0);
					glColor3fv(amarilloSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, longY, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

			// RIEL Y -45°

			longMenosY = distanciaDosPuntos(-ANCHO_RIEL, posY, -ANCHO_RIEL / 2,	ANCHO_RIEL, posY, ANCHO_RIEL / 2);

			glPushMatrix();
				// glTranslatef(0.0, 0.0, 0.0);
				glRotatef(radiansToDegrees(asin(ANCHO_RIEL / longMenosY)), 0.0, -1.0, 0.0);
					glColor3fv(amarilloSuperman);
					figuras.cilindro(ANCHO_TUBO_RIEL, longMenosY, RESOLUCION);
					glColor3fv(blanco);
			glPopMatrix();

	glPopMatrix();


}

void Superman::soporte(float posX, float posY, float posZ, float alturaSoporte, float alturaIndv, float largo ,float ancho) {

	glPushMatrix();

	glTranslatef(posX, posY, posZ);

		for (int i = 0; i < alturaSoporte; i++) {

			glColor3fv(azulSuperman);

			glPushMatrix();
		
				glTranslatef(0.0, alturaIndv/2 + i*alturaIndv, 0.0);
					glPushMatrix();
						glTranslatef(0.0, 0.0, ancho/2);
						carrilVertical(alturaIndv, alturaIndv, largo);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0, 0.0, -ancho/2);
						carrilVertical(alturaIndv, alturaIndv, largo);
					glPopMatrix();

					glPushMatrix();
						glRotatef(90, 0.0, 1.0, 0.0);
						glTranslatef(0.0, 0.0, largo/2);
						carrilVertical(alturaIndv, alturaIndv, ancho);
					glPopMatrix();

					glPushMatrix();
						glRotatef(90, 0.0, 1.0, 0.0);
						glTranslatef(0.0, 0.0, -largo/2);
						carrilVertical(alturaIndv, alturaIndv, ancho);
					glPopMatrix();

			glPopMatrix();
		}

		glColor3fv(blanco);

	glPopMatrix();
}

void Carril::carril(GLfloat Vi[3], GLfloat Vf[3]) {
	
	// longitud = distanciaDosPuntos(Vi, Vf);

	Vm[0] = Vi[0] + 0.5*(Vf[0] - Vi[0]);
	Vm[1] = Vi[1] + 0.5*(Vf[1] - Vi[1]);
	Vm[2] = Vi[2] + 0.5*(Vf[2] - Vi[2]);

	Vaux[0] = Vf[0];
	Vaux[1] = Vm[1];
	Vaux[2] = Vf[2];

	angX1 = radiansToDegrees(atan((absF(Vf[2]) - Vm[2]) / (absF(Vf[0]) - Vm[0])));
	//angZ1 = radiansToDegrees(atan(distanciaDosPuntos(Vaux,Vf) / distanciaDosPuntos(Vm,Vaux)));

	printf("angX: %f \n angZ: %f\n", angX1, angZ1);
	printf("longitud: %f\n", longitud);
	printf("Vm:(%f,%f,%f)\n", Vm[0], Vm[1], Vm[2]);

	glPushMatrix();

	glTranslatef(Vm[0], Vm[1], Vm[2]);

		if (Vf[2] == Vi[2])
			glRotatef(0.0, 0.0, 1.0, 0.0);
		else if (Vf[0] == Vi[0])
			glRotatef(90.0, 0.0, 1.0, 0.0);
		else if (Vf[0] * Vf[2] > 0.0)
			glRotatef(-angX1, 0.0, 1.0, 0.0);
		else
			glRotatef(angX1, 0.0, 1.0, 0.0);

		if (Vf[1] == Vm[1])
			glRotatef(0.0, 0.0, 0.0, 1.0);
		else if (Vf[2] == Vm[2])
			glRotatef(90.0, 0.0, 0.0, 1.0);
		else if (Vf[0] * Vf[1] > 0.0)
			glRotatef(angZ1, 0.0, 0.0, 1.0);
		else
			glRotatef(-angZ1, 0.0, 0.0, 1.0);

		figuras.cilindro(0.1,longitud, RESOLUCION);

	glPopMatrix();
}



#include "renders.h"

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
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertexes[7]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertexes[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertexes[6]);
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
			glTexCoord2f(0.0f, 7.0f); glVertex3fv(vertexes[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertexes[1]);
			glTexCoord2f(7.0f, 0.0f); glVertex3fv(vertexes[2]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertexes[3]);
		glEnd();
}
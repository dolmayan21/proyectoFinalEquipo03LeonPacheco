
#include "Main.h"

class Render {
	public:
	
		// void skyBox(float lenght, float height, float width, GLuint sideTexture);
		void cube(float lenght, float height, float width, GLuint top, GLuint down, GLuint left, GLuint right, GLuint front, GLuint back);
		void skyBox(float lenght, float height, float width, GLuint top, GLuint down, GLuint side, float sideMov);
		void plane(float lenght, float height, int repeat ,GLuint texture);
};
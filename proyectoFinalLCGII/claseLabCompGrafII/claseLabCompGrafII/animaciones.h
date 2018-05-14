#pragma once

#define NUM_FRAMES_SUPERMAN 66

class AnimacionSuperman {
	public:
	
	/* VARIABLES A ANIMAR */

		float posX = 25.25f;
		float posY = -25.3f;
		float posZ = -15.0f;

		float rotX = 0.0f;
		float rotY = -90.0f;
		float rotZ = 0.0f;

	/* FIN VARIABLES A ANIMAR */

		int finalFrameIndex = NUM_FRAMES_SUPERMAN - 1; // Indice del ultimo frame del arreglo de frames "keyFrame[]"
		int currentFrameIndex = 0; // Indice del primer frame del arreglo de frames "keyFrame[]"

		int maxSteps = 5; // ¿ Interpolacion en cuantos pasos ?
		int currSteps = 0; // ¡ Para ir variando el paso !

		bool play = false; // Mientras este en true se reproduce la animacion
		bool initialPlay = false;

		typedef struct _frame {
			float posX;
			float posXInc;
			float posY;
			float posYInc;
			float posZ;
			float posZInc;
			float rotX;
			float rotXInc;
			float rotY;
			float rotYInc;
			float rotZ;
			float rotZInc;

			float steps;
		} FRAME;

		FRAME keyFrame[NUM_FRAMES_SUPERMAN]; // Arreglo global, aqui se guardan todos los frames

		void resetElements( void );
		void interpolation( void );
};

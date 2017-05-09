#include "Light.h"



Light::Light(MLightEnum mLightEnum, GLenum light)
	: mLight(light)
{

	switch (mLightEnum) {
		case RED_LIGHT:
			gl_diffuse = DEFAULT_RED;
			break;
		case GREEN_LIGHT:
			gl_diffuse = DEFAULT_GREEN;
			break;
		case BLUE_LIGHT:
			gl_diffuse = DEFAULT_BLUE;
			break;
		case WHITE_LIGHT:
			gl_diffuse = DEFAULT_WHITE;
			break;
	}

	glEnable(mLight); //Must tell opengl the light is enabled
}


Light::~Light()
{
}

void Light::Display() {
	//glPushAttrib(GL_ALPHA_BITS);  //stop transparency propogating?

	gl_position[0] = pos[0];
	gl_position[1] = pos[1];
	gl_position[2] = pos[2];

	glPushMatrix();
		glTranslated(gl_position[0], gl_position[1], gl_position[2]);
		glColor3f(1.0f, 1.0f, 1.0f);
		glutSolidSphere(0.5, 16, 16);
	glPopMatrix();
	
	glLightfv(mLight, GL_AMBIENT, gl_ambience);
	glLightfv(mLight, GL_DIFFUSE, gl_diffuse);
	glLightfv(mLight, GL_SPECULAR, gl_specular);
	glLightfv(mLight, GL_POSITION, gl_position);
	glLightfv(mLight, GL_SPOT_DIRECTION, gl_direction);
	glLightfv(mLight, GL_SPOT_CUTOFF, &gl_cutoff);

	glLightf(mLight, GL_CONSTANT_ATTENUATION, 0.5f);
	//glLightf(mLight, GL_LINEAR_ATTENUATION, 0.01f);
	glLightf(mLight, GL_QUADRATIC_ATTENUATION, 0.0001f);

}

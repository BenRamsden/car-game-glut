#include "Light.h"



Light::Light(MLightEnum mLightEnum, GLenum light)
	: mLight(light)
{
	pos[2] = -8.f;
	pos[0] = 30;

	switch (mLightEnum) {
		case RED_LIGHT:
			diffuse = DEFAULT_RED;
			pos[0] -= 3;
			break;
		case GREEN_LIGHT:
			diffuse = DEFAULT_GREEN;
			break;
		case BLUE_LIGHT:
			diffuse = DEFAULT_BLUE;
			pos[0] += 3;
			break;
		case WHITE_LIGHT:
			diffuse = DEFAULT_WHITE;
			break;
	}

	glEnable(mLight); //Must tell opengl the light is enabled
}


Light::~Light()
{
}

void Light::Display() {
	GLfloat position[4] = { pos[0], pos[1], pos[2], 1.0f };  //[3] = 1.0f, directional light not ambient

	glPushMatrix();
	glTranslated(position[0], position[1], position[2]);
	//glColor3f(diffuse[0], diffuse[1], diffuse[2]);
	//glutSolidSphere(0.5, 16, 16);
	glPopMatrix();

	//pos[2] -= 0.01f;
		
	glLightfv(mLight, GL_AMBIENT, ambience);
	glLightfv(mLight, GL_DIFFUSE, diffuse);
	glLightfv(mLight, GL_SPECULAR, specular);
	glLightfv(mLight, GL_POSITION, position);
	glLightfv(mLight, GL_SPOT_DIRECTION, spot_direction);
	glLightfv(mLight, GL_SPOT_CUTOFF, new GLfloat(180.f) );

	//glLightf(mLight, GL_CONSTANT_ATTENUATION, 1.0f);
	//glLightf(mLight, GL_LINEAR_ATTENUATION, 0.5f);
	glLightf(mLight, GL_QUADRATIC_ATTENUATION, 0.01f);
}

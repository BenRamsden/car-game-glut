#include "Light.h"



Light::Light(GLenum light)
	: mLight(light)
{
	glEnable(mLight); //Must tell opengl the light is enabled
}


Light::~Light()
{
}

void Light::Display() {
	GLfloat ambience[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { 0.f, -3.f, pos[2], 1.0f };
	GLfloat spot_direction[] = { 0.0f, 0.0f, -1.0f, 1.0f };

	glPushMatrix();
	glTranslated(position[0], position[1], position[2]);
	glutSolidSphere(0.5, 16, 16);
	glPopMatrix();

	pos[2] -= 0.01f;
		
	glLightfv(mLight, GL_AMBIENT, ambience);
	glLightfv(mLight, GL_DIFFUSE, diffuse);
	glLightfv(mLight, GL_SPECULAR, specular);
	glLightfv(mLight, GL_POSITION, position);
	glLightfv(mLight, GL_SPOT_DIRECTION, spot_direction);
	glLightfv(mLight, GL_SPOT_CUTOFF, new GLfloat(180.f) );

	glLightf(mLight, GL_CONSTANT_ATTENUATION, 1.0f);
	//glLightf(mLight, GL_LINEAR_ATTENUATION, 0.5f);
	glLightf(mLight, GL_QUADRATIC_ATTENUATION, 0.08f);
}

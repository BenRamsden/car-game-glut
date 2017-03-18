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
	glPushMatrix();

	GLfloat ambience[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat diffuse[] = { 1.0f, 1.0f, 0.5f, 1.0f };
	GLfloat specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat position[] = { 0.f, 2.5f, 0.f, 1.0f };

	glLightfv(mLight, GL_AMBIENT, ambience);
	glLightfv(mLight, GL_DIFFUSE, diffuse);
	glLightfv(mLight, GL_SPECULAR, specular);
	glLightfv(mLight, GL_POSITION, position);

	glLightf(mLight, GL_CONSTANT_ATTENUATION, 1.0f);
	glLightf(mLight, GL_LINEAR_ATTENUATION, 0.05f);
	//glLightf(mLight, GL_QUADRATIC_ATTENUATION, 0.08f);

	glPopMatrix();
}

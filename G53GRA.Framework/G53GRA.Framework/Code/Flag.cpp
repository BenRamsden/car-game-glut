#include "Flag.h"
#define _USE_MATH_DEFINES
#include <math.h>

Flag::Flag(GLint texId) :
	texId(texId)
{
}


Flag::~Flag()
{
}

void Flag::Display() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

	glTranslatef(pos[0], pos[1], pos[2]);
	//glRotatef(90, rotation[0], rotation[1], rotation[2]); //TODO: when enabled, dissapears, havent figured out why
	glScalef(scale[0], scale[1], scale[2]);

	//Draw Pole
	glPushMatrix();
	glRotatef(90, -1, 0, 0); //turn pole upright
	glColor3f(0.6f, 0.6f, 0.6f);
	DrawCylinder(0.75, 25);
	glPopMatrix();

	//Draw Flag
	glPushMatrix();
	glTranslatef(0.0f, 12.5f, 0.0f);
	glRotatef(180, 0, 1, 0);
	glScalef(20.f, 12.5f, 10.f);
	DrawFlag();
	glPopMatrix();

	glPopMatrix();
	glPopAttrib();
}


void Flag::DrawFlag() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texId);

	glBegin(GL_QUADS);

	glNormal3f(0, 0, -1);
	glTexCoord2f(1, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(1, 0, 0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, NULL);
}


void Flag::Update(const double& deltaTime) {
	//rotation += 1;
}

void Flag::DrawCylinder(GLfloat radius, GLfloat height)
{
	GLfloat x, y, step = 0.8f;

	//Draw the Cylinder
	glBegin(GL_QUAD_STRIP);
	for (GLfloat angle = 0.0f; angle < 2 * M_PI + step; angle += step) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glNormal3f(cos(angle), sin(angle), 0.0f);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	//Draw the end cap (top)
	glBegin(GL_POLYGON);
	for (GLfloat angle = 0.0f; angle < 2 * M_PI + step; angle += step) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
	}
	glEnd();
}
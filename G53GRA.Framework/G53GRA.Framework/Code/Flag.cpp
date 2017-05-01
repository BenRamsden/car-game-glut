#include "Flag.h"
#define _USE_MATH_DEFINES
#include <math.h>

Flag::Flag()
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
	glRotatef(90, -1, 0, 0); //turn pole upright
	glColor3f(0.6f, 0.6f, 0.6f);
	DrawCylinder(0.75, 25);

	glPopMatrix();
	glPopAttrib();
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
#include "Helpers.h"
#define _USE_MATH_DEFINES
#include <math.h>

Helpers::Helpers()
{
}


Helpers::~Helpers()
{
}

void Helpers::DrawCylinder(GLfloat radius, GLfloat height)
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

void Helpers::DrawCone(GLfloat top_radius, GLfloat bottom_radius, GLfloat height)
{
	glPushMatrix();
	glRotated(90, 1, 0, 0);

	GLfloat top_x, top_y, bottom_x, bottom_y;
	GLfloat step = 0.5f;
	GLfloat target_angle = 2 * M_PI;

	//Draw the Cylinder
	glBegin(GL_QUAD_STRIP);
	for (GLfloat angle = 0.0f; angle < target_angle; angle += step) {

		top_x = top_radius * cos(angle);
		top_y = top_radius * sin(angle);
		bottom_x = bottom_radius  * cos(angle);
		bottom_y = bottom_radius * sin(angle);

		glNormal3f(cos(angle), sin(angle), 0.0f);
		glVertex3f(top_x, top_y, height);
		glVertex3f(bottom_x, bottom_y, 0.0f);
	}

	//Connect last segment to start of first
	glNormal3f(cos(0.0f), sin(0.0f), 0.0f);
	glVertex3f(top_radius * cos(0.0f), top_radius * sin(0.0f), height);
	glVertex3f(bottom_radius  * cos(0.0f), bottom_radius * sin(0.0f), 0.0f);

	glEnd();

	glPopMatrix();
}
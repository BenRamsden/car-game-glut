#include "Lander.h"
#define _USE_MATH_DEFINES
#include <math.h>


Lander::Lander()
{
}


Lander::~Lander()
{
}

struct LanderMesh {
	GLfloat top_radius, bottom_radius, height;
};

void Lander::Display() {
	int mesh_count = 2;
	LanderMesh lander_meshes[] = {
		{ 10, 5, 5 },
		{ 5, 5, 5 }
	};

	glPushMatrix();

	glTranslatef(pos[0], pos[1], pos[2]);

	LanderMesh lander_mesh;

	for(int mesh = 0; mesh < mesh_count; mesh++) {
		lander_mesh = lander_meshes[mesh];

		glTranslatef(0, lander_mesh.height, 0);

		DrawCone(lander_mesh.top_radius, lander_mesh.bottom_radius, lander_mesh.height);
	}

	glPopMatrix();
}

void Lander::DrawCone(GLfloat top_radius, GLfloat bottom_radius, GLfloat height)
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

	//Draw the end cap (top)
	glBegin(GL_POLYGON);
	for (GLfloat angle = 0.0f; angle < target_angle; angle += step) {
		top_x = top_radius * cos(angle);
		top_y = top_radius * sin(angle);
		glVertex3f(top_x, top_y, height);
	}
	glEnd();

	glPopMatrix();
}

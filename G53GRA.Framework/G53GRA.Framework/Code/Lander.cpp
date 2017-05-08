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

	glPushMatrix();

	int mesh_count = 3;
	LanderMesh lander_meshes[] = {
		{ 0, 15, 2 },
		{ 15, 17, 3 },
		{ 17, 8, 15 },
		{ 17, 0, 1 }
	};


	glTranslatef(pos[0], pos[1], pos[2]);

	LanderMesh lander_mesh;

	glPushMatrix();

	for(int mesh = 0; mesh < mesh_count; mesh++) {

		lander_mesh = lander_meshes[mesh];

		glTranslatef(0, lander_mesh.height, 0);  //Stack each part

		DrawCone(lander_mesh.top_radius, lander_mesh.bottom_radius, lander_mesh.height);
	}

	glPopMatrix();

	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glRotatef(i*90, 0, 1, 0);
		glTranslatef(8, 3, 8);
		glRotatef(90, 0, -1, 1);

		DrawCone(1, 3, 15);
		glPopMatrix();

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

	glPopMatrix();
}

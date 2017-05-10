#include "Lander.h"
#include "Helpers.h"

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

		Helpers::DrawCone(lander_mesh.top_radius, lander_mesh.bottom_radius, lander_mesh.height);
	}

	glPopMatrix();

	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glRotatef(i*90, 0, 1, 0);
		glTranslatef(8, 3, 8);
		glRotatef(90, 0, -1, 1);

		Helpers::DrawCone(1, 3, 15);
		glPopMatrix();

	}

	glPopMatrix();

}

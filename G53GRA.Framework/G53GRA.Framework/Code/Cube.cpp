#include "Cube.h"


Cube::Cube()
{
}


Cube::~Cube()
{
}

struct CarMesh {
	float width, y, z;
};

void Cube::Display() {
	glPushMatrix();

	const int numCarMeshes = 16;
	CarMesh carMeshes[numCarMeshes] = {
		{ 15.0f, 0.0f, 0.0f }, //bumper
		{ 15.0f, 2.0f, 0.0f },
		{ 15.0f, 2.0f, -1.0f},
		{ 15.0f, 7.0f, -1.5f }, //back
		{ 15.0f, 7.0f, -5.0f }, //boot
		{ 15.0f, 7.5f, -10.0f },
		{ 15.0f, 13.0f, -15.0f },
		{ 15.0f, 13.0f, -30.0f }, //roof
		{ 15.0f, 6.5f, -37.0f }, //windshield
		{ 15.0f, 6.0f, -48.0f }, //bonnet
		{ 15.0f, 5.0f, -49.0f },
		{ 15.0f, 2.0f, -49.0f }, //grille
		{ 15.0f, 2.0f, -50.0f }, //bumper
		{ 15.0f, 0.0f, -50.0f }
	};

	glTranslated(pos[0], pos[1], pos[2]);

	CarMesh *carMesh;

	//Main car frame
	glBegin(GL_QUAD_STRIP);
	for (int mesh = 0; mesh < numCarMeshes; mesh++) {
		carMesh = &carMeshes[mesh];
		glVertex3f(-carMesh->width / 2, carMesh->y, carMesh->z);
		glVertex3f(+carMesh->width / 2, carMesh->y, carMesh->z);
	}
	glEnd();

	//Right Side
	glBegin(GL_TRIANGLE_STRIP);
	for (int mesh = 0; mesh < numCarMeshes; mesh++) {
		carMesh = &carMeshes[mesh];
		glVertex3f(+carMesh->width / 2, carMesh->y, carMesh->z);
		glVertex3f(+carMesh->width / 2, 0.0f, carMesh->z);
	}
	glEnd();

	//Left Side
	glBegin(GL_TRIANGLE_STRIP);
	for (int mesh = 0; mesh < numCarMeshes; mesh++) {
		carMesh = &carMeshes[mesh];
		glVertex3f(-carMesh->width / 2, 0.0f, carMesh->z);
		glVertex3f(-carMesh->width / 2, carMesh->y, carMesh->z);
	}
	glEnd();

	glPopMatrix();
}


void Cube::Update(const double& deltaTime) {

}

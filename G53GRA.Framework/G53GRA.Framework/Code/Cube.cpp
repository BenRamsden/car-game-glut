#include "Cube.h"


Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::Display() {
	glPushMatrix();

	glTranslated(pos[0], pos[1], pos[2]);
	//glScaled(2.f, 2.f, 2.f);
	//glRotated(-30 + rotation, 1, 0, 0);

	for (int i = 0; i < 4; i++) {
		drawSquare();

		glColor3d(i == 0 ? 1 : 0, i == 1 ? 1 : 0, i == 2 ? 1 : 0);

		glRotated(90, 0, 1, 0);
	}

	glColor3d(0.7, 0.5, 0.0);
	glRotated(90, 0, 0, 1);

	drawSquare();

	glColor3d(0.0, 0.7, 0.5);
	glRotated(180, 0, 0, 1);

	drawSquare();

	glPopMatrix();
}


void Cube::Update(const double& deltaTime) {
	//rotation += 1;
}

void Cube::drawSquare() {
	glBegin(GL_TRIANGLES);

	glVertex3d(-1, -1, -1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 1, -1);

	glVertex3d(-1, 1, 1);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, -1, 1);

	glEnd();
}
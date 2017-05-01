#include "Flag.h"


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

	for (int i = 0; i < 4; i++) {
		drawSquare();

		glRotated(90, 0, 1, 0);
	}

	glRotated(90, 0, 0, 1);
	drawSquare();

	glRotated(180, 0, 0, 1);
	drawSquare();

	glPopMatrix();
	glPopAttrib();
}


void Flag::Update(const double& deltaTime) {
	//rotation += 1;
}

void Flag::drawSquare() {
	glBegin(GL_TRIANGLES);

	glVertex3d(-1, -1, -1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 1, -1);

	glVertex3d(-1, 1, 1);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, -1, 1);

	glEnd();
}
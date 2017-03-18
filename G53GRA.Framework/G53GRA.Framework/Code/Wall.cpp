#include "Wall.h"



Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::Display() {
	static double size = 5;
	
	glPushMatrix();

	glRotated(90, 1, 0, 0);

	glBegin(GL_QUADS);

	glColor3d(0.8, 0.8, 0.8);

	glVertex3d(-size, 0, -size);
	glVertex3d(-size, 0, size);
	glVertex3d(size, 0, size);
	glVertex3d(size, 0, -size);

	glEnd();

	glPopMatrix();
}
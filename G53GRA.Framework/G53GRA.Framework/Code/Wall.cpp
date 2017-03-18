#include "Wall.h"



Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::Display() {
	static double block_size = 1;
	static double offset_size = block_size / 2;
	static double size = 10;
	
	glPushMatrix();

	glTranslated(30, 0, -10);

	glBegin(GL_QUADS);

	/*glNormal3d(0, 0, 1);
	glVertex3d(- offset_size, - offset_size, 0);
	glNormal3d(0, 0, 1);
	glVertex3d(offset_size, - offset_size, 0);
	glNormal3d(0, 0, 1);
	glVertex3d(offset_size, offset_size, 0);
	glNormal3d(0, 0, 1);
	glVertex3d(- offset_size, offset_size, 0);*/

	glNormal3d(0, 0, 1);

	for (int x = -size; x <= size; x+= block_size) {
		for (int y = -size; y <= size; y+= block_size) {
			glVertex3d(x- offset_size, y- offset_size, 0);
			glVertex3d(x+ offset_size, y- offset_size, 0);
			glVertex3d(x+ offset_size, y+ offset_size, 0);
			glVertex3d(x- offset_size, y+ offset_size, 0);
		}
	}

	glEnd();

	glPopMatrix();
}
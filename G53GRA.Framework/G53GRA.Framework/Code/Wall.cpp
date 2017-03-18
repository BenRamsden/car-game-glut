#include "Wall.h"



Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::Display() {
	GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_ambient_color[] = { 0.8f, 0.8f, 0.2f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat no_shininess[] = { 0.0f };
	GLfloat low_shininess[] = { 5.0f };
	GLfloat high_shininess[] = { 100.0f };
	GLfloat mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };

	static double block_size = 1;
	static double offset_size = block_size / 2;
	static double size = 5;
	
	glPushMatrix();

	glTranslated(0, 0, -10);

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
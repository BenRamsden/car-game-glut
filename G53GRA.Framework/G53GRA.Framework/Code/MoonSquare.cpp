#include "MoonSquare.h"

MoonSquare::MoonSquare(GLint surfaceTexId, float block_size)
{
	texId = surfaceTexId;
	this->block_size = block_size;  //breaks if less than 1
}

MoonSquare::~MoonSquare()
{
}

void MoonSquare::Display() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texId);

	int rows = 15, cols = 15;
	int x_off = -rows / 2 * block_size;
	int z_off = +cols / 2 * block_size;
	glTranslatef(pos[0]+x_off, pos[1], pos[2]+z_off);

	glNormal3f(0, 1, 0);

	for (int rowCount = 0; rowCount < rows; rowCount++) {

		for (int colCount = 0; colCount < cols; colCount++) {
			glTranslatef(0, 0, -block_size);
			DrawSquare();
		}

		glTranslatef(block_size, 0, cols*block_size); //next x row, back to beginning z

	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPopAttrib();
}

void MoonSquare::Update(const double& deltaTime) {
	static float maxPos = pos[2] + block_size;

	pos[2] += deltaTime * 15.f;

	if (pos[2] > maxPos) {
		pos[2] -= block_size;
	}
}

void MoonSquare::DrawSquare() {
	float offset_size = block_size / 2;

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3d(-offset_size, 0, +offset_size);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3d(+offset_size, 0, +offset_size);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3d(+offset_size, 0, -offset_size);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3d(-offset_size, 0, -offset_size);
	glEnd();
}
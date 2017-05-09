#include "MoonSquare.h"

MoonSquare::MoonSquare(GLint surfaceTexId, float block_size, WorldProperties *worldProperties)
{
	texId = surfaceTexId;
	this->block_size = block_size;  //breaks if less than 1
	this->worldProperties = worldProperties;
}

MoonSquare::~MoonSquare()
{
}

void MoonSquare::Display() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texId);

	int rows = 22, cols = 22;
	int x_off = -rows / 2 * block_size;
	int z_off = +cols / 2 * block_size;
	glTranslatef(pos[0]+x_off, pos[1], pos[2]+z_off);

	glNormal3f(0, 1, 0);

	for (int rowCount = 0; rowCount < rows; rowCount++) {

		for (int colCount = 0; colCount < cols; colCount++) {
			glTranslatef(0, 0, -block_size);

			float centerDistance = sqrt(pow(colCount-(cols/2), 2) + pow(rowCount-(rows/2), 2));

			if (centerDistance < 12) {
				DrawSquare();
			}
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

	pos[2] += worldProperties->globalVelocity[2]; //delta time pre-accounted for

	if (pos[2] > maxPos) {
		pos[2] -= block_size;
	}
}

void MoonSquare::DrawSquare() {
	float offset_size = block_size / 2;
	float increment = offset_size / 8;
	float range = offset_size * 2;

	glBegin(GL_QUADS);

	for (float x = -offset_size; x <= offset_size; x += increment)
	{
		for (float y = -offset_size; y <= offset_size; y += increment)
		{
			float tex_x = offset_size + x;
			float tex_y = offset_size + y;

			glTexCoord2f(tex_x / range, tex_y / range);
			glVertex3f(x, 0, y);

			glTexCoord2f(tex_x / range, (tex_y + increment) / range);
			glVertex3f(x, 0, y + increment);

			glTexCoord2f((tex_x + increment) / range, (tex_y + increment) / range);
			glVertex3f(x + increment, 0, y + increment);

			glTexCoord2f((tex_x + increment) / range, tex_y / range);
			glVertex3f(x + increment, 0, y);
		}
	}

	glEnd();
}
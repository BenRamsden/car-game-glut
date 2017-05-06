#include "MoonSquare.h"

MoonSquare::MoonSquare(GLint surfaceTexId, float block_size, float total_size)
{
	texId = surfaceTexId;
	this->block_size = block_size;  //breaks if less than 1
	this->total_size = total_size;

	this->offset_size = block_size / 2;
}

MoonSquare::~MoonSquare()
{
}

void MoonSquare::Display() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texId);

	glTranslatef(pos[0], pos[1], pos[2]);

	glNormal3f(0, 1, 0);

	glBegin(GL_QUADS);

	for (int x = -total_size; x <= total_size; x = x + block_size) {
		for (int y = -total_size; y <= total_size; y = y + block_size) {

			glTexCoord2f(1.0f, 0.0f);
			glVertex3d(x - offset_size, 0, y + offset_size);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3d(x + offset_size, 0, y + offset_size);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3d(x + offset_size, 0, y - offset_size);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3d(x- offset_size, 0, y - offset_size);
			
		}
	}

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPopAttrib();
}
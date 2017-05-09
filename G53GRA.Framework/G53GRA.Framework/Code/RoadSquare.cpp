#include "RoadSquare.h"

RoadSquare::RoadSquare(GLint texId, float block_size)
{
	this->texId = texId;
	this->block_size = block_size;

	offset_size = block_size / 2;
}


RoadSquare::~RoadSquare()
{
}

void RoadSquare::Display()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	// Enable Texturing
	glEnable(GL_TEXTURE_2D);

	// Enable setting the colour of the material the cube is made from
	// as well as the material for blending.
	//glEnable(GL_COLOR_MATERIAL);

	// Tell openGL which texture buffer to use
	glBindTexture(GL_TEXTURE_2D, texId);

	glPushMatrix();

	glBegin(GL_QUADS);

	glNormal3f(0, 1, 0);

	//glColor3f(1, 0, 0);

	float increment = offset_size / 8;
	float range = offset_size * 2;

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
			glVertex3f(x + increment, 0, y+increment);

			glTexCoord2f((tex_x + increment) / range, tex_y / range);
			glVertex3f(x+increment, 0, y);
		}
	}

	glEnd();

	glPopMatrix();

	// Stop blending textures and colours
	//glDisable(GL_COLOR_MATERIAL);

	// Bind to the blank buffer to stop ourselves accidentaly
	// using the wrong texture in the next draw call
	glBindTexture(GL_TEXTURE_2D, 0);
	// Stop performing texturing
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
}

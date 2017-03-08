#include "RoadSquare.h"

RoadSquare::RoadSquare(const std::string& filename)
{
	texID = Scene::GetTexture(filename);
}


RoadSquare::~RoadSquare()
{
}

void RoadSquare::Display()
{
	static double size = 5;

	// Enable Texturing
	glEnable(GL_TEXTURE_2D);

	// Enable setting the colour of the material the cube is made from
	// as well as the material for blending.
	//glEnable(GL_COLOR_MATERIAL);

	// Tell openGL which texture buffer to use
	glBindTexture(GL_TEXTURE_2D, texID);

	glPushMatrix();
	glTranslated(0, -5, 0);

	glBegin(GL_QUADS);

	glColor3d(1, 1, 1);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3d(-size, 0, -size);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3d(-size, 0, size);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3d(size, 0, size);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3d(size, 0, -size);

	glEnd();

	glPopMatrix();

	// Stop blending textures and colours
	//glDisable(GL_COLOR_MATERIAL);

	// Bind to the blank buffer to stop ourselves accidentaly
	// using the wrong texture in the next draw call
	glBindTexture(GL_TEXTURE_2D, 0);
	// Stop performing texturing
	glDisable(GL_TEXTURE_2D);
}

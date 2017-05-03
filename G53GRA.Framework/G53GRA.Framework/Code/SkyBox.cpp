#include "SkyBox.h"

SkyBox::SkyBox(GLint texId)
{
	this->texId = texId;
}


SkyBox::~SkyBox()
{
}

void SkyBox::Display() {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

	glDisable(GL_LIGHTING); //stop skybox reacting to lights

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texId);

	glTranslatef(pos[0], pos[1], pos[2]);
	glRotated(180, rotation[0], rotation[1], rotation[2]);
	glScalef(scale[0], scale[1], scale[2]);

	for (int i = 0; i < 4; i++) {
		DrawFace();
		glRotatef(90, 0, 1, 0);
		glTranslatef(0.5f, 0.0f, 0.5f);
	}

	glRotatef(90, 1, 0, 0);
	glTranslatef(0.0f, -0.5f, +0.5f);
	DrawFace();

	glRotatef(180, 1, 0, 0);
	glTranslatef(0.0f, 0.0f, +1.0f);
	DrawFace();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);

	glPopMatrix();
	glPopAttrib();
}

void SkyBox::DrawFace() {
	const float LO = -0.5f;
	const float HI = 0.5f;

	glBegin(GL_QUADS);

	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(LO, HI, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(HI, HI, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(HI, LO, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(LO, LO, 0);
	glEnd();
}

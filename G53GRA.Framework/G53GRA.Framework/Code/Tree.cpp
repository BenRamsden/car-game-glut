#include "Tree.h"
#include <cmath>
#define LEFT  glVertex3d(+1, 0, -1/sqrt(2))
#define RIGHT glVertex3d(-1, 0, -1/sqrt(2))
#define REAR  glVertex3d(0, +1, 1/sqrt(2))
#define PEAK  glVertex3d(0, -1, 1/sqrt(2))
#define TX1 glTexCoord2f(0.5f, 1.0f)
#define TX2 glTexCoord2f(0.0f, 0.0f)
#define TX3 glTexCoord2f(1.0f, 0.0f)

Tree::Tree(const std::string& filename)
{
	texID = Scene::GetTexture(filename);
}


Tree::~Tree()
{
}

void Tree::Display() {
	glPushMatrix();

	// Enable Texturing
	glEnable(GL_TEXTURE_2D);

	// Enable setting the colour of the material the cube is made from
	// as well as the material for blending.
	//glEnable(GL_COLOR_MATERIAL);

	// Tell openGL which texture buffer to use
	glBindTexture(GL_TEXTURE_2D, texID);

	glTranslated(-9, -1, 0);
	glScaled(2.f, 2.f, 2.f);
	glRotated(-30, 1, 0, 0);
	
	glBegin(GL_TRIANGLES);

	glColor3d(0.2, 0.8, 0.2);

	TX1; REAR; TX2; RIGHT; TX3; PEAK;

	TX2; LEFT;  TX1; REAR; TX3; PEAK;

	TX2; LEFT;  TX3; RIGHT; TX1; REAR;

	//base
	RIGHT; LEFT; PEAK;

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


void Tree::Update(const double& deltaTime) {
	//rotation += 1;
}

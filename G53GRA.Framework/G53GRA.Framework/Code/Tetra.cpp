#include "Tetra.h"
#include <cmath>
#define LEFT  glVertex3d(+1, 0, -1/sqrt(2))
#define RIGHT glVertex3d(-1, 0, -1/sqrt(2))
#define REAR  glVertex3d(0, +1, 1/sqrt(2))
#define PEAK  glVertex3d(0, -1, 1/sqrt(2))


Tetra::Tetra()
{
}


Tetra::~Tetra()
{
}

void Tetra::Display() {
	glPushMatrix();

	glTranslated(-3, -1, 335);
	glScaled(2.f, 2.f, 2.f);
	glRotated(-30+rotation, 1, 0, 0);
	
	glBegin(GL_TRIANGLES);

	glColor3d(1, 0.3, 0.3);
	REAR; RIGHT;  PEAK;

	glColor3d(0.3, 1, 0.3);
	LEFT; REAR; PEAK;

	glColor3d(0.3, 0.3, 1);
	LEFT; RIGHT; REAR;

	glColor3d(0.5, 0.5, 0.5);
	RIGHT; LEFT; PEAK;

	glEnd();


	glPopMatrix();
}


void Tetra::Update(const double& deltaTime) {
	rotation += 1;
}

#include "CubeHuman.h"


CubeHuman::CubeHuman() : cube_instance(new Cube())
{
}


CubeHuman::~CubeHuman()
{
}

void CubeHuman::Display() {
	glPushMatrix();
	glTranslated(3, 2, 0);
	glScaled(0.2, 0.2, 0.2);

	//head
	glPushMatrix();
	glScaled(1.5, 1.5, 1.5);
	cube_instance->Display();
	glPopMatrix();

	//neck base
	glTranslated(0, -4, 0);
	cube_instance->Display();

	//left arm
	glPushMatrix();
	SproutLimb(1, 6, 2);
	DropLimb(7, 2);
	glPopMatrix();

	//right arm
	glPushMatrix();
	SproutLimb(1, -6, 2);
	DropLimb(7, 2);
	glPopMatrix();

	//spine
	DropLimb(9, 3);

	//left leg
	glPushMatrix();
	SproutLimb(7, -4, 2);
	DropLimb(7, 2);
	glPopMatrix();

	//right leg
	glPushMatrix();
	SproutLimb(7, 4, 2);
	DropLimb(7, 2);
	glPopMatrix();

	glPopMatrix();
}

void CubeHuman::SproutLimb(double drop, double wide, double segments) {
	for (int i = 0; i < segments; i++) {
		glTranslated(-wide/segments, -drop/segments, 0);
		cube_instance->Display();
	}
}

void CubeHuman::DropLimb(double length, double segments) {
	for (int i = 0; i < segments; i++) {
		glTranslated(0, -length/segments, 0);
		cube_instance->Display();
	}
}

void CubeHuman::Update(const double& deltaTime) {
	//cube_instance->Update(deltaTime);
}
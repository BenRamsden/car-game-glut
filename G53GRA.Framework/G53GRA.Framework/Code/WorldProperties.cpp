#include "WorldProperties.h"



WorldProperties::WorldProperties()
{
}


WorldProperties::~WorldProperties()
{
}

void WorldProperties::Display()
{

}

void WorldProperties::Update(const double& deltaTime)
{

}

void WorldProperties::HandleSpecialKey(int key, int state, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		velocity[2] += 0.4f;
	}

	if (key == GLUT_KEY_DOWN) {
		velocity[2] -= 0.6f;
	}

}
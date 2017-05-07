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
	globalPosition[0] += deltaTime * updateGlobalPosition[0];
	globalPosition[1] += deltaTime * updateGlobalPosition[1];
	globalPosition[2] += deltaTime * updateGlobalPosition[2];

	updateGlobalPosition[0] = 0.0f;
	updateGlobalPosition[1] = 0.0f;
	updateGlobalPosition[2] = 0.0f;


	globalVelocity[0] += deltaTime * updateGlobalVelocity[0];
	globalVelocity[1] += deltaTime * updateGlobalVelocity[1];
	globalVelocity[2] += deltaTime * updateGlobalVelocity[2];

	updateGlobalVelocity[0] = 0.0f;
	updateGlobalVelocity[1] = 0.0f;
	updateGlobalVelocity[2] = 0.0f;

}

void WorldProperties::HandleSpecialKey(int key, int state, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		updateGlobalVelocity[2] = 0.4f;
	}

	if (key == GLUT_KEY_DOWN) {
		updateGlobalVelocity[2] = -0.6f;
	}

	if (key == GLUT_KEY_RIGHT) {
		updateGlobalPosition[0] = -globalVelocity[2] * 600;
	}

	if (key == GLUT_KEY_LEFT) {
		updateGlobalPosition[0] = globalVelocity[2] * 600;
	}

}
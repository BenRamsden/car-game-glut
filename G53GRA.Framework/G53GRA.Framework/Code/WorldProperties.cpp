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

	globalVelocity[0] += deltaTime * updateGlobalVelocity[0];
	globalVelocity[1] += deltaTime * updateGlobalVelocity[1];
	globalVelocity[2] += deltaTime * updateGlobalVelocity[2];

}

void WorldProperties::HandleSpecialKey(int key, int state, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		if(state == 1) updateGlobalVelocity[2] = 0.4f;
		if(state == 0) updateGlobalVelocity[2] = 0.0f;
	}

	if (key == GLUT_KEY_DOWN) {
		if (state == 1) updateGlobalVelocity[2] = -0.6f;
		if (state == 0) updateGlobalVelocity[2] = 0.0f;
	}

	if (key == GLUT_KEY_RIGHT) {
		if (state == 1) updateGlobalPosition[0] = -sqrt(abs(globalVelocity[2])) * 60;
		if (state == 0) updateGlobalPosition[0] = 0.0f;
	}

	if (key == GLUT_KEY_LEFT) {
		if (state == 1) updateGlobalPosition[0] = sqrt(abs(globalVelocity[2])) * 60;
		if (state == 0) updateGlobalPosition[0] = 0.0f;
	}

}
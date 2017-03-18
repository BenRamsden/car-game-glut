#include "RoadManager.h"


RoadManager::RoadManager(const int initRoadCount)
	: roadCount(0)
{
	if (initRoadCount > MAXROADS) {
		printf("RoadManager: initRoadCount > MAXROADS, cannot initialize\n");
		return;
	}

	while (roadCount < initRoadCount) {
		roadSquares[roadCount++] = new RoadSquare("./Textures/Asphalt_Road.bmp");
	}

}


RoadManager::~RoadManager()
{
}


void RoadManager::Display() {
	glPushMatrix();

	glTranslated(0, -10, 20);

	renderCount = 0;

	while (renderCount < roadCount) {
		glTranslated(0, 0, -10);
		roadSquares[renderCount++]->Display();
	}

	glPopMatrix();
}

void RoadManager::Update(const double& deltaTime) {

}

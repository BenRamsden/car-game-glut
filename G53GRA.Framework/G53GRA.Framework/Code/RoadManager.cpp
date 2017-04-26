#include "RoadManager.h"


RoadManager::RoadManager(GLint roadTextureId, int initRoadCount, int block_size)
	: roadCount(0)
{
	this->block_size = block_size;

	while (roadCount < initRoadCount) {
		roadSquares[roadCount++] = new RoadSquare(roadTextureId, block_size);
	}

}


RoadManager::~RoadManager()
{
}


void RoadManager::Display() {
	glPushMatrix();

	glTranslated(pos[0], pos[1], pos[2]);

	renderCount = 0;

	while (renderCount < roadCount) {
		glTranslated(0, 0, -block_size);
		roadSquares[renderCount++]->Display();
	}

	glPopMatrix();
}

void RoadManager::Update(const double& deltaTime) {

}

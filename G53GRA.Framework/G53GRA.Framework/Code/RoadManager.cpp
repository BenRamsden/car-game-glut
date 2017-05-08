#include "RoadManager.h"


RoadManager::RoadManager(GLint roadTextureId, int initRoadCount, int block_size, WorldProperties *worldProperties)
{
	this->block_size = block_size;
	this->roadRows = 3;
	this->worldProperties = worldProperties;
	this->roadCount = initRoadCount;

	roadSquare = new RoadSquare(roadTextureId, block_size);
}


RoadManager::~RoadManager()
{
}


void RoadManager::Display() {
	glPushMatrix();

	float initOffset = block_size*(roadRows - 1) / 2.0f;
	glTranslated(pos[0]- initOffset, pos[1], pos[2]);

	for (int rowCount = 0; rowCount < roadRows; rowCount++) {
		
		for (int renderCount = 0; renderCount < roadCount; renderCount++) {
			glTranslated(0, 0, -block_size);
			roadSquare->Display();
		}

		glTranslated(block_size, 0, block_size*roadCount); //next x row, back to beginning z
	}

	glPopMatrix();
}

void RoadManager::Update(const double& deltaTime) {
	static float maxPos = pos[2] + block_size;

	pos[0] += worldProperties->globalVelocity[0];

	pos[2] += worldProperties->globalVelocity[2]; //delta time pre-accounted for

	if (pos[2] > maxPos) {
		pos[2] -= block_size;
	}

}

#include "RoadManager.h"


RoadManager::RoadManager(GLint roadTextureId, int initRoadCount, int block_size)
	: roadCount(0)
{
	this->block_size = block_size;
	this->roadRows = 3;

	while (roadCount < initRoadCount) {
		roadSquares[roadCount++] = new RoadSquare(roadTextureId, block_size);
	}

}


RoadManager::~RoadManager()
{
}


void RoadManager::Display() {
	glPushMatrix();

	float initOffset = block_size*(roadRows - 1) / 2.0f;
	glTranslated(pos[0]- initOffset, pos[1], pos[2]);

	for (int rowCount = 0; rowCount < roadRows; rowCount++) {
		
		glPushMatrix();
		for (int renderCount = 0; renderCount < roadCount; renderCount++) {
			glTranslated(0, 0, -block_size);
			roadSquares[renderCount]->Display();
		}
		glPopMatrix();

		glTranslated(block_size, 0, 0);
	}


	glPopMatrix();
}

void RoadManager::Update(const double& deltaTime) {
	static float maxPos = pos[2] + block_size;

	pos[2] += deltaTime * 15.f;

	if (pos[2] > maxPos) {
		pos[2] -= block_size;
	}

}

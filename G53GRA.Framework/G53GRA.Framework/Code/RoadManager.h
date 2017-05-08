#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "RoadSquare.h"
#include "WorldProperties.h"
#define MAXROADS 25

class RoadManager :
	public DisplayableObject,
	public Animation
{
public:
	RoadManager(GLint roadTextureId, int initRoadCount, int block_size, WorldProperties *worldProperties);
	virtual ~RoadManager();

	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	int roadCount;
	int roadRows;
	RoadSquare* roadSquare;

	float block_size;
	WorldProperties *worldProperties;

};


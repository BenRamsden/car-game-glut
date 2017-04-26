#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "RoadSquare.h"
#define MAXROADS 25

class RoadManager :
	public DisplayableObject,
	public Animation
{
public:
	RoadManager(GLint roadTextureId, int initRoadCount, int block_size);
	virtual ~RoadManager();

	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	int roadCount;
	int renderCount;
	RoadSquare* roadSquares[MAXROADS];

	float block_size;

};


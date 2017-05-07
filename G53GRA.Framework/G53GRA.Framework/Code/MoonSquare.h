#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "WorldProperties.h"

class MoonSquare :
	public DisplayableObject,
	public Animation
{
public:
	MoonSquare(GLint surfaceTexId, float block_size, WorldProperties *worldProperties);
	virtual ~MoonSquare();
	virtual void Display();
	virtual void Update(const double& deltaTime);
	GLint texId;

private:
	float block_size;
	void DrawSquare();
	WorldProperties *worldProperties;
};


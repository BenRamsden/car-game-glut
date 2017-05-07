#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class MoonSquare :
	public DisplayableObject,
	public Animation
{
public:
	MoonSquare(GLint surfaceTexId, float block_size);
	virtual ~MoonSquare();
	virtual void Display();
	virtual void Update(const double& deltaTime);
	GLint texId;

private:
	float block_size;
	void DrawSquare();
};


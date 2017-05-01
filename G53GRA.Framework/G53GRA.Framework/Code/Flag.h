#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
class Flag :
	public DisplayableObject,
	public Animation
{
public:
	Flag();
	virtual ~Flag();
	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	void DrawCylinder(GLfloat radius, GLfloat height);
};


#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
class Flag :
	public DisplayableObject,
	public Animation
{
public:
	Flag(GLint texId);
	virtual ~Flag();
	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	void DrawCylinder(GLfloat radius, GLfloat height);
	void DrawFlag();
	GLint texId;
};


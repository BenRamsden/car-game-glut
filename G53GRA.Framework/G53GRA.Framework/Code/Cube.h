#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "WorldProperties.h"
#include "Light.h"

class Cube :
	public DisplayableObject,
	public Animation
{
public:
	Cube(WorldProperties *worldProperties);
	virtual ~Cube();
	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	void Cube::DrawCylinder(GLfloat radius, GLfloat height);
	float wheelXRotation = 0.0f;
	float wheelYRotation = 0.0f;
	WorldProperties *worldProperties;

	Light *light1;
	Light *light2;
};


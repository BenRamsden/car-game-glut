#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "WorldProperties.h"
#include "Light.h"

class Car :
	public DisplayableObject,
	public Animation
{
public:
	Car(WorldProperties *worldProperties);
	virtual ~Car();
	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	void Car::DrawCylinder(GLfloat radius, GLfloat height);
	float wheelXRotation = 0.0f;
	float wheelYRotation = 0.0f;
	WorldProperties *worldProperties;

	Light *light1;
	Light *light2;
};


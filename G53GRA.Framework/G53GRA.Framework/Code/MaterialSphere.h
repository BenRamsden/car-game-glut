#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class MaterialSphere :
	public DisplayableObject,
	public Animation
{
public:
	MaterialSphere(float baseSpeed, double period);
	virtual ~MaterialSphere();
	virtual void Display();
	virtual void Update(const double& deltaTime);
	void RandomReset();

private:
	float baseSpeed, speedX, speedY, speedZ;
	double period, period_timer;
	float relativeX, relativeY, relativeZ;
};
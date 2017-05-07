#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class WorldProperties:
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	WorldProperties();
	~WorldProperties();
	virtual void Display();
	virtual void Update(const double& deltaTime);

	virtual void HandleSpecialKey(int key, int state, int x, int y);

	float globalVelocity[3] = { 0.f, 0.f, 0.f };
	float globalPosition[3] = { 0.f, 0.f, 0.f };

private:
	float updateGlobalVelocity[3] = { 0.f, 0.f, 0.f };
	float updateGlobalPosition[3] = { 0.f, 0.f, 0.f };
};


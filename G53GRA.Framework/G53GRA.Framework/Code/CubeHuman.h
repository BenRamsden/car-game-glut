#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "Cube.h"

class CubeHuman :
	public DisplayableObject,
	public Animation
{
public:
	CubeHuman();
	virtual ~CubeHuman();
	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	Cube *cube_instance;
	void CubeHuman::DropLimb(double length, double segments);
	void CubeHuman::SproutLimb(double drop, double wide, double segments);
};


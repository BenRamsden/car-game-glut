#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Tetra :
	public DisplayableObject,
	public Animation
{
public:
	Tetra();
	virtual ~Tetra();

	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	double rotation = 0;
};


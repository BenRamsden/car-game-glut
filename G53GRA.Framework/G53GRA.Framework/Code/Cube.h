#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
class Cube :
	public DisplayableObject,
	public Animation
{
public:
	Cube();
	virtual ~Cube();
	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	double rotation = 0;
	void drawSquare();
};


#pragma once
#include "DisplayableObject.h"
#include <string>

class RoadSquare :
	public DisplayableObject
{
public:
	RoadSquare(GLint texId, float block_size);
	virtual ~RoadSquare();
	virtual void Display();

private:
	GLint texId;
	float block_size;
	float offset_size;
};


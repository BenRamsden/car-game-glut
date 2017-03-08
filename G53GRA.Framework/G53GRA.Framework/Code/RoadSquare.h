#pragma once
#include "DisplayableObject.h"
#include <string>

class RoadSquare :
	public DisplayableObject
{
public:
	RoadSquare(const std::string& filename);
	virtual ~RoadSquare();
	virtual void Display();

private:
	GLint texID;
};


#pragma once
#include "DisplayableObject.h"

class MoonSquare :
	public DisplayableObject
{
public:
	MoonSquare(GLint surfaceTexId, float block_size, float total_size);
	virtual ~MoonSquare();
	virtual void Display();
	GLint texId;

private:
	float block_size;
	float offset_size;
	float total_size;
};


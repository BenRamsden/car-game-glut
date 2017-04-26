#pragma once
#include "DisplayableObject.h"

class Wall :
	public DisplayableObject
{
public:
	Wall(GLint surfaceTexId, float block_size, float total_size);
	virtual ~Wall();
	virtual void Display();
	GLint texId;

private:
	float block_size;
	float offset_size;
	float total_size;
};


#pragma once
#include "DisplayableObject.h"

class TexturedSquare :
	public DisplayableObject
{
public:
	TexturedSquare(GLint surfaceTexId, float block_size, float total_size);
	virtual ~TexturedSquare();
	virtual void Display();
	GLint texId;

private:
	float block_size;
	float offset_size;
	float total_size;
};


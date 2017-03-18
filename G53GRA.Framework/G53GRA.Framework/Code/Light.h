#pragma once
#include "DisplayableObject.h"
class Light :
	public DisplayableObject
{
public:
	Light(GLenum light);
	virtual ~Light();
	virtual void Display();

private:

	GLenum mLight;
};


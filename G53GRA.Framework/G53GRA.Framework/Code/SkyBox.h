#pragma once
#include "DisplayableObject.h"
class SkyBox :
	public DisplayableObject
{
public:
	SkyBox(GLint texId);
	virtual ~SkyBox();
	void Display();

private:
	GLint texId;
	void DrawFace();
};


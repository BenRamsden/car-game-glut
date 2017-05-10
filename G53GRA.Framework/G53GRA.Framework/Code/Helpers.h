#pragma once
#include "DisplayableObject.h"

class Helpers
{
public:
	Helpers();
	~Helpers();
	static void DrawCylinder(GLfloat radius, GLfloat height);
	static void DrawCone(GLfloat top_radius, GLfloat bottom_radius, GLfloat height);
	static void DrawTexturedCone(GLfloat top_radius, GLfloat bottom_radius, GLfloat height, GLint texId);

};


#pragma once
#include "DisplayableObject.h"
class Light :
	public DisplayableObject
{
public:
	enum MLightEnum { RED_LIGHT, GREEN_LIGHT, BLUE_LIGHT, WHITE_LIGHT };

	Light(MLightEnum mLightEnum, GLenum light);
	virtual ~Light();
	virtual void Display();

private:
	GLenum mLight;

	GLfloat DEFAULT_RED[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat DEFAULT_GREEN[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
	GLfloat DEFAULT_BLUE[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat DEFAULT_WHITE[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat ambience[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat* diffuse;
	GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat spot_direction[4] = { 0.0f, 0.0f, -1.0f, 1.0f };
};


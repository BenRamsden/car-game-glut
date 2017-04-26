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

	GLfloat* gl_diffuse;
	GLfloat DEFAULT_RED[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat DEFAULT_GREEN[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
	GLfloat DEFAULT_BLUE[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat DEFAULT_WHITE[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat gl_position[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat gl_ambience[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat gl_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//GLfloat gl_direction[4] = { 0.0f, -1.0f, 0.0f, 1.0f }; //{ 0.0f, 0.0f, -1.0f, 1.0f };
	//GLfloat gl_cutoff = 180.0f;

};


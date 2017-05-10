#pragma once
#include "C:\GitHub\G53GRA_Coursework\G53GRA.Framework\G53GRA.Framework\Framework\Interface\DisplayableObject.h"
class Tree :
	public DisplayableObject
{
public:
	Tree(GLint barkTexId, GLint leafTexId);
	virtual ~Tree();
	virtual void Display();
private:
	void Tree::DrawSection(GLfloat top_radius, GLfloat bottom_radius, GLfloat height, GLint texId);
	GLint barkTexId, leafTexId;

};


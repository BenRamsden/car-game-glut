#include "Tree.h"
#include "Helpers.h"


Tree::Tree(GLint barkTexId, GLint leafTexId) :
	barkTexId(barkTexId), leafTexId(leafTexId)
{
}


Tree::~Tree()
{
}

void Tree::Display()
{
	glPushMatrix();

	glTranslatef(pos[0], pos[1], pos[2]);

	Tree::DrawSection(5, 5, 15, barkTexId);

	Tree::DrawSection(5, 15, 5, leafTexId);

	Tree::DrawSection(15, 20, 5, leafTexId);

	Tree::DrawSection(20, 22, 5, leafTexId);

	Tree::DrawSection(22, 19, 10, leafTexId);

	Tree::DrawSection(19, 14, 10, leafTexId);

	Tree::DrawSection(14, 10, 10, leafTexId);

	Tree::DrawSection(10, 5, 10, leafTexId);

	Tree::DrawSection(5, 0, 5, leafTexId);

	glPopMatrix();
}

void Tree::DrawSection(GLfloat top_radius, GLfloat bottom_radius, GLfloat height, GLint texId) {
	glTranslatef(0, height, 0);
	Helpers::DrawTexturedCone(top_radius, bottom_radius, height, texId);
}
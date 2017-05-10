#include "TreeSpawner.h"



TreeSpawner::TreeSpawner(WorldProperties *worldProperties, GLint barkTexId, GLint leafTexId) :
	worldProperties(worldProperties)
{
	tree = new Tree(barkTexId, leafTexId);

	int mid_point = NUM_TREES / 2;

	for (int t = 0; t < NUM_TREES; t++) {
		if (t < mid_point) {
			treeProperties[t] = { -80, -30, -150 * (float)t };
		}
		else {
			treeProperties[t] = { +80, -30, -150 * ((float)t - mid_point) };
		}
	}
}


TreeSpawner::~TreeSpawner()
{
}

void TreeSpawner::Display()
{
	for (int t = 0; t < NUM_TREES; t++) {
		glPushMatrix();
		glTranslatef(treeProperties[t].x, treeProperties[t].y, treeProperties[t].z);
		tree->Display();
		glPopMatrix();
	}
}

void TreeSpawner::Update(const double& deltaTime)
{
	for (int t = 0; t < NUM_TREES; t++) {
		treeProperties[t].x += worldProperties->globalVelocity[0];
		treeProperties[t].z += worldProperties->globalVelocity[2];

		if (treeProperties[t].z > 200.f) {
			ResetTree(t);
		}
	}
}

void TreeSpawner::ResetTree(int t) {
	static int mid_point = NUM_TREES / 2;
	treeProperties[t].z += -150 * mid_point;
}
#include "TreeSpawner.h"



TreeSpawner::TreeSpawner(WorldProperties *worldProperties, GLint barkTexId, GLint leafTexId) :
	worldProperties(worldProperties)
{
	tree = new Tree(barkTexId, leafTexId);

	for (int t = 0; t < NUM_TREES; t++) {

	}
}


TreeSpawner::~TreeSpawner()
{
}

void TreeSpawner::Display()
{
	tree->Display();
}

void TreeSpawner::Update(const double& deltaTime)
{
}
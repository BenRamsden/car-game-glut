#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "WorldProperties.h"
#include "Tree.h"

class TreeSpawner :
	public DisplayableObject,
	public Animation
{
public:
	TreeSpawner(WorldProperties *worldProperties, GLint barkTexId, GLint leafTexId);
	virtual ~TreeSpawner();
	virtual void Display();
	virtual void TreeSpawner::Update(const double& deltaTime);

private:
	WorldProperties *worldProperties;
	Tree *tree;

	static const int NUM_TREES = 20;
	struct TreeProperty {
		float x, y, z;
	} treeProperties[NUM_TREES];

	void ResetTree(int t);

};


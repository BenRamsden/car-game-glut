#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Tree :
	public DisplayableObject,
	public Animation
{
public:
	Tree(const std::string& filename);
	virtual ~Tree();

	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	GLint texID;
};


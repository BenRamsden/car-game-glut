#pragma once
#include "DisplayableObject.h"

class Wall :
	public DisplayableObject
{
public:
	Wall();
	virtual ~Wall();
	virtual void Display();
};


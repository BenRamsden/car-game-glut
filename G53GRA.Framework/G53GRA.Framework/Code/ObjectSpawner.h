#pragma once
#include "DisplayableObject.h"
#include "WorldProperties.h"
#define MAX_COLLISION_OBJECTS 10

class ObjectSpawner :
	public DisplayableObject
{
public:
	ObjectSpawner(WorldProperties *worldProperties, GLint flagTex);
	virtual ~ObjectSpawner();
	virtual void Display();
	virtual void Update(const double& deltaTime);
private:
	WorldProperties *worldProperties;

	struct CollisionProperties {
		float x, y, z;
		bool enabled;
	} collisionProperties[MAX_COLLISION_OBJECTS];
	
	DisplayableObject *collisionObjects[MAX_COLLISION_OBJECTS];
	int collisionObjectCount = 0;

	void resetCollisionProperty(int index);
};


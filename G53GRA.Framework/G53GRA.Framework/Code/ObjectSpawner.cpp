#include "ObjectSpawner.h"
#include "Lander.h"

ObjectSpawner::ObjectSpawner(WorldProperties *worldProperties)
{
	this->worldProperties = worldProperties;
	for (int i = 0; i < MAX_COLLISION_OBJECTS; i++) {
		collisionObjects[i] = new Lander();
		float x_range = (MAX_COLLISION_OBJECTS-1) * 9.0f;
		collisionProperties[i] = { i * 9.0f - (x_range / 2), -12.0f, -2000.0f };
	}

}


ObjectSpawner::~ObjectSpawner()
{
}

void ObjectSpawner::Display()
{
	for (int i = 0; i < MAX_COLLISION_OBJECTS; i++) {
		float random = ((float)rand()) / RAND_MAX;
		//printf("%f\n", random);

		if (random < 0.00003f * worldProperties->globalVelocity[2]) {
			collisionProperties[i].enabled = true;
		}

		glPushMatrix();
		glTranslatef(collisionProperties[i].x, collisionProperties[i].y, collisionProperties[i].z);
		collisionProperties[i].x += worldProperties->globalVelocity[0];

		if (collisionProperties[i].enabled) {
			collisionProperties[i].z += worldProperties->globalVelocity[2];
			collisionObjects[i]->Display();
		}

		glPopMatrix();
		
	}
}

void ObjectSpawner::Update(const double& deltaTime)
{
	
}
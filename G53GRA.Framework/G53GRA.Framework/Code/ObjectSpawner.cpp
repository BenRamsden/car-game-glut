#include "ObjectSpawner.h"
#include "Lander.h"

ObjectSpawner::ObjectSpawner(WorldProperties *worldProperties)
{
	this->worldProperties = worldProperties;
	for (int i = 0; i < MAX_COLLISION_OBJECTS; i++) {
		collisionObjects[i] = new Lander();
		resetCollisionProperty(i);
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

		if (collisionProperties[i].z > 200.0f) {
			resetCollisionProperty(i);
		}

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

void ObjectSpawner::resetCollisionProperty(int index) {
	collisionProperties[index] = { index * 9.0f - (((MAX_COLLISION_OBJECTS - 1) * 9.0f) / 2), -12.0f, -1300.f, false };
}
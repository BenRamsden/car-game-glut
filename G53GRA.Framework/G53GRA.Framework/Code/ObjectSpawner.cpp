#include "ObjectSpawner.h"
#include "Lander.h"
#include "Flag.h"

ObjectSpawner::ObjectSpawner(WorldProperties *worldProperties, GLint flagTex)
{
	this->worldProperties = worldProperties;
	for (int index = 0; index < MAX_COLLISION_OBJECTS; index++) {

		float random = ((float)rand()) / RAND_MAX;
		//printf("%f\n", random);

		if (random < 0.5f) {
			collisionObjects[index] = new Lander();
		}
		else {
			collisionObjects[index] = new Flag(flagTex);
		}

		collisionProperties[index].x = index * 9.0f - (((MAX_COLLISION_OBJECTS - 1) * 9.0f) / 2);
		collisionProperties[index].y = -12.0f;
		resetCollisionProperty(index);

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

		//collision detection
		float x_distance = abs(collisionProperties[i].x - pos[0]);
		float z_distance = abs(collisionProperties[i].z - pos[2]);
		float center_distance = sqrt(pow(x_distance, 2) + pow(z_distance, 2));

		if (center_distance < 20.f) {
			worldProperties->globalVelocity[0] = 0.0f;
			worldProperties->globalVelocity[2] = 0.0f;
			resetCollisionProperty(i);
		}

		glPopMatrix();
		
	}
}

void ObjectSpawner::Update(const double& deltaTime)
{
	
}

void ObjectSpawner::resetCollisionProperty(int index) {
	collisionProperties[index].z = -1300.f;
	collisionProperties[index].enabled = false;
}
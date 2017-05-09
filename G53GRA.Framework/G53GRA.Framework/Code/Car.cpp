#define _USE_MATH_DEFINES
#include <math.h>
#include "Car.h"

Car::Car(WorldProperties *worldProperties)
{
	this->worldProperties = worldProperties;

	light1 = new Light(Light::RED_LIGHT, GL_LIGHT1);
	light1->position(5, 4, -49);

	light2 = new Light(Light::GREEN_LIGHT, GL_LIGHT2);
	light2->position(-5, 4, -49);
}


Car::~Car()
{
}

struct CarMesh {
	float width, y, z;
};

void Car::Display() {
	glPushMatrix();

	glTranslated(pos[0], pos[1] + 3.5f, pos[2]);
	glRotatef(wheelYRotation / 3, 0, 1, 0); //make car turn with wheels

	light1->Display();
	light2->Display();

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//glEnable(GL_COLOR_MATERIAL);

	//MATERIALS
	GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_ambient_color[] = { 0.8f, 0.8f, 0.2f, 1.0f };
	GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat no_shininess[] = { 0.0f };
	GLfloat low_shininess[] = { 5.0f };
	GLfloat high_shininess[] = { 100.0f };
	GLfloat mat_emission[] = { 0.2f, 0.2f, 0.2f, 0.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glColor3f(0.4f, 0.4f, 0.4f);

	const float carWidth = 18.0f;
	const float wheelXOffset = 6.0f;
	const float frontWheelZOffset = -39.0f;
	const float backWheelZOffset = -10.0f;
	const float wheelSize = 4.0f;

	const int numCarMeshes = 16;
	CarMesh carMeshes[numCarMeshes] = {
		{ carWidth, 0.0f, 0.0f }, //bumper
		{ carWidth, 2.0f, 0.0f },
		{ carWidth, 2.0f, -1.0f},
		{ carWidth, 7.0f, -1.5f }, //back
		{ carWidth, 7.0f, -5.0f }, //boot
		{ carWidth, 7.5f, -10.0f },
		{ carWidth, 13.0f, -15.0f },
		{ carWidth, 13.0f, -30.0f }, //roof
		{ carWidth, 6.5f, -37.0f }, //windshield
		{ carWidth, 6.0f, -48.0f }, //bonnet
		{ carWidth, 5.0f, -49.0f },
		{ carWidth, 2.0f, -49.0f }, //grille
		{ carWidth, 2.0f, -50.0f }, //bumper
		{ carWidth, 0.0f, -50.0f }
	};

	CarMesh *carMesh;

	glColor3f(0.7f, 0.1f, 0.1f);
	//Main car frame
	glBegin(GL_QUAD_STRIP);
	glNormal3f(0, 1, 0);
	for (int mesh = 0; mesh < numCarMeshes; mesh++) {
		carMesh = &carMeshes[mesh];
		glVertex3f(-carMesh->width / 2, carMesh->y, carMesh->z);
		glVertex3f(+carMesh->width / 2, carMesh->y, carMesh->z);
	}
	glEnd();

	glColor3f(0.5f, 0.1f, 0.1f);
	//Right Side
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3f(1, 0, 0);
	for (int mesh = 0; mesh < numCarMeshes; mesh++) {
		carMesh = &carMeshes[mesh];
		glVertex3f(+carMesh->width / 2, carMesh->y, carMesh->z);
		glVertex3f(+carMesh->width / 2, 0.0f, carMesh->z);
	}
	glEnd();

	glColor3f(0.5f, 0.1f, 0.1f);
	//Left Side
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3f(-1, 0, 0);
	for (int mesh = 0; mesh < numCarMeshes; mesh++) {
		carMesh = &carMeshes[mesh];
		glVertex3f(-carMesh->width / 2, 0.0f, carMesh->z);
		glVertex3f(-carMesh->width / 2, carMesh->y, carMesh->z);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	//Back right tyre
	glPushMatrix();
		glTranslatef(wheelXOffset, 0.0f, backWheelZOffset);
		glRotatef(wheelXRotation, -1, 0, 0);
		glRotatef(90, 0, 1, 0);
		DrawCylinder(wheelSize, wheelSize);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);
	//Front right tyre
	glPushMatrix();
		glTranslatef(wheelXOffset, 0.0f, frontWheelZOffset);
		glRotatef(wheelYRotation, 0, 1, 0);
		glRotatef(wheelXRotation, -1, 0, 0);
		glRotatef(90, 0, 1, 0);
		DrawCylinder(wheelSize, wheelSize);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);
	//Back left tyre
	glPushMatrix();
		glTranslatef(-wheelXOffset, 0.0f, backWheelZOffset);
		glRotatef(wheelXRotation, -1, 0, 0);
		glRotatef(90, 0, -1, 0);
		DrawCylinder(wheelSize, wheelSize);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);
	//Front left tyre
	glPushMatrix();
		glTranslatef(-wheelXOffset, 0.0f, frontWheelZOffset);
		glRotatef(wheelYRotation, 0, 1, 0);
		glRotatef(wheelXRotation, -1, 0, 0);
		glRotatef(90, 0, -1, 0);
		DrawCylinder(wheelSize, wheelSize);
	glPopMatrix();

	glPopMatrix();
	glPopAttrib();
}


void Car::Update(const double& deltaTime) {
	wheelXRotation += worldProperties->globalVelocity[2] * 7;

	if (worldProperties->globalVelocity[2] == 0.0f) {
		wheelYRotation = 0;
	}
	else {
		wheelYRotation = worldProperties->globalVelocity[0] / worldProperties->globalVelocity[2] * 60;
	}

	if (wheelYRotation > 45.0f) wheelYRotation = 45.0f;
	if (wheelYRotation < -45.0f) wheelYRotation = -45.0f;
}

void Car::DrawCylinder (GLfloat radius, GLfloat height)
{
	GLfloat x, y;
	GLfloat step = 0.5f;
	GLfloat target_angle = 2 * M_PI;

	//Draw the Cylinder
	glBegin(GL_QUAD_STRIP);
	for (GLfloat angle = 0.0f; angle < target_angle; angle += step) {

		x = radius * cos(angle);
		y = radius * sin(angle);

		glNormal3f(cos(angle), sin(angle), 0.0f);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0f);
	}

	//Connect last segment to start of first
	glNormal3f(cos(0.0f), sin(0.0f), 0.0f);
	glVertex3f(radius * cos(0.0f), radius * sin(0.0f), height);
	glVertex3f(radius * cos(0.0f), radius * sin(0.0f), 0.0f);
	glEnd();

	//Draw the end cap
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0f, height);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	for (GLfloat angle = 0.0f; angle < target_angle; angle += step) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
	}
	//Connect last segment to start of first
	glVertex3f(radius * cos(0.0f), radius * sin(0.0f), height);

	glEnd();
}
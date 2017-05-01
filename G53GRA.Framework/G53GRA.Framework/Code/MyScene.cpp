#include "MyScene.h"
#include "RoadManager.h"
#include "TexturedSquare.h"
#include "TexturedSphere.h"
#include "MaterialSphere.h"
#include "Light.h"
#include "Flag.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(1.0f));

	//Translate, Rotate, Scale (T * R * S)

	LightShow(0,40,-100,60);

	MaterialSphere *materialSphere = new MaterialSphere();
	materialSphere->position(0, -13, -100);
	materialSphere->size(3, 3, 3);
	AddObjectToScene(materialSphere);

	Light *light0 = new Light(Light::WHITE_LIGHT, GL_LIGHT0);
	light0->position(0, 50, 0);
	//AddObjectToScene(light0);

	TexturedSquare *moon_surface = new TexturedSquare(Scene::GetTexture("./Textures/Moon_Surface2.bmp"), 50, 200);
	moon_surface->orientation(-1, 0, 0);
	moon_surface->position(0, -17, -100);
	AddObjectToScene(moon_surface);

	RoadManager *roadManager = new RoadManager(Scene::GetTexture("./Textures/Asphalt_Road.bmp"), 15, 45);
	roadManager->position(0, -16, 150);
	AddObjectToScene(roadManager);

	TexturedSphere *earth = new TexturedSphere(Scene::GetTexture("./Textures/alpha_map.bmp"), Scene::GetTexture("./Textures/alpha_clouds.bmp"));
	earth->position(300, 500, -1500);
	earth->size(100.0f);
	earth->SetResolution(2);
	AddObjectToScene(earth);

	//TODO Apollo 13 moon lander

	//TODO American Flag
	Flag *flag = new Flag();
	flag->position(-20, -16, -50);
	AddObjectToScene(flag);

	//TODO Stars Sky box/sphere
}

void MyScene::Projection()
{
	gluPerspective(static_cast<GLdouble>(60.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight), static_cast<GLdouble>(1.0), static_cast<GLdouble>(2000.0));
}

void MyScene::LightShow(float x, float y, float z, float x_step) {
	x -= x_step;

	Light *light1 = new Light(Light::RED_LIGHT, GL_LIGHT1);
	light1->position(x, y, z);
	AddObjectToScene(light1);

	x += x_step;

	Light *light2 = new Light(Light::GREEN_LIGHT, GL_LIGHT2);
	light2->position(x, y, z);
	AddObjectToScene(light2);

	x += x_step;

	Light *light3 = new Light(Light::BLUE_LIGHT, GL_LIGHT3);
	light3->position(x, y, z);
	AddObjectToScene(light3);
}

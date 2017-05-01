#include "MyScene.h"
#include "RoadManager.h"
#include "Wall.h"
#include "Light.h"
#include "MaterialTest.h"
#include "TexturedSphere.h"
#include "Flag.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(static_cast<GLclampf>(0.2f), static_cast<GLclampf>(0.2f), static_cast<GLclampf>(0.2f), static_cast<GLclampf>(1.0f));

	//Translate, Rotate, Scale (T * R * S)

	MaterialTest *materialTest = new MaterialTest();
	materialTest->position(+20, -16, -50);
	materialTest->orientation(0, -1, 0);
	materialTest->size(3, 3, 3);
	AddObjectToScene(materialTest);

	Light *light1 = new Light(Light::WHITE_LIGHT, GL_LIGHT0);
	light1->position(0, 50, 0);
	AddObjectToScene(light1);

	Wall *moon_surface = new Wall(Scene::GetTexture("./Textures/Moon_Surface2.bmp"), 50, 200);
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

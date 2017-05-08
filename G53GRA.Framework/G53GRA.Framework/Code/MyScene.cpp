#include "MyScene.h"
#include "RoadManager.h"
#include "MoonSquare.h"
#include "TexturedSphere.h"
#include "MaterialSphere.h"
#include "Light.h"
#include "Flag.h"
#include "SkyBox.h"
#include "Lander.h"
#include "WorldProperties.h"
#include "Cube.h"
#include "ObjectSpawner.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(1.0f));

	//Translate, Rotate, Scale (T * R * S)

	WorldProperties *worldProperties = new WorldProperties();	
	AddObjectToScene(worldProperties);

	ObjectSpawner *objectSpawner = new ObjectSpawner(worldProperties);
	AddObjectToScene(objectSpawner);

	Cube *cube = new Cube(worldProperties);
	cube->position(0, -16, -30);
	AddObjectToScene(cube);

	Light *light1 = new Light(Light::RED_LIGHT, GL_LIGHT1);
	light1->position(5, -10, -80);
	AddObjectToScene(light1);

	Light *light2 = new Light(Light::GREEN_LIGHT, GL_LIGHT2);
	light2->position(-5, -10, -80);
	AddObjectToScene(light2);

	//Light *light3 = new Light(Light::BLUE_LIGHT, GL_LIGHT3);
	//light3->position(x, y, z);
	//AddObjectToScene(light3);


	Light *light0 = new Light(Light::WHITE_LIGHT, GL_LIGHT0);
	light0->position(0, 50, 0);
	AddObjectToScene(light0);

	MoonSquare *moon_square = new MoonSquare(Scene::GetTexture("./Textures/Moon_Surface2.bmp"), 64, worldProperties);
	moon_square->position(0, -30, -100);
	AddObjectToScene(moon_square);

	RoadManager *roadManager = new RoadManager(Scene::GetTexture("./Textures/Asphalt_Road.bmp"), 50, 45, worldProperties);
	roadManager->position(0, -16, 150);
	AddObjectToScene(roadManager);

	TexturedSphere *earth = new TexturedSphere(Scene::GetTexture("./Textures/alpha_map.bmp"), Scene::GetTexture("./Textures/alpha_clouds.bmp"));
	earth->position(300, 500, -1500);
	earth->size(100.0f);
	earth->SetResolution(2);
	AddObjectToScene(earth);

	//TODO Stars Sky box/sphere
	SkyBox *skyBox = new SkyBox(Scene::GetTexture("./Textures/Star_Scape.bmp"));
	skyBox->position(0, 0, -2000);
	skyBox->orientation(0, 1, 0);
	skyBox->size(4000);
	AddObjectToScene(skyBox);

	/* PROPS */

	Lander *lander = new Lander();
	lander->position(0, -10, -100);
	//AddObjectToScene(lander);

	Flag *flag = new Flag();
	flag->position(-20, -16, -50);
	//AddObjectToScene(flag);

	MaterialSphere *materialSphere = new MaterialSphere();
	materialSphere->position(30, -13, -100);
	materialSphere->size(3, 3, 3);
	//AddObjectToScene(materialSphere);
}

void MyScene::Projection()
{
	gluPerspective(static_cast<GLdouble>(60.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight), static_cast<GLdouble>(1.0), static_cast<GLdouble>(4000.0));
}
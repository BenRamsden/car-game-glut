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
#include "Car.h"
#include "ObjectSpawner.h"
#include "Tree.h"
#include "TreeSpawner.h"

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

	ObjectSpawner *objectSpawner = new ObjectSpawner(worldProperties, Scene::GetTexture("./Textures/american.bmp"));
	objectSpawner->position(0, -16, -60);  //must be at position of front of car, to detect collisions
	AddObjectToScene(objectSpawner);

	TreeSpawner *treeSpawner = new TreeSpawner(worldProperties, Scene::GetTexture("./Textures/barkTexture.bmp"), Scene::GetTexture("./Textures/leafTexture.bmp"));
	treeSpawner->position(0, -16, -30);
	AddObjectToScene(treeSpawner);

	Car *car = new Car(worldProperties);
	car->position(0, -16, -30);
	AddObjectToScene(car);

	MoonSquare *moon_square = new MoonSquare(Scene::GetTexture("./Textures/Moon_Surface2.bmp"), 64, worldProperties);
	moon_square->position(0, -30, -100);
	AddObjectToScene(moon_square);

	RoadManager *roadManager = new RoadManager(Scene::GetTexture("./Textures/Asphalt_Road.bmp"), 30, 45, worldProperties);
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

	Flag *flag = new Flag(Scene::GetTexture("./Textures/american.bmp"));
	flag->position(-20, -16, -50);
	//AddObjectToScene(flag);

	MaterialSphere *materialSphere = new MaterialSphere(1000.f, 1.0);
	materialSphere->position(0.0f, 1000.f, -1000.f);
	materialSphere->size(3, 3, 3);
	AddObjectToScene(materialSphere);
}

void MyScene::Projection()
{
	gluPerspective(static_cast<GLdouble>(60.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight), static_cast<GLdouble>(1.0), static_cast<GLdouble>(4000.0));
}
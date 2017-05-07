#include "MyScene.h"
#include "RoadManager.h"
#include "MoonSquare.h"
#include "TexturedSphere.h"
#include "MaterialSphere.h"
#include "Light.h"
#include "Flag.h"
#include "SkyBox.h"
#include "Lander.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(1.0f));

	//Translate, Rotate, Scale (T * R * S)
	
	LightShow(0,100,-100,150);

	Light *light0 = new Light(Light::WHITE_LIGHT, GL_LIGHT0);
	light0->position(0, 50, 0);
	AddObjectToScene(light0);

	MaterialSphere *materialSphere = new MaterialSphere();
	materialSphere->position(30, -13, -100);
	materialSphere->size(3, 3, 3);
	AddObjectToScene(materialSphere);

	MoonSquare *moon_square = new MoonSquare(Scene::GetTexture("./Textures/Moon_Surface2.bmp"), 64);
	moon_square->position(0, -30, -100);
	AddObjectToScene(moon_square);

	RoadManager *roadManager = new RoadManager(Scene::GetTexture("./Textures/Asphalt_Road.bmp"), 15, 45);
	roadManager->position(0, -16, 150);
	AddObjectToScene(roadManager);

	TexturedSphere *earth = new TexturedSphere(Scene::GetTexture("./Textures/alpha_map.bmp"), Scene::GetTexture("./Textures/alpha_clouds.bmp"));
	earth->position(300, 500, -1500);
	earth->size(100.0f);
	earth->SetResolution(2);
	AddObjectToScene(earth);

	//TODO Apollo 13 moon lander
	Lander *lander = new Lander();
	lander->position(0, -10, -100);
	AddObjectToScene(lander);

	//TODO American Flag
	Flag *flag = new Flag();
	flag->position(-20, -16, -50);
	AddObjectToScene(flag);

	//TODO Stars Sky box/sphere
	SkyBox *skyBox = new SkyBox(Scene::GetTexture("./Textures/Star_Scape.bmp"));
	skyBox->position(0, 0, -2000);
	skyBox->orientation(0, 1, 0);
	skyBox->size(4000);
	AddObjectToScene(skyBox);
}

void MyScene::Projection()
{
	gluPerspective(static_cast<GLdouble>(60.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight), static_cast<GLdouble>(1.0), static_cast<GLdouble>(4000.0));
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

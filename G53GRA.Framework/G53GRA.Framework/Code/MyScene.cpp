#include "MyScene.h"
#include "Tree.h"
#include "CubeHuman.h"
#include "TexturedCube.h"
#include "RoadSquare.h"
#include "RoadManager.h"
#include "Wall.h"
#include "Light.h"
#include "MaterialTest.h"
#include "TexturedSphere.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(1.0f));

	//Light *light1 = new Light(Light::BLUE_LIGHT, GL_LIGHT1);
	//light1->position(23, 0, -18.f);
	//Light *light2 = new Light(Light::RED_LIGHT, GL_LIGHT2);
	//light2->position(17, 0, -18.f);
	//CubeHuman *cube_human = new CubeHuman();
	//Tree *tree = new Tree("./Textures/Tree_Leaves.bmp");
	//TexturedCube *texturedCube = new TexturedCube("./Textures/Rocky_Mountain.bmp");
	//RoadSquare *roadSquare = new RoadSquare("./Textures/Asphalt_Road.bmp");
	//MaterialTest *materialTest = new MaterialTest();
	//AddObjectToScene(tree);
	//AddObjectToScene(cube_human);
	//AddObjectToScene(texturedCube);
	//AddObjectToScene(roadSquare);
	//AddObjectToScene(materialTest);
	//AddObjectToScene(light1);
	//AddObjectToScene(light2);

	//RoadManager *roadManager = new RoadManager(5);
	//AddObjectToScene(roadManager);

	Wall *moon_surface = new Wall(Scene::GetTexture("./Textures/Moon_Surface.bmp"), 25, 100);
	moon_surface->orientation(-1, 0, 0);
	moon_surface->position(0, -20, -100);
	AddObjectToScene(moon_surface);

	TexturedSphere *earth = new TexturedSphere(Scene::GetTexture("./Textures/alpha_map.bmp"), Scene::GetTexture("./Textures/alpha_clouds.bmp"));
	earth->position(300, 500, -1500);
	earth->size(100.0f);
	earth->SetResolution(2);
	AddObjectToScene(earth);
}

void MyScene::Projection()
{
	gluPerspective(static_cast<GLdouble>(60.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight), static_cast<GLdouble>(1.0), static_cast<GLdouble>(2000.0));
}

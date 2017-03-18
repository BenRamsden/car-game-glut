#include "MyScene.h"
#include "Tree.h"
#include "CubeHuman.h"
#include "TexturedCube.h"
#include "RoadSquare.h"
#include "RoadManager.h"
#include "Wall.h"
#include "Light.h"
#include "MaterialTest.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(1.0f));

	Light *light1 = new Light(GL_LIGHT1);
	CubeHuman *cube_human = new CubeHuman();
	Tree *tree = new Tree("./Textures/Tree_Leaves.bmp");
	TexturedCube *texturedCube = new TexturedCube("./Textures/Rocky_Mountain.bmp");
	//RoadSquare *roadSquare = new RoadSquare("./Textures/Asphalt_Road.bmp");
	RoadManager *roadManager = new RoadManager(25);
	Wall *wall = new Wall();
	MaterialTest *materialTest = new MaterialTest();

	AddObjectToScene(light1);
	AddObjectToScene(tree);
	AddObjectToScene(cube_human);
	AddObjectToScene(texturedCube);
	//AddObjectToScene(roadSquare);
	AddObjectToScene(roadManager);
	AddObjectToScene(wall);
	AddObjectToScene(materialTest);
}

void MyScene::Projection()
{
	gluPerspective(static_cast<GLdouble>(60.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight), static_cast<GLdouble>(1.0), static_cast<GLdouble>(1000.0));
}

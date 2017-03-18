#include "MyScene.h"
#include "Tree.h"
#include "CubeHuman.h"
#include "TexturedCube.h"
#include "RoadSquare.h"
#include "RoadManager.h"
#include "Wall.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(1.0f));

	CubeHuman *cube_human = new CubeHuman();
	Tree *tree = new Tree("./Textures/Tree_Leaves.bmp");
	TexturedCube *texturedCube = new TexturedCube("./Textures/Rocky_Mountain.bmp");
	//RoadSquare *roadSquare = new RoadSquare("./Textures/Asphalt_Road.bmp");
	RoadManager *roadManager = new RoadManager(25);
	Wall *wall = new Wall();

	AddObjectToScene(tree);
	AddObjectToScene(cube_human);
	AddObjectToScene(texturedCube);
	//AddObjectToScene(roadSquare);
	AddObjectToScene(roadManager);
	AddObjectToScene(wall);
}

void MyScene::Projection()
{
	gluPerspective(static_cast<GLdouble>(60.0), static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight), static_cast<GLdouble>(1.0), static_cast<GLdouble>(1000.0));
}

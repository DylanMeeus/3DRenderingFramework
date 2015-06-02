#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <cstdlib>
#include "renderer/Renderer.h"
#include "renderer/Camera.h"
#include "scene/Scene.h"
#include "scene/SceneFactory.h"
#include "shape/Sphere.h"
#include <string>

Renderer * renderer;
Camera * camera;

int nCols;
int nRows;

void reshape(int w, int h){
	glViewport(0, 0, w, h);
}

void renderScene(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, nCols, 0, nRows);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_LIGHTING);
    renderer->render();
	glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y)
{
	if(key == 'f' || key == 'z')
	{
		camera->forward();
	}
	else if(key == 'b' || key == 's')
	{
		camera->backward();
	}
	glutPostRedisplay();
}

void keySpecial(int key, int x , int y)
{
	if(key == GLUT_KEY_UP)
	{
		camera->up();
	}
	else if(key == GLUT_KEY_DOWN)
	{
		camera->down();
	}
	else if(key == GLUT_KEY_LEFT)
	{
		camera->left();
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		camera->right();
	}
	glutPostRedisplay();
}

int main(int argc, char ** argv){
		AppConfiguration appCfg = AppConfigurationFileReader::read(argv[1]);
		camera = new Camera(appCfg);
		Scene scene = SceneFactory::createScene(appCfg["scene.file"]);

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		nCols = std::atoi(appCfg["image.nCols"].c_str());
		nRows = std::atoi(appCfg["image.nRows"].c_str());
		glutInitWindowSize(nCols, nRows);
		glutCreateWindow("3D Computer Graphics");
		glutReshapeFunc(reshape);
		glutDisplayFunc(renderScene);
		glutKeyboardFunc(keyPressed);
		glutSpecialFunc(keySpecial);
	    renderer = new Renderer(camera, scene, appCfg);
		glutMainLoop();
		delete camera;
		delete renderer;
	return 0;
}

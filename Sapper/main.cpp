#include <windows.h> 
#include <gl/glut.h>
#include <gl/gl.h>
#include <iostream>
#include "Scene.h"
#include "Logic.h"
#include "Element.h"
#include <iostream>
using namespace std;
using DiskGame::Scene;

Scene* scene; 
void on_paint()
{
	scene->on_paint(); 
}
void mouseButton(int button, int state, GLint x, GLint y) {
	if (scene->game() == false) {
		if (button == GLUT_LEFT_BUTTON) {
			scene->coordinate(x, y);
		}
		if (button == GLUT_RIGHT_BUTTON) {
			scene->flag(x, y);
		}
	}
}
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
}
void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		scene->rotate(-5.0, 2);
		scene->on_paint();
		break;
	case GLUT_KEY_RIGHT:
		scene->rotate(5.0, 2);
		scene->on_paint();
		break;
	case GLUT_KEY_F2:   
		scene->initialization();
		break;
	}
}
void on_keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}
void on_timer(int value)
{
	scene->on_timer();
	glutTimerFunc(25, on_timer, 0); 
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);       
	scene = new Scene();        
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);          
	glutCreateWindow("Game");  
	glutDisplayFunc(on_paint);   
	glutKeyboardFunc(on_keyboard);
	glutSpecialFunc(processSpecialKeys);
	glutMouseFunc(mouseButton);
	glutTimerFunc(25, on_timer, 0);
	glutMainLoop();          
	delete scene;               
	return(0);
}
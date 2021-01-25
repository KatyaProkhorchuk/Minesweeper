#include <windows.h> 
#include <GL/glut.h>
#include "Scene.h"
#include <windows.h> 
#include <GL/glut.h>
#include "Scene.h"
#include <cmath>
#include "Logic.h";
#include "Element.h"
#include <iostream>
#include "Number.h"
using namespace std;
Number::Number() {}
void Number::draw(double x, double y, double z) {
	glColor3f(1.0f, 0.6f, 0.6f);
	glBegin(GL_POLYGON);
	glNormal3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(x, y, z);
	glVertex3f(x + 0.1, y, z);
	glVertex3f(x + 0.1, y + 0.1, z);
	glVertex3f(x, y + 0.1, z);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(x + 0.04, y + 0.04);
	glVertex2f(x + 0.105, y + 0.105);
	glEnd();
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(x + 0.08, y + 0.08);
	glVertex2f(x + 0.08, y + 0.16);
	glVertex2f(x + 0.105, y + 0.105);
	glEnd();

}
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
#include "board.h"
using namespace std;
board::board() {}
void board::draw(double length, double width, double height) {
	glColor3f(0.6f, 0.6f, 0.6f);

	glBegin(GL_POLYGON);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	//�������� �������
	glVertex3f(length, width, height);
	glVertex3f(length + 0.1, width, height);
	glVertex3f(length + 0.1, width + 0.1, height);
	glVertex3f(length, width + 0.1, height);
	glEnd();
	glBegin(GL_POLYGON);
	//����� �����
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(length, width, height);
	glVertex3f(length, width, height - 0.1);
	glVertex3f(length, width + 0.1, height - 0.1);
	glVertex3f(length, width + 0.1, height);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	//������ �����
	glVertex3f(length + 0.1, width, height);
	glVertex3f(length + 0.1, width, height - 0.1);
	glVertex3f(length + 0.1, width + 0.1, height - 0.1);
	glVertex3f(length + 0.1, width + 0.1, height);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	//������ �����
	glVertex3f(length, width, height);
	glVertex3f(length, width, height - 0.1);
	glVertex3f(length + 0.1, width, height - 0.1);
	glVertex3f(length + 0.1, width, height);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, -1.0f);
	//������� �����
	glVertex3f(length, width + 0.1, height);
	glVertex3f(length + 0.1, width + 0.1, height);
	glVertex3f(length + 0.1, width + 0.1, height - 0.1);
	glVertex3f(length, width + 0.1, height - 0.1);
	glEnd();
	glBegin(GL_POLYGON);
	//������ �����
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(length, width, height - 0.1);
	glVertex3f(length + 0.1, width, height - 0.1);
	glVertex3f(length + 0.1, width + 0.1, height - 0.1);
	glVertex3f(length, width + 0.1, height - 0.1);
	glEnd();
}
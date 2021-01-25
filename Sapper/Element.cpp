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
using namespace std;
void Element::texture(double x, double y, double z, int k) {
	glColor3f(1.0f, 0.6f, 0.6f);
	glBegin(GL_POLYGON);
	glNormal3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(x, y, z);
	glVertex3f(x + 0.1, y, z);
	glVertex3f(x + 0.1, y + 0.1, z);
	glVertex3f(x, y + 0.1, z);
	glEnd();
	if (k == 0) {
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glTranslatef(x + 0.05, y + 0.05, z);
		glutSolidSphere(0.06f, 12, 12);

		glPopMatrix();
	}
	if (k == 1) {
		glColor3f(0.0f, 0.6f, 0.8f);
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.05, z);
		glVertex3f(x, y + 0.06, z);
		glVertex3f(x + 0.08, y + 0.06, z);
		glVertex3f(x + 0.08, y + 0.05, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.08, y + 0.06, z);
		glVertex3f(x + 0.08, y + 0.05, z);
		glVertex3f(x + 0.05, y + 0.075, z);
		glVertex3f(x + 0.045, y + 0.07, z);
		glEnd();
	}
	if (k == 2) {
		glColor3f(0.0f, 0.6f, 0.8f);
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.01, z);
		glVertex3f(x, y + 0.06, z);
		glVertex3f(x + 0.01, y + 0.06, z);
		glVertex3f(x + 0.01, y + 0.01, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.05, y, z);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x, y + 0.06, z);
		glVertex3f(x + 0.01, y + 0.06, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.05, y + 0.01, z);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x + 0.065, y + 0.03, z);
		glVertex3f(x + 0.075, y + 0.03, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.065, y + 0.03, z);
		glVertex3f(x + 0.075, y + 0.03, z);
		glVertex3f(x + 0.05, y + 0.06, z);
		glVertex3f(x + 0.06, y + 0.06, z);

		glEnd();

	}
	if (k == 3) {
		glColor3f(0.0f, 0.6f, 0.8f);
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.01, z);
		glVertex3f(x, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.01, z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.03, y + 0.01, z);
		glVertex3f(x + 0.04, y + 0.01, z);
		glVertex3f(x + 0.03, y + 0.05, z);
		glVertex3f(x + 0.04, y + 0.05, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x + 0.06, y + 0.05, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y, z);
		glVertex3f(x + 0.07, y, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x, y + 0.01, z);
		glEnd();
	}
	if (k == 4) {
		glColor3f(0.0f, 0.6f, 0.8f);

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.03, y + 0.02, z);
		glVertex3f(x + 0.04, y + 0.02, z);
		glVertex3f(x + 0.03, y + 0.06, z);
		glVertex3f(x + 0.04, y + 0.06, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.02, z);
		glVertex3f(x, y + 0.02, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.03, y + 0.06, z);
		glVertex3f(x + 0.07, y + 0.06, z);
		glVertex3f(x + 0.07, y + 0.07, z);
		glVertex3f(x + 0.04, y + 0.07, z);
		glEnd();
	}
	if (k == 5) {
		glColor3f(0.0f, 0.6f, 0.8f);
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.01, z);
		glVertex3f(x, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.01, z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.03, y + 0.01, z);
		glVertex3f(x + 0.04, y + 0.01, z);
		glVertex3f(x + 0.03, y + 0.05, z);
		glVertex3f(x + 0.04, y + 0.05, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x + 0.06, y + 0.05, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y, z);
		glVertex3f(x + 0.04, y, z);
		glVertex3f(x + 0.04, y + 0.01, z);
		glVertex3f(x, y + 0.01, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.03, y + 0.04, z);
		glVertex3f(x + 0.07, y + 0.04, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glVertex3f(x + 0.03, y + 0.05, z);
		glEnd();
	}
	if (k == 6) {
		glColor3f(0.0f, 0.6f, 0.8f);
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.01, z);
		glVertex3f(x, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.01, z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.03, y + 0.01, z);
		glVertex3f(x + 0.04, y + 0.01, z);
		glVertex3f(x + 0.03, y + 0.05, z);
		glVertex3f(x + 0.04, y + 0.05, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x + 0.06, y + 0.05, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y, z);
		glVertex3f(x + 0.04, y, z);
		glVertex3f(x + 0.04, y + 0.01, z);
		glVertex3f(x, y + 0.01, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.04, z);
		glVertex3f(x + 0.07, y + 0.04, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glVertex3f(x, y + 0.05, z);
		glEnd();
	}
	if (k == 7) {
		glColor3f(0.0f, 0.6f, 0.8f);

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x + 0.06, y + 0.05, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.02, z);
		glVertex3f(x, y + 0.03, z);
		glVertex3f(x, y + 0.04, z);
		glEnd();

	}
	if (k == 8) {
		glColor3f(0.0f, 0.6f, 0.8f);
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.01, z);
		glVertex3f(x, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.05, z);
		glVertex3f(x + 0.01, y + 0.01, z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.03, y + 0.01, z);
		glVertex3f(x + 0.04, y + 0.01, z);
		glVertex3f(x + 0.03, y + 0.05, z);
		glVertex3f(x + 0.04, y + 0.05, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x + 0.06, y + 0.01, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x + 0.06, y + 0.05, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y, z);
		glVertex3f(x + 0.07, y, z);
		glVertex3f(x + 0.07, y + 0.01, z);
		glVertex3f(x, y + 0.01, z);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(x, y + 0.04, z);
		glVertex3f(x + 0.07, y + 0.04, z);
		glVertex3f(x + 0.07, y + 0.05, z);
		glVertex3f(x, y + 0.05, z);
		glEnd();
	}
}
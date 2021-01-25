#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> 
#include <GL/glut.h>
#include "Scene.h"
#include "Logic.h"
#include <iostream>
#include "Element.h"
#include "time.h"
#include "SOIL.h"
#include <gl\glu.h>	
#include <fstream>
#include <istream>
#include "board.h"
#include"Number.h"
using namespace std;

namespace DiskGame
{

	Scene::Scene()
	{
		element.push_back(new board());
		element.push_back(new Number());
		log->mass();
	}
	Scene::~Scene()
	{
	}
	void Scene::pole() {
		int N = 8;
		int M = 8;
		double x = -0.5;
		double y = -0.5;
		double z = 0.9;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				element[0]->draw(x, y, z);
				log->getXYZ(x, y, z, i, j);
				x += 0.11;
			}
			y += 0.11;
			x = -0.5;
		}
	}
	void Scene::rotate(double key, int i) {
		rotate_z += key;
	}
	void Scene::drawString(void* font, const char* text, float x, float y)
	{
		if (!text) 
		{
			return;
		}
	
		glRasterPos2f(x, y);
		while (*text)
		{
			glutBitmapCharacter(font, *text);
			text++;
		}
	}
	int tick = 0;
	void Scene::on_timer()
	{
		tick++;
		if (tick >= 40)
		{
			if (log->finish() == false)
			{
				time++;
			}
			tick = 0;
		}
		if (log->finish() == false)
			on_paint();
	}

	void Scene::result() {
		cout << 1 << endl;
		ifstream input("result.txt", ios::in | ios::binary);
		ofstream out("result.txt", ios::out | ios::binary);// app
		int file;
		if (!input)
		{
			cout << "Cannot open source file." << endl;
		}
		else {
			input >> file;
			cout << file << endl;
		}
		out << time;
	}

	void Scene::on_paint(void) {
		glClearColor(0, 0.9, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		char text[128];
		if (log->return_game() == 2) {
			sprintf(text, "Game over. Time: %d sec.   F2 - Restart game", time);
			glLoadIdentity();
			glColor3f(1, 1, 0);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, -0.6, 0.6);
			glPopMatrix();
		}
		else if (log->return_game() == 1) {
			sprintf(text, "Winner. Time: %d sec.   F2 - Restart game", time);
			glLoadIdentity();
			glColor3f(1, 1, 0);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, -0.6, 0.6);
			glPopMatrix();
			ifstream input("result.txt");
			int file;
			if (!input)
			{
				cout << "Cannot open source file." << endl;
			}
			else {
				int max;
				input >> file;
				max = file;
				while ((input >> file)) {
					if (max > file)max = file;
				}
				file = max;
				cout << max << endl;
			}
			ofstream out("result.txt", ios_base::app);
			if (file == NULL)
				out << time;
			if (time < file) {
				out << time << endl;
				sprintf(text, "Record Time: %d sec", time);
				glLoadIdentity();
				glColor3f(1, 1, 0);
				drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, -0.6, 0.9);
				glPopMatrix();
			}
			else {
				sprintf(text, "Best result Time: %d sec", file);
				glLoadIdentity();
				glColor3f(1, 1, 0);
				drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, -0.6, 0.9);
				glPopMatrix();
			}

		}
		else if (log->return_game() == 0) {
			sprintf(text, "F2 - Restart game  Time: %d sec.", time);
			glLoadIdentity();
			glColor3f(1, 1, 0);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.03, 0.9);
			glPopMatrix();
			sprintf(text, "Number of flags: %d", log->quantity_flag());
			glLoadIdentity();
			glColor3f(1, 1, 0);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.03, 0.8);
			glPopMatrix();
		}
		GLfloat front_color[] = { 1,1,1,0.3 };
		GLfloat back_color[] = { 1,1,1,1 };
		glMatrixMode(GL_PROJECTION);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, front_color);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, back_color);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glPushMatrix();
		gluPerspective(150, width / height, 1, 100);
		glPopMatrix();
		if (abs(rotate_z) % 360 == 0) {
			rotate_z = 0;
		}
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glRotatef(rotate_z, 0.0f, 0.0f, 0.1f);
		glRotatef(rotate_z, 0.1f, 0.0f, 0.0f);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		float eyeX = 0.0f;
		float eyeY = 0.0f;
		float eyeZ = 0.5f;
		float centerX = 0;
		float centerY = 0;
		float centerZ = 0;
		float upX = 0.5;
		float upY = 0.5;
		float upZ = 1.0;
		glMatrixMode(GL_PROJECTION);
		gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
		glPopMatrix();
		float lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 
		float lightDiffuse[] = { 0.0f, 0.5f, 0.8f, 1.0f }; 
		float lightSpecular[] = { 0.0f, 0.6, 0.8f, 1.0f };
		float lightPosition[] = { 1.0f, 1.0f, 0.8f, 0.0f };
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		pole();
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		//нужно просмативать все елементы массива и иесли где-то есть флаг-рисуем тк карта постоянно обновляется 
		if ((abs(rotate_z) >= 0 && abs(rotate_z) <= 5) || (abs(rotate_z) >= 180 && abs(rotate_z) <= 185)) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (log->inform(i, j) == true) {
						x = log->return_x(i, j);//получаем координаты флага
						y = log->return_y(i, j);
						z = log->return_z(i, j);
						element[1]->draw(x, y, z + 0.4);
					}
					if (log->num_inform(i, j) == true) {
						x = log->return_x(i, j);
						y = log->return_y(i, j);
						z = log->return_z(i, j);
						if (log->numeral(i, j) == 0) {
							glEnable(GL_LIGHTING);
							glEnable(GL_LIGHT0);
							el->texture(x, y, z, log->numeral(i, j));
							glDisable(GL_LIGHT0);
							glDisable(GL_LIGHTING);
						}
						else {
							el->texture(x, y, z, log->numeral(i, j));
						}
					}
				}
			}
		}
		glPopMatrix();
		glGetIntegerv(GL_VIEWPORT, viewport);
		glGetDoublev(GL_MODELVIEW_MATRIX, mv_matrix);
		glGetDoublev(GL_PROJECTION_MATRIX, proj_matrix);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHTING);
		glFlush();
		glutSwapBuffers();
	}
	void Scene::coordinate(GLint x, GLint y) {
		gluUnProject(x, y, 0.9, mv_matrix, proj_matrix, viewport, &obx, &oby, &obz);
		if (rotate_z == 0)
			log->logica(obx - 0.15, oby - 0.11);
		else
			log->logica(obx - 0.15, oby - 0.11);
	}
	void Scene::flag(GLint x, GLint y) {
		gluUnProject(x, y, 0.9, mv_matrix, proj_matrix, viewport, &obx, &oby, &obz);
		log->flag(obx - 0.15, oby - 0.11, obz);
		log->finish();
	}
	bool Scene::game() {
		return log->finish();
	}
	void Scene::initialization() {
		time = 0;
		log->mass();
		on_paint();
	}
}

#ifndef Scene_h
#define Scene_h 
#include "Element.h"
#include "Logic.h"
#include <vector>
using namespace std;
namespace DiskGame
{
	class Scene
	{
	private:
		vector<Element*> element;
		Element* el;
		int height = 800;
		int width = 600;
		Logic* log;
		int n = 8;
		int  rotate_z = 0;
		GLint viewport[4]; //для окна
		GLdouble mv_matrix[16]; // для модельно-видовой матрицы
		GLdouble proj_matrix[16]; // для матрицы прецирования
		GLdouble obx, oby, obz; // Возвращаемые объектные x, y, z координаты
		double x, y, z;
		int time = 0;
	public:
		Scene();
		~Scene();
		void pole();
		void rotate(double k, int i);
		void drawString(void* font, const char* text, float x, float y);
		void result();
		//void texture(double x, double y, double z, int k);
		void on_paint();
		void on_timer();
		void coordinate(GLint x, GLint y);
		void flag(GLint x, GLint y);
		bool game();
		void initialization();
	};
}

#endif
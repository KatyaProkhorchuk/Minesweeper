#ifndef Logic_h
#define Logic_h 

class Logic
{

public:
	Logic();
	~Logic();
	void mass();//генерируем массив -переманная массива глобальная и потом после того как сгенерировли 
	void getXYZ(double x, double y, double z, int i, int j);//записываем координаты в структуру
	int getX(double x, double y);
	int getY(double x, double y);
	void flag(double x, double y, double z);
	void logica(double x, double y);
	void open(int i, int j);
	void check(int i, int j);
	bool inform(int i, int j);//возвращает true/false
	int numeral(int i, int j);
	int quantity_flag();
	bool num_inform(int i, int j);
	double return_x(int i, int j);
	double return_y(int i, int j);
	double return_z(int i, int j);
	int return_game();
	bool finish();
};


#endif

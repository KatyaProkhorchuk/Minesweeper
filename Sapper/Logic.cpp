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
#include "time.h"
using namespace std;
enum boollean { true1, true2, false1 };
struct Objects {
    int arr[64];
    double x;
    int key;
    double y;
    double z;
    bool flag;
    boollean flag1;
    bool pressing;
};
bool final = false;
int game = 0;
Objects Arr[8][8];
int flag_num;
int mina = 10;
int n = 8;
Logic::Logic() {
}
Logic::~Logic() {

}
void Logic::mass() {

    int i;
    int j;
    int k = 0;
    game = 0;
    final = false;
    Logic();
    //изначально массив пустой
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Arr[i][j].key = -1;
            Arr[i][j].flag = false;
            Arr[i][j].flag1 = false1;
            Arr[i][j].pressing = false;//изначально все калвиши не нажаты
        }
    }
    //генерируем мины
    srand(time(NULL));
    while (k < mina) {
        i = rand() % n;
        j = rand() % n;
        if (Arr[i][j].key != 0) {
            Arr[i][j].key = 0;
            k++;
        }
    }
    //формируем массив
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t = 0;
            if (j != n - 1 && Arr[i][j + 1].key == 0)t++;
            if (i != n - 1 && Arr[i + 1][j].key == 0)t++;
            if (i != n - 1 && j != n - 1 && Arr[i + 1][j + 1].key == 0)t++;
            if (j != 0 && Arr[i][j - 1].key == 0)t++;
            if (i != 0 && Arr[i - 1][j].key == 0)t++;
            if (i != 0 && j != 0 && Arr[i - 1][j - 1].key == 0)t++;
            if (i != 0 && j != n - 1 && Arr[i - 1][j + 1].key == 0)t++;
            if (i != n - 1 && j != 0 && Arr[i + 1][j - 1].key == 0)t++;
            if (t != 0 && Arr[i][j].key != 0)
                Arr[i][j].key = t;
        }
    }
    flag_num = 16;
   
}
void Logic::getXYZ(double x, double y, double z, int i, int j) {
    Arr[i][j].x = x;
    Arr[i][j].y = y;
    Arr[i][j].z = z;
}
int Logic::getX(double x, double y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((abs(Arr[i][j].x - x) <= 0.090) && (abs(Arr[i][j].y - y) <= 0.090) && (abs(Arr[i][j].x - x) >= 0) && (abs(Arr[i][j].y - y) >= 0)) {
                return i;
            }
        }
    }
    return -1;
}
int Logic::getY(double x, double y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((abs(Arr[i][j].x - x) <= 0.090) && (abs(Arr[i][j].y - y) <= 0.090) && (abs(Arr[i][j].x - x) >= 0) && (abs(Arr[i][j].y - y) >= 0)) {
                return j;
            }
        }
    }
    return -1;
}
void Logic::flag(double x, double y, double z) {
    double xx, yy;
    int width = 600;
    int height = 800;

    int i = getX(x, y);
    int j = getY(x, y);
    if (i >= 0 && j >= 0) {

        if (Arr[i][j].pressing == false)
            if (Arr[i][j].flag == false) {
                if (flag_num > 0) {
                    Arr[i][j].flag = true;
                    Arr[i][j].flag1 = true1;
                    flag_num -= 1;
                }
            }
            else

                if (Arr[i][j].flag1 == true1) {
                    Arr[i][j].flag = true;
                    Arr[i][j].flag1 = true2;
                }
                else
                    if (Arr[i][j].flag1 == true2) {
                        Arr[i][j].flag = false;
                        Arr[i][j].flag1 = false1;
                        flag_num += 1;
                    }
    }
}
void Logic::open(int i, int j) {
    if (j < n - 1 && Arr[i][j + 1].key != 0) { Arr[i][j + 1].pressing = true; if (Arr[i][j + 1].flag == true) { Arr[i][j + 1].flag = false; } }
    if (i < n - 1 && Arr[i + 1][j].key != 0) {
        Arr[i + 1][j].pressing = true; if (Arr[i + 1][j].flag == true) {
            Arr[i + 1][j].flag = false;
        }
    }
    if (i < n - 1 && j < n - 1 && Arr[i + 1][j + 1].key != 0) {
        Arr[i + 1][j + 1].pressing = true;
        if (Arr[i + 1][j + 1].flag == true) {
            Arr[i + 1][j + 1].flag = false;
        }
    }
    if (j > 0 && Arr[i][j - 1].key != 0)
    {
        Arr[i][j - 1].pressing = true; if (Arr[i][j - 1].flag == true) {
            Arr[i][j - 1].flag = false;
        }
    }
    if (i > 0 && Arr[i - 1][j].key != 0) {
        Arr[i - 1][j].pressing = true; if (Arr[i - 1][j].flag == true) {
            Arr[i - 1][j].flag = false;
        }
    }
    if (i > 0 && j > 0 && Arr[i - 1][j - 1].key != 0) {
        Arr[i - 1][j - 1].pressing = true; if (Arr[i - 1][j - 1].flag == true) {
            Arr[i - 1][j - 1].flag = false;
        }
    }
    if (i > 0 && j < n - 1 && Arr[i - 1][j + 1].key != 0) {
        Arr[i - 1][j + 1].pressing = true; if (Arr[i - 1][j + 1].flag == true) {
            Arr[i - 1][j + 1].flag = false;
        }
    }
    if (i < n - 1 && j > 0 && Arr[i + 1][j - 1].key != 0) {
        Arr[i + 1][j - 1].pressing = true; if (Arr[i + 1][j - 1].flag == true) { Arr[i + 1][j - 1].flag = false; }
    }
}
void Logic::check(int i, int j) {
    if (Arr[i][j].key == -1) {
        if (j != n - 1 && Arr[i][j + 1].key == -1)
        {
            Arr[i][j + 1].pressing = true; check(i, j + 1); open(i, j + 1);
        }
        if (i != n - 1 && Arr[i + 1][j].key == -1) {
            Arr[i + 1][j].pressing = true; check(i + 1, j); open(i + 1, j);
        }
        if (i != n - 1 && j != n - 1 && Arr[i + 1][j + 1].key == -1 && Arr[i + 1][j + 1].flag == false) {
            Arr[i + 1][j + 1].pressing = true; check(i + 1, j + 1); open(i + 1, j + 1);
        }
        if (j != 0 && Arr[i][j - 1].key == -1) {
            Arr[i][j - 1].pressing = true; open(i, j - 1);
        }
        if (i != 0 && Arr[i - 1][j].key == -1) {
            Arr[i - 1][j].pressing = true; open(i - 1, j);
        }
        if (i != 0 && j != 0 && Arr[i - 1][j - 1].key == -1) {
            Arr[i - 1][j - 1].pressing = true; open(i - 1, j - 1);
        }
        if (i != 0 && j != n - 1 && Arr[i - 1][j + 1].key == -1) {
            Arr[i - 1][j + 1].pressing = true; open(i - 1, j + 1);
        }
        if (i != n - 1 && j != 0 && Arr[i + 1][j - 1].key == -1) {
            Arr[i + 1][j - 1].pressing = true;  check(i + 1, j - 1); open(i + 1, j - 1);
        }
        open(i, j);
    }
}
void Logic::logica(double x, double y) {
    int i = getX(x, y);
    int j = getY(x, y);
    if (i >= 0 && j >= 0 && Arr[i][j].flag == false) {
        Arr[i][j].pressing = true;
        if (Arr[i][j].key == -1)
        {
            check(i, j);
            if (j != n - 1)check(i, j + 1);
            if (i != n - 1)check(i + 1, j);
            if (i != n - 1 && j != n - 1)check(i + 1, j + 1);
            if (j != 0)check(i, j - 1);
            if (i != 0)check(i - 1, j);
            if (i != 0 && j != 0)check(i - 1, j - 1);
            if (i != 0 && j != n - 1)check(i - 1, j + 1);
            if (i != n - 1 && j != 0)check(i + 1, j - 1);

        }
        if (Arr[i][j].key == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (Arr[i][j].key == 0) { Arr[i][j].pressing = true; if (Arr[i][j].flag == true)Arr[i][j].flag = false; }
                }

            }
            //проиграли
            final = true;
            game = 2;
        }
    }

}
int Logic::quantity_flag() {
    return flag_num;
}
bool Logic::inform(int i, int j) {
    return Arr[i][j].flag;
}
int Logic::numeral(int i, int j) {
    return Arr[i][j].key;
}
bool Logic::num_inform(int i, int j) {
    return Arr[i][j].pressing;
}
double Logic::return_x(int i, int j) {
    return Arr[n - j - 1][n - i - 1].x;;
}
double Logic::return_y(int i, int j) {
    return Arr[n - j - 1][n - i - 1].y;
}
double Logic::return_z(int i, int j) {
    return Arr[n - j + 1][n - i + 1].z;
}

int Logic::return_game() {
    return game;
}
bool Logic::finish() {
    if (final == true)return final;
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Arr[i][j].key == 0 && Arr[i][j].flag == true) {
                t++;
            }
        }
    }
    if (t == mina) {
        final = true;
        game = 1;//победа
    }
    return final;
}
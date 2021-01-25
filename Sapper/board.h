#pragma once
#include "Element.h"
class board :public Element
{
public:
	board();
	virtual void draw(double x, double y, double z);
};

#pragma once
#include "Element.h"
class Number :public Element
{
public:
	Number();
	virtual void draw(double x, double y, double z);

};
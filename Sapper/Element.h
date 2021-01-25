#ifndef Element_h
#define Element_h 

class Element
{
public:
	virtual void draw(double x, double y, double z) = 0;
	void texture(double x, double y, double z, int k);
};


#endif
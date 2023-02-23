#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(string newName, int newHeight);
	void draw();
private:
	int height;
};


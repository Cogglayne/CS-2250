#include "Shape.h"

class Triangle : Shape
{
public:
	Triangle(string newName, int newHeight);
	void draw();
private:
	int height;
};


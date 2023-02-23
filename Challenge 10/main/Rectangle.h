#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(string newName, int newHeight, int newWidth);
	void draw();
private:
	int height;
	int width;
};


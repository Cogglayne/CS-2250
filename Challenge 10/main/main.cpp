#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main()
{
	Shape shape("Space 0");
	Rectangle rectangle("Rectangle 1", 3, 5);
	Triangle triangle("Triangle 2", 5);
	shape.draw();
	rectangle.draw();
	triangle.draw();
}

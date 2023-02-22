#include "Shape.h"
#include <iostream>
using namespace std;
Shape::Shape(string newName)
{
	cout << "Shape Constructor" << endl;
	name = newName;
}
void Shape::draw()
{
	cout << "Shape Draw" << endl;
	cout << "Name: " << name << endl;
}

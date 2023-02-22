#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape
{
public:
	Shape(string newName);
	void draw();
private:
	string name;
};

#endif 


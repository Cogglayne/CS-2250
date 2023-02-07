#include <iostream>
#ifndef WEAPON_H
#define WEAPON_H
using namespace std;

/*
* A weapon
*/
class Weapon
{
public:
	// method prototypes
	Weapon(string name = "PISTOL", int ammo = 0);
	bool fire();
private:
	// variables
	string m_name = "";
	int m_ammo = 0;
};

#endif


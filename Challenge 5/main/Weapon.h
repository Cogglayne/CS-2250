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
	Weapon(string name = "PISTOL", int ammo = 0);
	bool fire();
private:
	string m_name = "";
	int m_ammo = 0;
};

#endif


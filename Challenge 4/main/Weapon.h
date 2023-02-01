#include <iostream>
#ifndef WEAPON_H
#define WEAPON_H

/*
* A weapon
*/
class Weapon
{
public:
	// method protypes
	void setAmmo(int ammoAmount);
	int getAmmo();
	bool fire();
private:
	// variables
	int ammo = 0;
};

#endif



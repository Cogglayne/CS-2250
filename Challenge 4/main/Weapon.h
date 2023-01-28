#pragma once
#include <iostream>
#ifndef WEAPON_H
#define WEAPON_H
class Weapon
{
public:
	void setAmmo(int ammoAmmount);
	int getAmmo();
	bool fire();
private:
	int ammo = 0;
};
#endif // !WEAPON_H




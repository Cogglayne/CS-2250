#include "Weapon.h"
bool Weapon::fire()
{
	if (ammo > 0) 
	{
		std::cout << "FIRE" << std::endl;
		ammo--;
		return true;
	}
	else
	{
		std::cout << "CLICK" << std::endl;
		return false;
	}
}
int Weapon::getAmmo()
{
	return ammo;
}
void Weapon::setAmmo(int ammoAmmount)
{
	ammo = ammoAmmount;
}
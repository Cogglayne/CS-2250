#include "Weapon.h"

/*
* Return Value:
*  bool - true means that the weapon has ammo
*  false means the weapon has no ammo.

* Description: 
*  Fires a weapon if it has ammo
*/
bool Weapon::fire()
{
	// returns true if there is ammo otherwise returns false
	if (ammo > 0) 
	{
		// outputs fire and reduces the amount of ammo
		std::cout << "FIRE" << std::endl;
		ammo--;
		return true;
	}
	else
	{
		// outputs click when there is not ammo
		std::cout << "CLICK" << std::endl;
		return false;
	}
}

/*
* Return Value:
*  Returns the amount of ammo

* Description: 
*  Gets the amount of ammo a weapon has
*/
int Weapon::getAmmo()
{
	return ammo;
}

/*
* Parameters: 
*  ammoAmount - What a weapon's ammo should be set to

* Description: 
*  Sets the amount of ammo a weapon has
*/
void Weapon::setAmmo(int ammoAmount)
{
	ammo = ammoAmount;
}
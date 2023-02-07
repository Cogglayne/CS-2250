#include "Weapon.h"

/*
* Parameter:
* name = What to set the weapon's name as
* ammo = What to set the weapon's ammo as
* Description:
* Creates a weapon and sets the weapons
* name and ammo to the values given
*/
Weapon::Weapon(string name, int ammo)
{
	m_name = name;
	m_ammo = ammo;
}

/*
* Return Value:
*  true means that the weapon has ammo
*  false means the weapon has no ammo.
* Description:
*  Fires a weapon if it has ammo
*/
bool Weapon::fire()
{
	// returns true if there is ammo otherwise returns false
	if (m_ammo > 0)
	{
		// outputs fire and reduces the amount of ammo
		m_ammo--;
		cout << "FIRE" << endl;
		return true;
	}
	else
	{
		// outputs click when there is no ammo
		cout << "CLICK" << endl;
		return false;
	}
}
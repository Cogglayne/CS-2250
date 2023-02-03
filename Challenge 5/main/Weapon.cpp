#include "Weapon.h"
Weapon::Weapon(string name, int ammo) {
	m_name = name;
	m_ammo = ammo;
}
bool Weapon::fire() {
	if (m_ammo > 0) {
		m_ammo--;
		cout << "FIRE" << endl;
		return true;
	}
	else {
		cout << "CLICK" << endl;
		return false;
	}
}
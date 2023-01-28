
#include <iostream>
#include "Weapon.h"
using namespace std;
int main()
{
	Weapon weapon;
	int bullets = 0;
	bool isFiring = false;
	weapon.setAmmo(2);
	cout << "There are " << weapon.getAmmo() << " bullets in the clip" << endl;
	cout << "How many bullets do you want in the clip?" << endl;
	cin >> bullets;
	weapon.setAmmo(bullets);
	cout << "There are " << weapon.getAmmo() << " bullets in the clip" << endl;
	for (int numBullets = weapon.getAmmo(); numBullets > 0; numBullets--)
	{
		isFiring = weapon.fire();
		if (isFiring)
		{
			cout << "TRUE" << endl;
		}
	}
	isFiring = weapon.fire();
	if (!isFiring)
	{
		cout << "FALSE" << endl;
	}
	/*
	*weapon.setAmmo(6);
	bool test = weapon.fire();
	cout << weapon.getAmmo() << endl;
	cout << test << endl;
	*/
}


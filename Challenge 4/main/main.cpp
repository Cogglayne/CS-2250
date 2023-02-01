#include <iostream>
#include "Weapon.h"
using namespace std;

/*
* Return Value:
* int – value of 0 means that everything
* has gone ok, value of 1 means
* that something bad has happened

* Description:
*  This is the main function, execution
*  starts here. A weapon is is loaded twice,
*  fired until there is not ammo left, and then
*  fired one last time when it is empty
*/
int main()
{
	// object creation
	Weapon weapon;

	// variable creation
	int bullets = 0;
	bool isFiring = false;

	// setting the ammo using a hard value
	weapon.setAmmo(2);
	cout << "There are " << weapon.getAmmo() << " bullets in the clip" << endl;

	// setting the ammo using user input
	cout << "How many bullets do you want in the clip?" << endl;
	cin >> bullets;
	weapon.setAmmo(bullets);
	cout << "There are " << weapon.getAmmo() << " bullets in the clip" << endl;

	// fires the bullets until the weapon is empty
	for (int numBullets = weapon.getAmmo(); numBullets > 0; numBullets--)
	{

		// fires the weapon and if it successfully fired outputs true
		isFiring = weapon.fire();
		if (isFiring)
		{
			cout << "TRUE" << endl;
		}
	}

	// fire the weapon when it is empty then outputs false
	isFiring = weapon.fire();
	if (!isFiring)
	{
		cout << "FALSE" << endl;
	}

	return 0;
}


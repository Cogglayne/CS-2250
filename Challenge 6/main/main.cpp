#include <iostream>
#include <array>
using namespace std;

/*
* Return Value:
* 0 means everything went ok
* 1 means something bad happened
* Description:
* This is the main function, execution
* starts here. Creates two floats and
* then uses pointers to manipulate and
* print their values.
*/
int main()
{
	// variable creation
	float a = 3.14159;
	float b = 2.8321958;

	// 1. Create a pointer to a
	float* ptr = &a;

	// 2. Print the value of the pointee, followed by an end of line
	cout << *ptr << endl;

	// 3. Add 7 to the value of the the pointee
	*ptr += 7;

	// 4. Print the value of the pointee, followed by an end of line
	cout << *ptr << endl;

	// 5. Point the pointer to b instead of a
	ptr = &b;

	// 6. Print the value of the pointee, followed by an end of line
	cout << *ptr << endl;

	// 7. Multiple the value of the pointee by 5
	*ptr *= 5;

	// 8. Print the value of the pointee followed by an end of line
	cout << *ptr << endl;

	// 9. Set the pointer back to point to a again
	ptr = &a;

	// 10. Print out the value of the pointee
	cout << *ptr << endl;

	return 0;
}

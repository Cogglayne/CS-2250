#include <iostream>
#include <array>
using namespace std;
int main()
{
	float a = 3.14159;
	float b = 2.8321958;

	float* ptr = &a;
	cout << *ptr << endl;
	*ptr += 7;
	cout << *ptr << endl;
	ptr = &b;
	cout << *ptr << endl;
	*ptr *=5;
	cout << *ptr << endl;
	ptr = &a;
	cout << *ptr << endl;
		return 0;
}

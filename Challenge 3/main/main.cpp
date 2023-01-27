
#include <iostream>
using namespace std;

int promptForInteger();

/*
* Program execution begins and ends here.
* Sums numbers until a negative number is inputed
* afterwords the total sum is outputed
*/
int main()
{
	int totalSum = 0;
	int input = 0;
	bool isPositive;
	do
	{
		input = promptForInteger();
		isPositive = input >= 0;
		if (isPositive)
		{
			totalSum += input;
		}
	} while (isPositive);
	cout << "Total Sum: " << totalSum << endl;
	return 0;
}

/*
* Prompts for a number and then returns that number
*/
int promptForInteger()
{
	int input = 0;
	cout << "Please enter an integer:" << endl;
	cin >> input;
	return input;
}
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
	// variable creation
	int totalSum = 0;
	int input = 0;
	bool isPositive;

	// the loop continues until a negative number is inputed
	do
	{
		// gets a number from the user
		input = promptForInteger();

		// checks if input is positive 
		isPositive = (input >= 0);

		// the number is added to total sum if input is positive
		if (isPositive)
		{
			totalSum += input;
		}
	} while (isPositive);

	cout << "Total Sum: " << totalSum << endl;

	return 0;
}

/*
* Gets a number from the user and then returns that number
*/
int promptForInteger()
{
	int input = 0;
	cout << "Please enter an integer:" << endl;
	cin >> input;

	return input;
}
#include <iostream>
using namespace std;

void showOptions();

int selectOption();

string encryptMessage();

int getShiftValue();

/*
* Return Value:
*  0 if program ran successfull
*  1 if it failed.
* Description:
* 
*/
int main()
{
	int optionSelection = 0;
	string message = "";
	// outputs the initial greeting
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;

	// shows the user the options they can select
	showOptions();
	optionSelection = selectOption();
	message = encryptMessage();
	cout << message << endl;
	return 0;
}

void showOptions()
{
	cout << "*************************************" << endl;
	cout << "* 1 - Encrypt a message" << endl;
	cout << "* 2 - Decrypt a message" << endl;
	cout << "* 3 - Brute - force decrypt a message" << endl;
	cout << "* 4 - Quit" << endl;
	cout << "*************************************" << endl;
}

int selectOption()
{
	int selection = 0;
	bool notValidOption;
	cout << "Please make a menu selection (1-4):" << endl;
	do
	{
		cin >> selection;
		notValidOption = (selection <= 0 || selection >= 5);
		if (notValidOption)
		{
			cout << "Invalid choice, Please make a menu selection (1-4):" << endl;
		}
	} while (notValidOption);

	return selection;
}

string encryptMessage()
{
	int shiftValue = 0;
	int messageToEncryptLength = 0;
	string messageToEncrypt = "";


	cout << "Please enter the message to encrypt:" << endl;
	cin >> messageToEncrypt;
	shiftValue = getShiftValue();

	string temp = "cat";
	char tab2[1024];
	strcpy(tab2, temp.c_str());

	string temp = "cat";
	char tab2[1024];
	strncpy(tab2, temp.c_str(), sizeof(tab2));
	tab2[sizeof(tab2) - 1] = 0;
}

int getShiftValue()
{
	int selection = 0;
	cout << "Please enter the shift value (1-25):" << endl;
	bool notValidShiftValue;
	cin.ignore();
	do
	{
		cin >> selection;
		notValidShiftValue = (selection <= 0 || selection >= 26);
		if (notValidShiftValue)
		{
			cout << "Invalid choice, Please enter the shift value (1-25):" << endl;
		}
	} while (notValidShiftValue);
	return selection;
}
#include <iostream>
#include <string>
using namespace std;

void showOptions();

int selectOption();

string encryptMessage();

int getShiftValue();

string decryptMessage();

string getString(string message);



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
	switch (optionSelection)
	{
	case 1:
		message = encryptMessage();
		cout << "Encrypted as:" << endl;
		cout << message << endl;
		break;
	case 2:
		message = decryptMessage();
		break;
	case 3:
		break;
	}
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

	if (selection == 4)
	{
		cout << "Thank you Caesar!  See ya!" << endl;
		exit(0);
	}
	return selection;
}

string encryptMessage()
{
	int shiftValue = 0;
	string encryptedMessage = "";
	encryptedMessage = getString("Please enter the message to encrypt:");
	shiftValue = getShiftValue();


	unsigned char* array = (unsigned char*) & encryptedMessage[0];
	for (int i = 0; i < encryptedMessage.length(); i++) {
		if (isalpha(array[i])) {
			if (islower(array[i])) {
				if ((array[i] += shiftValue) > 'z')
				{
					array[i] -= 26;
				}
			}
			else if (isupper(array[i])) {
				if ((array[i] += shiftValue) > 'Z')
				{
					array[i] -= 26;
				}
			}
		}

	}
	return encryptedMessage;
}

int getShiftValue()
{

	int selection = 0;
	cout << "Please enter the shift value (1-25):" << endl;
	bool notValidShiftValue;
	do
	{
		;
		cin >> selection;
		notValidShiftValue = (selection <= 0 || selection >= 26);
		if (notValidShiftValue)
		{
			cout << "Invalid choice, Please enter the shift value (1-25):" << endl;
		}
	} while (notValidShiftValue);
	return selection;
}

string decryptMessage() {
	int shiftValue = 0;
	string decryptedMessage = "";
	decryptedMessage = getString("Please enter the message to decrypt:");
	shiftValue = getShiftValue();

	char* array = &decryptedMessage[0];

	for (int i = 0; i < decryptedMessage.length(); i++) {
		if (isalpha(array[i])) {
			if (islower(array[i])) {
				if (array[i] -= shiftValue < 'a'){
					array[i] += 26;
				}
				else
				{
					array[i] += shiftValue;
				}
			}
			else if (isupper(array[i])) {
				if (array[i] -= shiftValue < 'A')
				{
					array[i] += 26;
				}
				else
				{
					array[i] += shiftValue;
				}
			}
			array[i] -= shiftValue;
		}
	}
	
	return decryptedMessage;
}

string getString(string message)
{
	cin.ignore();
	string encryptOrDecrypt = "";
	cout << message << endl;
	getline(cin, encryptOrDecrypt);
	return encryptOrDecrypt;
}

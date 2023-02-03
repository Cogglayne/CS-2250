#include <iostream>
#include <string>
using namespace std;

void showOptions();

int selectOption();

void encryptMessage(string message, int shiftValue);

int getShiftValue();

void decryptMessage(string message, int shiftValue = 1);

string getString(string message);

string bruteForce();

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
	int shiftValue = 0;
	// outputs the initial greeting
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;

	while (true)
	{
		// shows the user the options they can select
		showOptions();
		optionSelection = selectOption();
		switch (optionSelection)
		{
		case 1:
			message = getString("Please enter the message to encrypt:");
			shiftValue = getShiftValue();
			encryptMessage(message, shiftValue); // this can't be void change this to string and string return type
			cout << "Encrypted as:" << endl;
			cout << message << endl;
			break;
		case 2:
			message = getString("Please enter the message to decrypt:");
			shiftValue = getShiftValue();
			decryptMessage(message, shiftValue);
			cout << "Decrypted as:" << endl;
			cout << message << endl;
			break;
		case 3:
			message = bruteForce();
			break;
		}

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

void encryptMessage(string message, int shiftValue)
{

	unsigned char* array = (unsigned char*) &message[0];
	for (int i = 0; i < message.length(); i++) {
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

void decryptMessage(string message, int shiftValue) {

	unsigned char* array = (unsigned char*)&message[0];

	for (int i = 0; i < message.length(); i++) {
		if (isalpha(array[i])) {
			if (islower(array[i])) {
				if ((array[i] -= shiftValue) < 'a'){
					array[i] += 26;
				}
			}
			else if (isupper(array[i])) {
				if ((array[i] -= shiftValue) < 'A')
				{
					array[i] += 26;
				}
			}
		}
	}
}

string getString(string message)
{
	cin.ignore();
	string encryptOrDecrypt = "";
	cout << message << endl;
	getline(cin, encryptOrDecrypt);
	return encryptOrDecrypt;
}

string bruteForce()
{
	int shiftValue = 0;
	string decryptedMessage = "";
	decryptedMessage = getString("Please enter the message to decrypt:");

	unsigned char* array = (unsigned char*)&decryptedMessage[0];
	cout << "Decrypted as:" << endl;

	for (int i = 0; i < 25; i++)
	{
		if (isalpha(array[i]))
		{
			cout << array[i] << endl;
			if (islower(array[i]))
			{
				cout << array[i] << endl;
				if ((array[i] -= (i+1)) < 'a')
				{
					array[i] += 26;
				}
				cout << array[i] << endl;
			}
			else if (isupper(array[i]))
			{
				cout << array[i] << endl;
				if ((array[i] -= (i+1)) < 'A')
				{
					array[i] += 26;
				}
				cout << array[i] << endl;
			}
		}
	}
	return decryptedMessage;
}

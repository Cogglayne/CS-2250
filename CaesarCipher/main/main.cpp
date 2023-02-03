#include <iostream>
#include <string>
using namespace std;

void showOptions();

int selectOption();

void encryptMessage(string& message, int shiftValue);

int getShiftValue();

void decryptMessage(string& message, int shiftValue);

string getString(string message);

void bruteForce(string message);

/*
* Return Value:
*  0 if program ran successfull
*  1 if it failed.
* Description:
* 
*/
int main()
{
	int optionSelection = 0; // used to verify input validation
	string message = ""; // used to the the string that is to be shifted
	int shiftValue = 0; // used to get how much a string should be shifted by

	// outputs the initial greeting
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;

	// continues until option 4 is chosen 
	while (true)
	{
		// shows the user the options they can select
		showOptions();

		// gets an option selection from the user
		optionSelection = selectOption();

		// calls encryption, decryption or brute force
		switch (optionSelection)
		{
		case 1:
			// encrypts a message and then outputs the encrypted message
			message = getString("Please enter the message to encrypt:");
			shiftValue = getShiftValue();
			encryptMessage(message, shiftValue); 
			cout << "Encrypted as:" << endl;
			cout << message << endl;
			break;
		case 2:
			//decrypts a message and outputs the decrypted message
			message = getString("Please enter the message to decrypt:");
			shiftValue = getShiftValue();
			decryptMessage(message, shiftValue);
			cout << "Decrypted as:" << endl;
			cout << message << endl;
			break;
		case 3:
			// outputs every possible decrypted version of an encrypted string
			message = getString("Please enter the message to decrypt:");
			bruteForce(message);
			break;
		}

	}

	return 0;
}
/*
* Description:
*  Shows the options a user can choose from
*/
void showOptions()
{
	cout << "*************************************" << endl;
	cout << "* 1 - Encrypt a message" << endl;
	cout << "* 2 - Decrypt a message" << endl;
	cout << "* 3 - Brute - force decrypt a message" << endl;
	cout << "* 4 - Quit" << endl;
	cout << "*************************************" << endl;
}
/*
* Return Value:
*  selection - the option the user chose
*/
int selectOption()
{
	int selection = 0; // used to get an option selection 
	bool notValidOption; // used to verify input

	// outputs the available selections
	cout << "Please make a menu selection (1-4):" << endl;

	// continues until a valid selection is chosen
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
/*
*/
void encryptMessage(string& message, int shiftValue)
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
/*
*/
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

void decryptMessage(string& message, int shiftValue) {

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
/*
*/
string getString(string message)
{
	cin.ignore();
	string encryptOrDecrypt = "";
	cout << message << endl;
	getline(cin, encryptOrDecrypt);
	return encryptOrDecrypt;
}
/*
*/
void bruteForce(string message)
{

	cout << "Decrypted as:" << endl;
	string originalMessage = message;
	for (int i = 0; i < 25; i++)
	{
		message = originalMessage;
		decryptMessage(message, i + 1);
		cout << message << endl;
	}
}

#include <iostream>
#include <string>
using namespace std;

void showOptions();

int selectOption();

string encryptMessage();

int getShiftValue();

string decryptMessage();



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
	message = decryptMessage();
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
	string encryptedMessage = "";
	cin.ignore();

	cout << "Please enter the message to encrypt:" << endl;
	getline(cin, encryptedMessage);
	shiftValue = getShiftValue();


	char* array = &encryptedMessage[0];

	for (int i = 0; i < encryptedMessage.length(); i++) {
		if (isalpha(array[i])) {
			if (islower(array[i])) {
				if (array[i] += shiftValue > 'z') {
					array[i] -= 26;
				}
			}
			else if (isupper(array[i])) {
				if (array[i] += shiftValue > 'Z') {
					array[i] -= 26;
				}
			}
			array[i] += shiftValue;
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
	cin.ignore();

	cout << "Please enter the message to decrypt:" << endl;
	getline(cin, decryptedMessage);
	shiftValue = getShiftValue();

	char* array = &decryptedMessage[0];

	for (int i = 0; i < decryptedMessage.length(); i++) {
		if (isalpha(array[i])) {
			if (islower(array[i])) {
				if (array[i] -= shiftValue < 'a'){
					array[i] += 26;
				}
			}
			else if (isupper(array[i])) {
				if (array[i] -= shiftValue < 'A') {
					array[i] += 26;
				}
			}
			array[i] -= shiftValue;
		}
	}
	
	return decryptedMessage;
}

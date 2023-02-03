#include <iostream>
#include <string>
using namespace std;

void showOptions();

int getValidInput(int max, int min, string message1, string message2);

void encryptMessage(string& message, int shiftValue);

void decryptMessage(string& message, int shiftValue);

string getMessage(string message);

void bruteForceDecryption(string message);

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
		optionSelection = getValidInput(4, 1, "Please make a menu selection (1-4):", "Invalid choice, Please make a menu selection (1-4):");

		// calls encryption, decryption or brute force
		switch (optionSelection)
		{
		case 1:
			// encrypts a message and then outputs the encrypted message
			message = getMessage("Please enter the message to encrypt:");
			shiftValue = getValidInput(25, 1, "Please enter the shift value (1-25):", "Invalid choice, Please enter the shift value (1-25):");
			encryptMessage(message, shiftValue);
			cout << "Encrypted as:" << endl;
			cout << message << endl;
			break;
		case 2:
			//decrypts a message and outputs the decrypted message
			message = getMessage("Please enter the message to decrypt:");
			shiftValue = getValidInput(25, 1, "Please enter the shift value (1-25):", "Invalid choice, Please enter the shift value (1-25):");
			decryptMessage(message, shiftValue);
			cout << "Decrypted as:" << endl;
			cout << message << endl;
			break;
		case 3:
			// outputs every possible decrypted version of an encrypted string
			message = getMessage("Please enter the message to decrypt:");
			bruteForceDecryption(message);
			break;
		case 4:
			// exits the program
			cout << "Thank you Caesar!  See ya!" << endl;
			exit(0);
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
* Description:
*  Shows the options a user can choose from
*/
int getValidInput(int max, int min, string message1, string message2)
{
	int selection = 0; // used to get an option selection 
	bool notValid; // used to verify input

	// outputs the available selections
	cout << message1 << endl;

	// continues until a valid selection is chosen
	do
	{
		cin >> selection;
		notValid = (selection < min || selection > max);

		// error message is outputed if user input is not valid
		if (notValid)
		{
			cout << message2 << endl;
		}
	} while (notValid);

	return selection;
}

/*
* Description:
* Shifts each letter in a string by a shift amount
*/
void encryptMessage(string& message, int shiftValue)
{
	unsigned char* array = (unsigned char*)&message[0]; // assigns a char array to the first spot in the string to encrypt

	// shifts each char in the message up by a specified shift amount
	// wraps the letter in the alphbet it it is greater than z or Z
	for (int i = 0; i < message.length(); i++)
	{
		// checks if the char is a letter then if it is upper or lowercase
		if (isalpha(array[i]))
		{
			if (islower(array[i]))
			{
				if ((array[i] += shiftValue) > 'z')
				{
					array[i] -= 26;
				}
			}
			else if (isupper(array[i]))
			{
				if ((array[i] += shiftValue) > 'Z')
				{
					array[i] -= 26;
				}
			}
		}

	}
}

/*
* Description:
* Shifts each letter in a string by a shift amount
*/
void decryptMessage(string& message, int shiftValue)
{
	unsigned char* array = (unsigned char*)&message[0]; // assigns a char array to the first spot in the string to decrypt

	// shifts each char in the message down by a specified shift amount
	// wraps the letter in the alphbet it it is less than a or A
	for (int i = 0; i < message.length(); i++)
	{
		// checks if the char is a letter then if it is upper or lowercase
		if (isalpha(array[i]))
		{
			if (islower(array[i]))
			{
				if ((array[i] -= shiftValue) < 'a')
				{
					array[i] += 26;
				}
			}
			else if (isupper(array[i]))
			{
				if ((array[i] -= shiftValue) < 'A')
				{
					array[i] += 26;
				}
			}
		}
	}
}
/*
* Description:
* Gets a message from the user and then returns it
*/
string getMessage(string message)
{
	// ignores previous cin to prevent issues with using cin then getline 
	cin.ignore();

	// gets a message from the user
	string encryptOrDecrypt = "";
	cout << message << endl;
	getline(cin, encryptOrDecrypt);

	return encryptOrDecrypt;
}
/*
* Description:
* Decrypts an encrypted message using brute force
*/
void bruteForceDecryption(string message)
{

	cout << "Decrypted as:" << endl;

	string originalMessage = message; // stores the original string so every iteration shifts the original string

	// decrypts the messsage with every possible shift value
	for (int i = 0; i < 25; i++)
	{
		message = originalMessage;
		decryptMessage(message, i + 1);
		cout << message << endl;
	}
}

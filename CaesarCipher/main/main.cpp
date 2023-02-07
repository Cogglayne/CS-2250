#include <iostream>
#include <string>
using namespace std;

void showOptions();

int getValidInput(int max, int min, string validInputsMessage, string errorMessage);

void encryptMessage(string& message, int shiftValue);

void decryptMessage(string& message, int shiftValue);

string getMessage(string userInstructionMessage);

void bruteForceDecryption(string message);

/*
* Return Value:
*  0 if program ran successfull
*  1 if it failed.
* Description:
* This is the main function, execution
* starts here. Initial prompts are presented to the user
* after the user is given the opportunity to encrypt, decrypt,
* quit, or brute force a message
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

		// encrypts, decrypts, brute forces, or quits the program
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
			cout << "Decrypted as:" << endl;
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
* Parameter:
* max - The maximum value for a valid input
* min - The mininum value for a valid input
* validInputsMessage - Shows what is considered a valid input
* errorMessage - Error message if invalid input is entered
* Return Value:
* selection - The valid input gotten from the user.
* Description:
*  Shows the options a user can choose from
*/
int getValidInput(int max, int min, string validInputsMessage, string errorMessage)
{
	int selection = 0; // used to get an option selection 
	bool notValid; // used to verify input

	// outputs the available selections
	cout << validInputsMessage << endl;

	// continues until a valid selection is chosen
	do
	{
		// assigns the user's input to selection
		cin >> selection;

		// checks if the user's input is valid
		notValid = (selection < min || selection > max);

		// an error message is outputed if the user's input is not valid
		if (notValid)
		{
			cout << errorMessage << endl;
		}
	} while (notValid);

	return selection;
}

/*
* Parameter:
* message = The message that the user wants to shift
* shiftValue = How much to shift the message by
* Description:
* Shifts each letter in a string by a shift amount
*/
void encryptMessage(string& message, int shiftValue)
{
	unsigned char* messagePtr = (unsigned char*) &message[0]; // assigns a char array to the first spot in the string to encrypt

	// shifts each char in the message up by a specified shift amount
	for (int i = 0; i < message.length(); i++)
	{
		// checks if the char is a letter then if it is upper or lowercase
		if (isalpha(messagePtr[i]))
		{
			if (islower(messagePtr[i]))
			{
				messagePtr[i] += shiftValue;
				// wraps a lower case letter if shifting it made it above z
				if (messagePtr[i] > 'z')
				{
					messagePtr[i] -= 26;
				}
			}
			else if (isupper(messagePtr[i]))
			{
				messagePtr[i] += shiftValue;
				// wraps an upper case letter if shifting it made it above Z
				if (messagePtr[i] > 'Z')
				{
					messagePtr[i] -= 26;
				}
			}
		}

	}
}

/*
* Parameter:
* message = The message that the user wants to shift
* shiftValue = How much to shift the message by
* Description:
* Shifts each letter in a string by a shift amount
*/
void decryptMessage(string& message, int shiftValue)
{
	unsigned char* messagePtr = (unsigned char*) &message[0]; // assigns a char array to the first spot in the string to decrypt

	// shifts each char in the message down by a specified shift amount
	for (int i = 0; i < message.length(); i++)
	{
		// checks if the char is a letter then if it is upper or lowercase
		if (isalpha(messagePtr[i]))
		{
			if (islower(messagePtr[i]))
			{
				messagePtr[i] -= shiftValue;
				// wraps a lower case letter if shifting it made it below a
				if (messagePtr[i] < 'a')
				{
					messagePtr[i] += 26;
				}
			}
			else if (isupper(messagePtr[i]))
			{
				messagePtr[i] -= shiftValue;
				// wraps an upper case letter if shifting it made it below A
				if (messagePtr[i] < 'A')
				{
					messagePtr[i] += 26;
				}
			}
		}
	}
}
/*
* Parameter:
* userInstructionMessage - Tells the user to input a string for encryption or decryption
* Return Value:
* message - The message the user wants to encrypt or decrypt
* Description:
* Gets a message from the user and then returns it
*/
string getMessage(string userInstructionMessage)
{
	string message = ""; // used to get a message from the user
	
	// ignores previous cin to prevent issues with using cin then getline 
	cin.ignore();

	// tells the user to enter a message to encrypt or decrypt
	cout << userInstructionMessage << endl;

	// gets a message from the user
	getline(cin, message);

	return message;
}
/*
* Parameter:
* message = The message that the user wants to shift
* Description:
* Decrypts an encrypted message using brute force
*/
void bruteForceDecryption(string message)
{
	string originalMessage = message; // stores the original string so every iteration shifts the original string

	// decrypts the messsage with every possible shift value
	for (int i = 0; i < 25; i++)
	{
		// resets the message to the original message
		message = originalMessage;

		// calls decreypt message with the current shift value
		decryptMessage(message, i + 1);

		// outputs the message shifted by each shift value
		cout << message << endl;
	}
}

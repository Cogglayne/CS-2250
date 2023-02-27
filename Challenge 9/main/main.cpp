#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// Prints out the board layout
/// </summary>
/// <param name="size">The size of the board</param>
void printLine(int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "----";
	}
	cout << "-" << endl;
}

/// <summary>
/// Prints the board
/// </summary>
/// <param name="board">The board to print out</param>
/// <param name="size">The size of the board</param>
void printBoard(char** board, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		printLine(size);
		for (size_t j = 0; j < size; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
	}
	printLine(size);
}

/// <summary>
/// Creates a board and then allows a user to place an S
/// </summary>
/// <returns>0 on success</returns>
int main()
{
	// gets the size of the board
	int size;
	do
	{
		cout << "How large should the board be?" << endl;
		cin >> size;
	} while (size < 1 || size > 20);

	// creates the board
	char** board = new char* [size];

	// initializes the board's rows and cols
	for (int row = 0; row < size; row++)
	{
		board[row] = new char[size];
		for (int col = 0; col < size; col++)
		{
			board[row][col] = ' ';
		}
	}

	// prints the board
	printBoard(board, size);

	for (size_t i = 0; i < size; i++)
	{
		// gets input from the user to place an S on the board
		int x;
		int y;
		do
		{
			cout << "Where would you like to put a ship?" << endl;
			cin >> x >> y;
		} while (x < 0 || x >= size || y < 0 || y >= size || board[x][y] != ' ');

		// sets the spot the user choose to S
		board[x][y] = 'S';

		printBoard(board, size);
	}

	return 0;
}

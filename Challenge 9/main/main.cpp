#include <iostream>
#include <string>
using namespace std;
void printLine(int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "----";
	}
	cout << "-" << endl;
}
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
int main()
{
	int size;
	do
	{
		cout << "How large should the board be?" << endl;
		cin >> size;
	} while (size < 1 || size > 20);

	char** board = new char* [size];

	for (int row = 0; row < size; row++)
	{
		board[row] = new char[size];
		for (int col = 0; col < size; col++)
		{
			board[row][col] = ' ';
		}
	}

	printBoard(board, size);

	for (size_t i = 0; i < size; i++)
	{
		int x;
		int y;
		do
		{
			cout << "Where would you like to put a ship?" << endl;
			cin >> x >> y;
		} while (x < 0 || x >= size || y < 0 || y >= size || board[x][y] != ' ');

		board[x][y] = 'S';

		printBoard(board, size);
	}

	return 0;
}

// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void mystery(int a, int b) {
    a++;
    cout << a << " " << b << " ";
}
int main()
{
    int a = 5;
    int b =9;
    mystery(b, a);
    cout << a << " " << b << " " << endl;
    return 0;
}
//5 10 -5 10 -5 2
// 10 4 4 10
// 5 9 5 10 wrong
// 5 10 5 10 wrong
// 5 9 10 5 wrong
// 6 9 5 9

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

//first question
//third is correct

//second question 
// 5th is correct

// Which of the following lines of code incorrectly attempts to use the DayOfYear class?
// 4 is correct

// final question
// 6 wrong and 7 right
// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int promptForInteger();

int main()
{
    int totalSum = 0;
    int input = 0;
    bool isPositive;
    do 
    {
       input = promptForInteger();
       isPositive = input >= 0;
       if (isPositive) 
       {
           totalSum += input;
       }
    } while (isPositive);
    cout << "Total Sum: " << totalSum << endl;
    return 0;
}

int promptForInteger() {
    int input = 0;
    cout << "Please enter an integer:" << endl;
    cin >> input;
    return input;
}
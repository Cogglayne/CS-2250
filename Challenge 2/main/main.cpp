// Challenge Two.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string fullName = "";
    cout << "Please enter your full name (first middle last)" << endl;
    getline(cin, fullName);
    //cout << "|" << fullName << "|" << endl;
    int age = 0;
    cout << "Please enter your age" << endl;
    cin >> age;
    //cout << "|" << age << "|" << endl;
    double gpa = 0;
    cout << "Please enter your gpa" << endl;
    cin >> gpa;
    //cout << "|" << gpa << "|" << endl;
    cin.ignore();
    string schoolName = "";
    cout << "Please enter your school's name" << endl;
    getline(cin, schoolName);
    //cout << "|" << schoolName << "|" << endl;
    if (gpa >= 3)
    {
        cout << "Welcome " << fullName << "," << " age " << age << ". Congratulations on your gpa of " << gpa << " at " << schoolName << endl;
    }
    else if (gpa >= 2)
    {
        cout << "Welcome " << fullName << "," << " age " << age << ". You can graduate with your current gpa of " << gpa << ", but might want to try a little harder at " << schoolName << endl;
    }
    else
    {
        cout << "Welcome " << fullName << "," << " age " << age << ". Unfortunately, you cannot graduate with your current gpa of " << gpa << " at " << schoolName << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

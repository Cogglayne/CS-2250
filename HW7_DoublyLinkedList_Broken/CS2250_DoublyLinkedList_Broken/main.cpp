#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <functional>
#include "DoublyLinkedList.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Test tracking variables
///////////////////////////////////////////////////////////////////////////////
int testsPassed = 0;
int totalTests = 0;

///////////////////////////////////////////////////////////////////////////////
// Test output for list construction methods
///////////////////////////////////////////////////////////////////////////////

// Construct an inorder list
string constructList(int n)
{
	// If the list is supposed to be empty, indicate that
	if (n == 0)
		return "EMPTY LIST";

	// Build the list using arrows to indicate pointers
	string listString = "1....1";
	for (int i = 2; i <= n; ++i)
	{
		listString = to_string(i) + "->" + listString + "->" + to_string(i);
	}
	return listString;
}

// Construct a Reverse order list
string constructReverseList(int n)
{
	// If the list is supposed to be empty, indicate that
	if (n == 0)
		return "EMPTY LIST";

	// Build the list using arrows to indicate pointers
	string listString = to_string(n) + "...." + to_string(n);
	for (int i = n - 1; i >= 1; --i)
	{
		listString = to_string(i) + "->" + listString + "->" + to_string(i);
	}
	return listString;
}

// Construct a list where the items are mirrored
string constructMirrorList(int n)
{
	// If the list is supposed to be empty, indicate that
	if (n == 0)
		return "EMPTY LIST";

	// Build the list using arrows to indicate pointers
	string listString = "1->1";
	for (int i = 2; i <= n; ++i)
	{
		listString = to_string(i) + "->" + listString + "->" + to_string(i);
	}

	listString += "...." + listString;

	return listString;
}

// Construct a list after removing one mirrored item
string constructMirrorListAfterRemoval(int n)
{
	// If the list is supposed to be empty, indicate that
	if (n == 0)
		return "EMPTY LIST";
	if (n == 1)
		return "1....1";

	// Build the list using arrows to indicate pointers
	return to_string(n) + "->" + constructMirrorList(n - 1) + "->" + to_string(n);
}

// Construct a custom list from an array
string constructCustomList(int values[], int size)
{
	// If the list is supposed to be empty, indicate that
	if (size == 0)
		return "EMPTY LIST";

	// Build the list using arrows to indicate pointers
	string listString = to_string(values[size - 1]) + "...." + to_string(values[size - 1]);
	for (int i = size - 2; i >= 0; --i)
	{
		listString = to_string(values[i]) + "->" + listString + "->" + to_string(values[i]);
	}

	return listString;
}

///////////////////////////////////////////////////////////////////////////////
// Test Results output methods
///////////////////////////////////////////////////////////////////////////////

// Test the list size and report results

void testListSize(DoublyLinkedList& list, int expectedResult)
{
	cout << endl << "========== TEST " << ++totalTests << " ========== " << "Checking Size of List" << endl;
	int actualResult = list.size();
	cout << setw(20) << left << "Expected Result:" << setw(60) << left << expectedResult << endl;
	cout << setw(20) << left << "Actual Result:  " << setw(60) << left << actualResult
		<< (actualResult == expectedResult ? "PASSED" : "                    FAILED") << endl;
	if (actualResult == expectedResult) ++testsPassed;
}

// Test the list contents and report results

void testListContents(DoublyLinkedList& list, string expectedResult)
{
	cout << endl << "========== TEST " << ++totalTests << " ========== " << "Checking Contents of List" << endl;
	ostringstream outputStream;
	outputStream << list;
	string actualResult = outputStream.str();
	cout << setw(20) << left << "Expected Result:" << setw(60) << left << expectedResult << endl;
	cout << setw(20) << left << "Actual Result:  " << setw(60) << left << actualResult
		<< (actualResult == expectedResult ? "PASSED" : "                    FAILED") << endl;
	if (actualResult == expectedResult) ++testsPassed;
}

// Test the search results and report results

void testSearchResult(DoublyLinkedList& list, int i, bool expectedValue)
{
	cout << endl << "========== TEST " << ++totalTests << " ========== " << "Checking Search for " << i << endl;
	bool searchResult = list.search(i);
	string expectedResult = expectedValue ? "TRUE" : "FALSE";
	string actualResult = searchResult ? "TRUE" : "FALSE";
	cout << setw(20) << left << "Expected Result:" << setw(60) << left << expectedResult << endl;
	cout << setw(20) << left << "Actual Result:  " << setw(60) << left << actualResult
		<< (actualResult == expectedResult ? "PASSED" : "                    FAILED") << endl;
	if (actualResult == expectedResult) ++testsPassed;
}

// Test the full node print and indicate user should manually check results

void testFullNodePrint(DoublyLinkedList& list)
{
	cout << endl << "Printing all of the Nodes" << endl;
	list.printFullNodes();
	cout << setw(80) << left << "" << "          CHECK" << endl;
	cout << endl;
}

// Test removing front or back and report results

void testRemovedFrontOrBack(DoublyLinkedList& list, int expectedResult, int actualResult)
{
	cout << endl << "========== TEST " << ++totalTests << " ========== " << "Checking Removed Front or Back " << expectedResult << endl;
	cout << setw(20) << left << "Expected Result:" << setw(60) << left << expectedResult << endl;
	cout << setw(20) << left << "Actual Result:  " << setw(60) << left << actualResult
		<< (actualResult == expectedResult ? "PASSED" : "                    FAILED") << endl;
	if (actualResult == expectedResult) ++testsPassed;
}

// Test removing an internal item and report results

void testRemovedItem(DoublyLinkedList& list, int i, bool expectedResult, bool actualResult)
{
	cout << endl << "========== TEST " << ++totalTests << " ========== " << "Checking Removed Item " << i << endl;
	cout << setw(20) << left << "Expected Result:" << setw(60) << left << expectedResult << endl;
	cout << setw(20) << left << "Actual Result:  " << setw(60) << left << actualResult
		<< (actualResult == expectedResult ? "PASSED" : "                    FAILED") << endl;
	if (actualResult == expectedResult) ++testsPassed;
}

///////////////////////////////////////////////////////////////////////////////
// Run the tests on the list using ints
///////////////////////////////////////////////////////////////////////////////
void runIntegerTests()
{
	cout << "***********************************************************************************************************" << endl;
	cout << "*********************************************  INTEGER TESTS  *********************************************" << endl;
	cout << "***********************************************************************************************************" << endl;

	// Initialize the testing variables
	totalTests = 0;
	testsPassed = 0;

	// TESTING List Constructor
	DoublyLinkedList list;
	cout << list << endl;

	// TESTING List AddFront, Size and operator<<
	cout << "************************  TESTING AddFront, Size and operator<< **************************" << endl;
	string expectedOutput = "....";
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Adding to Front " << i << endl;
		list.addFront(i);

		testListSize(list, i);
		testListContents(list, constructList(i));
		testFullNodePrint(list);
	}

	// TESTING List Search
	cout << "\n************************  TESTING Search **************************" << endl;
	testSearchResult(list, 0, false);
	for (int i = 1; i <= 5; ++i)
	{
		testSearchResult(list, i, true);
	}
	testSearchResult(list, 6, false);

	// TESTING List RemoveFront, Size, operator<<
	cout << "\n************************  TESTING RemoveFront, Size, operator<< **************************" << endl;
	for (int i = 5; i >= 1; --i)
	{
		testRemovedFrontOrBack(list, i, list.removeFront());
		testListSize(list, i - 1);
		testListContents(list, constructList(i - 1));
		testFullNodePrint(list);
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n************************  TESTING AddBack, Size and operator<< **************************" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Adding to Back " << i << endl;
		list.addBack(i);

		testListSize(list, i);
		testListContents(list, constructReverseList(i));
		testFullNodePrint(list);
	}

	// TESTING List RemoveBack, Size, operator<<
	cout << "\n************************  TESTING RemoveBack, Size, operator<< **************************" << endl;
	for (int i = 5; i >= 1; --i)
	{
		testRemovedFrontOrBack(list, i, list.removeBack());
		testListSize(list, i - 1);
		testListContents(list, constructReverseList(i - 1));
		testFullNodePrint(list);
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n************************  TESTING AddBack, AddFront, RemoveBack, RemoveFront << **************************" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		list.addBack(i);
		list.addFront(i);

		testListSize(list, i * 2);
		testListContents(list, constructMirrorList(i));
		testFullNodePrint(list);
	}

	for (int i = 5; i >= 1; --i)
	{
		testRemovedFrontOrBack(list, i, list.removeBack());
		testListSize(list, i * 2 - 1);
		testListContents(list, constructMirrorListAfterRemoval(i));
		testFullNodePrint(list);
		testRemovedFrontOrBack(list, i, list.removeFront());
		testListSize(list, i * 2 - 2);
		testListContents(list, constructMirrorList(i - 1));
		testFullNodePrint(list);
	}

	// TESTING List Search, RemoveItem, Size, operator<<
	cout << "\n************************  TESTING Search, RemoveItem, Size, operator<< **************************" << endl;
	cout << "NOTE:  Tests are performed to remove INNER items before OUTER items in list" << endl;

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
		list.addFront(i);
	}
	testListSize(list, 5);
	testListContents(list, constructList(5));
	testFullNodePrint(list);

	int i = 0;
	{
		int values[] = { 5, 4, 3, 2, 1 };
		testSearchResult(list, i, false);
		testRemovedItem(list, i, false, list.removeItem(i));
		testListSize(list, 5);
		testListContents(list, constructCustomList(values, 5));
		testFullNodePrint(list);
	}

	i = 3;
	{
		int values[] = { 5, 4, 2, 1 };
		testSearchResult(list, i, true);
		testRemovedItem(list, i, true, list.removeItem(i));
		testListSize(list, 4);
		testListContents(list, constructCustomList(values, 4));
		testFullNodePrint(list);
	}

	i = 2;
	{
		int values[] = { 5, 4, 1 };
		testSearchResult(list, i, true);
		testRemovedItem(list, i, true, list.removeItem(i));
		testListSize(list, 3);
		testListContents(list, constructCustomList(values, 3));
		testFullNodePrint(list);
	}

	i = 4;
	{
		int values[] = { 5, 1 };
		testSearchResult(list, i, true);
		testRemovedItem(list, i, true, list.removeItem(i));
		testListSize(list, 2);
		testListContents(list, constructCustomList(values, 2));
		testFullNodePrint(list);
	}

	i = 1;
	{
		int values[] = { 5 };
		testSearchResult(list, i, true);
		testRemovedItem(list, i, true, list.removeItem(i));
		testListSize(list, 1);
		testListContents(list, constructCustomList(values, 1));
		testFullNodePrint(list);
	}

	i = 5;
	{
		int values[] = { 0 };
		testSearchResult(list, i, true);
		testRemovedItem(list, i, true, list.removeItem(i));
		testListSize(list, 0);
		testListContents(list, constructCustomList(values, 0));
		testFullNodePrint(list);
	}

	// TESTING List Constructors, Destructors and operator=
	cout << "\n************************  TESTING Constructors and Destructors **************************" << endl;

	DoublyLinkedList* listPtr1 = new DoublyLinkedList();

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
		listPtr1->addFront(i);
	}
	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	// Test the copy constructor
	DoublyLinkedList* listPtr2 = new DoublyLinkedList(*listPtr1);
	testListSize(*listPtr2, 5);
	testListContents(*listPtr2, constructList(5));
	testFullNodePrint(*listPtr2);
	delete listPtr2;

	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	cout << "\n************************  TESTING operator= **************************" << endl;
	// Test the assignment operator
	listPtr2 = new DoublyLinkedList();
	*listPtr2 = *listPtr1;
	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);
	testListSize(*listPtr2, 5);
	testListContents(*listPtr2, constructList(5));
	testFullNodePrint(*listPtr2);
	delete listPtr2;

	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	// Test for self-assignment problems
	*listPtr1 = *listPtr1;
	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	// Delete the original list, if there is anything wrong with memory in copy or
	// assignment operator, this delete will cause a crash!
	delete listPtr1;

	cout << "***********************************************************************************************************" << endl;
	cout << "*********************************************  FINAL RESULTS  *********************************************" << endl;
	cout << "***********************************************************************************************************" << endl;

	cout << "Number Tests:   " << setw(10) << right << totalTests << endl;
	cout << "Passed Tests:   " << setw(10) << right << testsPassed << endl;
	cout << "Percent Passed: " << setw(10) << right << (testsPassed / (double)totalTests) * 100 << endl;
	cout << endl << endl;
}

///////////////////////////////////////////////////////////////////////////////
// Run the tests on the list using strings
///////////////////////////////////////////////////////////////////////////////
void runStringTests()
{
/*
	cout << "***********************************************************************************************************" << endl;
	cout << "*********************************************  STRING TESTS  **********************************************" << endl;
	cout << "***********************************************************************************************************" << endl;

	// Initialize the testing variables
	totalTests = 0;
	testsPassed = 0;

	// TESTING List Constructor
	DoublyLinkedList list;
	cout << list << endl;

	// TESTING List AddFront, Size and operator<<
	cout << "************************  TESTING AddFront, Size and operator<< **************************" << endl;
	string expectedOutput = "....";
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Adding to Front " << i << endl;
		list.addFront(to_string(i));

		testListSize(list, i);
		testListContents(list, constructList(i));
		testFullNodePrint(list);
	}

	// TESTING List Search
	cout << "\n************************  TESTING Search **************************" << endl;
	testSearchResult(list, to_string(0), false);
	for (int i = 1; i <= 5; ++i)
	{
		testSearchResult(list, to_string(i), true);
	}
	testSearchResult(list, to_string(6), false);

	// TESTING List RemoveFront, Size, operator<<
	cout << "\n************************  TESTING RemoveFront, Size, operator<< **************************" << endl;
	for (int i = 5; i >= 1; --i)
	{
		testRemovedFrontOrBack(list, to_string(i), list.removeFront());
		testListSize(list, i - 1);
		testListContents(list, constructList(i - 1));
		testFullNodePrint(list);
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n************************  TESTING AddBack, Size and operator<< **************************" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Adding to Back " << i << endl;
		list.addBack(to_string(i));

		testListSize(list, i);
		testListContents(list, constructReverseList(i));
		testFullNodePrint(list);
	}

	// TESTING List RemoveBack, Size, operator<<
	cout << "\n************************  TESTING RemoveBack, Size, operator<< **************************" << endl;
	for (int i = 5; i >= 1; --i)
	{
		testRemovedFrontOrBack(list, to_string(i), list.removeBack());
		testListSize(list, i - 1);
		testListContents(list, constructReverseList(i - 1));
		testFullNodePrint(list);
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n************************  TESTING AddBack, AddFront, RemoveBack, RemoveFront << **************************" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		list.addBack(to_string(i));
		list.addFront(to_string(i));

		testListSize(list, i * 2);
		testListContents(list, constructMirrorList(i));
		testFullNodePrint(list);
	}

	for (int i = 5; i >= 1; --i)
	{
		testRemovedFrontOrBack(list, to_string(i), list.removeBack());
		testListSize(list, i * 2 - 1);
		testListContents(list, constructMirrorListAfterRemoval(i));
		testFullNodePrint(list);
		testRemovedFrontOrBack(list, to_string(i), list.removeFront());
		testListSize(list, i * 2 - 2);
		testListContents(list, constructMirrorList(i - 1));
		testFullNodePrint(list);
	}

	// TESTING List Search, RemoveItem, Size, operator<<
	cout << "\n************************  TESTING Search, RemoveItem, Size, operator<< **************************" << endl;
	cout << "NOTE:  Tests are performed to remove INNER items before OUTER items in list" << endl;

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
		list.addFront(to_string(i));
	}
	testListSize(list, 5);
	testListContents(list, constructList(5));
	testFullNodePrint(list);

	int i = 0;
	{
		int values[] = { 5, 4, 3, 2, 1 };
		testSearchResult(list, to_string(i), false);
		testRemovedItem(list, to_string(i), false, list.removeItem(to_string(i)));
		testListSize(list, 5);
		testListContents(list, constructCustomList(values, 5));
		testFullNodePrint(list);
	}

	i = 3;
	{
		int values[] = { 5, 4, 2, 1 };
		testSearchResult(list, to_string(i), true);
		testRemovedItem(list, to_string(i), true, list.removeItem(to_string(i)));
		testListSize(list, 4);
		testListContents(list, constructCustomList(values, 4));
		testFullNodePrint(list);
	}

	i = 2;
	{
		int values[] = { 5, 4, 1 };
		testSearchResult(list, to_string(i), true);
		testRemovedItem(list, to_string(i), true, list.removeItem(to_string(i)));
		testListSize(list, 3);
		testListContents(list, constructCustomList(values, 3));
		testFullNodePrint(list);
	}

	i = 4;
	{
		int values[] = { 5, 1 };
		testSearchResult(list, to_string(i), true);
		testRemovedItem(list, to_string(i), true, list.removeItem(to_string(i)));
		testListSize(list, 2);
		testListContents(list, constructCustomList(values, 2));
		testFullNodePrint(list);
	}

	i = 1;
	{
		int values[] = { 5 };
		testSearchResult(list, to_string(i), true);
		testRemovedItem(list, to_string(i), true, list.removeItem(to_string(i)));
		testListSize(list, 1);
		testListContents(list, constructCustomList(values, 1));
		testFullNodePrint(list);
	}

	i = 5;
	{
		int values[] = { 0 };
		testSearchResult(list, to_string(i), true);
		testRemovedItem(list, to_string(i), true, list.removeItem(to_string(i)));
		testListSize(list, 0);
		testListContents(list, constructCustomList(values, 0));
		testFullNodePrint(list);
	}

	// TESTING List Constructors, Destructors and operator=
	cout << "\n************************  TESTING Constructors and Destructors **************************" << endl;

	DoublyLinkedList* listPtr1 = new DoublyLinkedList();

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
		listPtr1->addFront(i);
	}
	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	// Test the copy constructor
	DoublyLinkedList* listPtr2 = new DoublyLinkedList(*listPtr1);
	testListSize(*listPtr2, 5);
	testListContents(*listPtr2, constructList(5));
	testFullNodePrint(*listPtr2);
	delete listPtr2;

	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	cout << "\n************************  TESTING operator= **************************" << endl;
	// Test the assignment operator
	listPtr2 = new DoublyLinkedList();
	*listPtr2 = *listPtr1;
	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);
	testListSize(*listPtr2, 5);
	testListContents(*listPtr2, constructList(5));
	testFullNodePrint(*listPtr2);
	delete listPtr2;

	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	// Test for self-assignment problems
	*listPtr1 = *listPtr1;
	testListSize(*listPtr1, 5);
	testListContents(*listPtr1, constructList(5));
	testFullNodePrint(*listPtr1);

	// Delete the original list, if there is anything wrong with memory in copy or
	// assignment operator, this delete will cause a crash!
	delete listPtr1;

	cout << "***********************************************************************************************************" << endl;
	cout << "*********************************************  FINAL RESULTS  *********************************************" << endl;
	cout << "***********************************************************************************************************" << endl;

	cout << "Number Tests:   " << setw(10) << right << totalTests << endl;
	cout << "Passed Tests:   " << setw(10) << right << testsPassed << endl;
	cout << "Percent Passed: " << setw(10) << right << (testsPassed / (double)totalTests) * 100 << endl;
	cout << endl << endl;
*/
}

int main()
{
	runIntegerTests();
	runStringTests();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	cout << "Hit ENTER to exit..." << endl;
	string a;
	getline(cin, a);

	return 0;
}


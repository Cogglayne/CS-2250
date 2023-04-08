#include "stdafx.h"
#include "CppUnitTest.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedListNode.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DLL_UnitTests
{
	TEST_CLASS(ConstructorsAndDestructors)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// Constructor Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(Constructor)
		{
			DoublyLinkedList<int>list;
			// The "L" that prefixes the string means that the string is stored
			// as 16-bit characters instead of 8-bit characters and is
			// required by the assert 
			Assert::AreEqual(0, list.getCount(), L"Constructor Count Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead(), L"Constructor Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"Constructor Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Constructor getNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"Constructor Output Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// CopyConstructor Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(CopyConstructor_Empty)
		{
			DoublyLinkedList<int>origList;
			DoublyLinkedList<int>newList(origList);

			Assert::AreEqual(0, newList.getCount(), L"CopyConstructor Count Incorrect", LINE_INFO());
			Assert::IsNull(newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
			Assert::IsNull(newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"CopyConstructor getNbrOfNodes Incorrect", LINE_INFO());
		}
		TEST_METHOD(CopyConstructor)
		{
			DoublyLinkedList<int>origList;
			origList.addFront(1);
			origList.addFront(2);
			origList.addFront(3);
			origList.addFront(4);
			origList.addFront(5);

			DoublyLinkedList<int>newList(origList);

			Assert::AreEqual(5, newList.getCount(), L"CopyConstructor Count Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());
			Assert::AreEqual(10, DoublyLinkedListNode<int>::getNbrOfNodes(), L"CopyConstructor getNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove from one of the lists
				int item = newList.removeBack();
				Assert::AreEqual(1, item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(9, DoublyLinkedListNode<int>::getNbrOfNodes(), L"CopyConstructor getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(5, item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(8, DoublyLinkedListNode<int>::getNbrOfNodes(), L"CopyConstructor getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3->2....2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeBack();
				Assert::AreEqual(2, item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(7, DoublyLinkedListNode<int>::getNbrOfNodes(), L"CopyConstructor getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3....3->4";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(4, item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(6, DoublyLinkedListNode<int>::getNbrOfNodes(), L"CopyConstructor getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "3....3";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(3, item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"CopyConstructor getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// Destructor Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(Destructor_Empty)
		{
			DoublyLinkedList<int>*list = new DoublyLinkedList<int>();
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes Empty List Incorrect", LINE_INFO());
			Assert::IsNull(list->getHead(), L"Destructor Head Incorrect", LINE_INFO());
			Assert::IsNull(list->getTail(), L"Destructor Tail Incorrect", LINE_INFO());

			delete list;
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes Empty List Incorrect", LINE_INFO());
		}
		TEST_METHOD(Destructor_5Items)
		{
			DoublyLinkedList<int>*list = new DoublyLinkedList<int>();
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes List Incorrect", LINE_INFO());

			list->addFront(1);
			Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes List Incorrect", LINE_INFO());

			list->addFront(2);
			Assert::AreEqual(2, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes List Incorrect", LINE_INFO());

			list->addFront(3);
			Assert::AreEqual(3, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes List Incorrect", LINE_INFO());

			list->addFront(4);
			Assert::AreEqual(4, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes List Incorrect", LINE_INFO());

			list->addFront(5);
			Assert::AreEqual(5, list->getCount(), L"Destructor Count Incorrect", LINE_INFO());

			Assert::IsNotNull(list->getHead(), L"Destructor Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list->getTail(), L"Destructor Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes Incorrect", LINE_INFO());
			Assert::IsNull(list->getHead()->getPrev(), L"Destructor Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list->getTail()->getNext(), L"Destructor Tail->Next Incorrect", LINE_INFO());

			delete list;

			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"Destructor getNbrOfNodes Incorrect", LINE_INFO());
		}
	};

	TEST_CLASS(AdditemsTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// addFront Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(addFront_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);

			Assert::AreEqual(1, list.getCount(), L"AddSingleItemFront Count Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"AddSingleItemFront Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"AddSingleItemFront Tail Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead()->getPrev(), L"AddSingleItemFront Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail()->getNext(), L"AddSingleItemFront Tail->Next Incorrect", LINE_INFO());
			Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddSingleItemFront getNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1....1";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFront Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(addFront_MultipleItems)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			list.addFront(2);
			list.addFront(3);
			list.addFront(4);
			list.addFront(5);

			Assert::AreEqual(5, list.getCount(), L"AddMultipleItemFront Count Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"AddMultipleItemFront Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"AddMultipleItemFront Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFront Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFront Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "5->4->3->2->1....1->2->3->4->5";
			Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFront Output Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// addBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(addBack_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addBack(1);

			Assert::AreEqual(1, list.getCount(), L"AddSingleItemBack Count Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"AddSingleItemBack Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"AddSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddSingleItemBack getNbrOfNodes Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead()->getPrev(), L"AddSingleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail()->getNext(), L"AddSingleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1....1";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(addBack_MultipleItems)
		{
			DoublyLinkedList<int>list;
			list.addBack(1);
			list.addBack(2);
			list.addBack(3);
			list.addBack(4);
			list.addBack(5);

			Assert::AreEqual(5, list.getCount(), L"AddMultipleItemBack Count Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"AddMultipleItemBack Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"AddMultipleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1->2->3->4->5....5->4->3->2->1";
			Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBack Output Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// addFrontaddBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(addFrontaddBack_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			list.addBack(2);

			Assert::AreEqual(2, list.getCount(), L"AddSingleItemFrontAddSingleItemBack Count Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"AddSingleItemFrontAddSingleItemBack Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"AddSingleItemFrontAddSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(2, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddSingleItemFrontAddSingleItemBack getNbrOfNodes Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead()->getPrev(), L"AddSingleItemFrontAddSingleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail()->getNext(), L"AddSingleItemFrontAddSingleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1->2....2->1";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFrontAddSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(addFrontaddBack_MultipleItem)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			list.addBack(2);
			list.addFront(3);
			list.addBack(4);
			list.addFront(5);
			list.addBack(6);

			Assert::AreEqual(6, list.getCount(), L"AddMultipleItemBack Count Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"AddMultipleItemBack Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"AddMultipleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(6, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "5->3->1->2->4->6....6->4->2->1->3->5";
			Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBack Output Incorrect", LINE_INFO());
		}
	};

	TEST_CLASS(addFrontremoveFrontTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// addFrontremoveFront Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(addFrontremoveFront_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			int item = list.removeFront();
			Assert::AreEqual(1, item, L"AddSingleItemFrontRemoveSingleItemFront Item Incorrect", LINE_INFO());

			Assert::AreEqual(0, list.getCount(), L"AddSingleItemFrontRemoveSingleItemFront Count Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead(), L"AddSingleItemFrontRemoveSingleItemFront Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"AddSingleItemFrontRemoveSingleItemFront Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddSingleItemFrontRemoveSingleItemFront getNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFrontRemoveSingleItemFront Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(addFrontremoveFront_MultipleItems)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			list.addFront(2);
			list.addFront(3);
			list.addFront(4);
			list.addFront(5);

			int item;
			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(5, item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "4->3->2->1....1->2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(4, item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "3->2->1....1->2->3";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(3, item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "2->1....1->2";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(2, item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				item = list.removeFront();
				Assert::AreEqual(1, item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}
		}

	};

	TEST_CLASS(addFrontremoveBackTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// addFrontremoveBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(addFrontremoveBack_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			int item = list.removeBack();
			Assert::AreEqual(1, item, L"AddSingleItemFrontRemoveSingleItemBack Item Incorrect", LINE_INFO());
			Assert::AreEqual(0, list.getCount(), L"AddSingleItemFrontRemoveSingleItemBack Count Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead(), L"AddSingleItemFrontRemoveSingleItemBack Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"AddSingleItemFrontRemoveSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddSingleItemFrontRemoveSingleItemBack getNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFrontRemoveSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemFrontRemoveMultipleItemBack)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			list.addFront(2);
			list.addFront(3);
			list.addFront(4);
			list.addFront(5);

			int item;

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(1, item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(2, item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5->4->3....3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(3, item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5->4....4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(4, item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5....5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				item = list.removeBack();
				Assert::AreEqual(5, item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.getCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}
		}

	};

	TEST_CLASS(addBackremoveBackTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// addBackremoveBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(addBackremoveBack_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addBack(1);
			int item = list.removeBack();
			Assert::AreEqual(1, item, L"AddSingleItemBackRemoveSingleItemBack Item Incorrect", LINE_INFO());
			Assert::AreEqual(0, list.getCount(), L"AddSingleItemBackRemoveSingleItemBack Count Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead(), L"AddSingleItemBackRemoveSingleItemBack Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"AddSingleItemBackRemoveSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddSingleItemBackRemoveSingleItemBack getNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemBackRemoveSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(addBackremoveBack_MultipleItem)
		{
			DoublyLinkedList<int>list;
			list.addBack(1);
			list.addBack(2);
			list.addBack(3);
			list.addBack(4);
			list.addBack(5);

			int item;

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(5, item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1->2->3->4....4->3->2->1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(4, item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1->2->3....3->2->1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(3, item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1->2....2->1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
				item = list.removeBack();
				Assert::AreEqual(2, item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				item = list.removeBack();
				Assert::AreEqual(1, item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack getNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}
		}

	};

	TEST_CLASS(addBackremoveFrontTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// addBackremoveFront Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(addBackremoveFront_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addBack(1);
			int item = list.removeFront();
			Assert::AreEqual(1, item, L"AddSingleItemBackRemoveSingleItemFront Item Incorrect", LINE_INFO());
			Assert::AreEqual(0, list.getCount(), L"AddSingleItemBackRemoveSingleItemFront Count Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead(), L"AddSingleItemBackRemoveSingleItemFront Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"AddSingleItemBackRemoveSingleItemFront Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddSingleItemBackRemoveSingleItemFront getNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemBackRemoveSingleItemFront Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(addBackremoveFront_MultipleItem)
		{
			DoublyLinkedList<int>list;
			list.addBack(1);
			list.addBack(2);
			list.addBack(3);
			list.addBack(4);
			list.addBack(5);

			int item;

			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(1, item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "2->3->4->5....5->4->3->2";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(2, item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "3->4->5....5->4->3";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(3, item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "4->5....5->4";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
				item = list.removeFront();
				Assert::AreEqual(4, item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNotNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail()->getNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5....5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				item = list.removeFront();
				Assert::AreEqual(5, item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.getCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront getNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}
		}

	};

	TEST_CLASS(removeItemTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// removeItem Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(removeItem_SingleItem)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			Assert::AreEqual(true, list.removeItem(1), L"RemoveFromSingleItemList Exists Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.removeItem(1), L"RemoveFromSingleItemList Duplicate Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.removeItem(0), L"RemoveFromSingleItemList Does Not Exist Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead(), L"RemoveFromSingleItemList Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"RemoveFromSingleItemList Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"RemoveFromSingleItemList getNbrOfNodes Incorrect", LINE_INFO());
		}

		TEST_METHOD(removeItem_MultipleItem)
		{
			{   // Remove items back to front
				DoublyLinkedList<int>list;
				for (int i = 1; i < 6; ++i)
				{
					list.addFront(i);
				}
				for (int i = 1; i < 6; ++i)
				{
					Assert::AreEqual(true, list.removeItem(i), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
					Assert::AreEqual(false, list.removeItem(i), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				}
				Assert::AreEqual(false, list.removeItem(0), L"RemoveFromMultipleItemList Does Not Exist Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead(), L"RemoveFromMultipleItemList Head Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail(), L"RemoveFromMultipleItemList Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"RemoveFromMultipleItemList getNbrOfNodes Incorrect", LINE_INFO());
			}

			{   // Remove items front to back
				DoublyLinkedList<int>list;
				for (int i = 1; i < 6; ++i)
				{
					list.addFront(i);
				}
				for (int i = 5; i > 0; --i)
				{
					Assert::AreEqual(true, list.removeItem(i), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
					Assert::AreEqual(false, list.removeItem(i), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				}
				Assert::AreEqual(false, list.removeItem(0), L"RemoveFromMultipleItemList Does Not Exist Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead(), L"RemoveFromMultipleItemList Head Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail(), L"RemoveFromMultipleItemList Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"RemoveFromMultipleItemList getNbrOfNodes Incorrect", LINE_INFO());
			}

			{   // Remove items from middle
				DoublyLinkedList<int>list;
				for (int i = 1; i < 6; ++i)
				{
					list.addFront(i);
				}
				Assert::AreEqual(true, list.removeItem(3), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.removeItem(3), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.removeItem(2), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.removeItem(2), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.removeItem(4), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.removeItem(4), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.removeItem(1), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.removeItem(1), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.removeItem(5), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.removeItem(5), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.removeItem(0), L"RemoveFromMultipleItemList Does Not Exist Incorrect", LINE_INFO());
				Assert::IsNull(list.getHead(), L"RemoveFromMultipleItemList Head Incorrect", LINE_INFO());
				Assert::IsNull(list.getTail(), L"RemoveFromMultipleItemList Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"RemoveFromMultipleItemList getNbrOfNodes Incorrect", LINE_INFO());
			}
		}
	};

	TEST_CLASS(RemoveFromEmptyTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// RemoveFromEmpty Tests
		////////////////////////////////////////////////////////////////////////////////

		TEST_METHOD(removeFront_Empty)
		{
			try
			{
				DoublyLinkedList<int>list;
				list.removeFront();
			}
			catch (const string& e)
			{
				Assert::AreEqual(e, string("ERROR:  Cannot remove from an empty list"), L"RemoveFromEmpty Exception Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(removeBack_Empty)
		{
			try
			{
				DoublyLinkedList<int>list;
				list.removeBack();
			}
			catch (const string& e)
			{
				Assert::AreEqual(e, string("ERROR:  Cannot remove from an empty list"), L"RemoveFromEmpty Exception Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(removeItem_Empty)
		{
			DoublyLinkedList<int>list;
			Assert::AreEqual(false, list.removeItem(3), L"removeItem_Empty Incorrect", LINE_INFO());
		}
	};

	TEST_CLASS(searchTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// search Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(searchSingleItem)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			Assert::AreEqual(true, list.search(1), L"searchSingleItem Exists Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.search(0), L"searchSingleItem Does Not Exist Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"searchSingleItem Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"searchSingleItem Tail Incorrect", LINE_INFO());
			Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"searchSingleItem getNbrOfNodes Incorrect", LINE_INFO());
		}

		TEST_METHOD(searchMultipleItems)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			list.addFront(2);
			list.addFront(3);
			list.addFront(4);
			list.addFront(5);
			Assert::AreEqual(true, list.search(1), L"searchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.search(2), L"searchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.search(3), L"searchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.search(4), L"searchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.search(5), L"searchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.search(0), L"searchMultipleItems Does Not Exist Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"searchMultipleItems Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"searchMultipleItems Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"searchMultipleItems getNbrOfNodes Incorrect", LINE_INFO());
		}

	};

	TEST_CLASS(sizeTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// size Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(size_Empty)
		{
			DoublyLinkedList<int>list;
			Assert::IsNull(list.getHead(), L"size Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"size Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"size getNbrOfNodes Incorrect", LINE_INFO());
		}
		TEST_METHOD(size_100)
		{
			DoublyLinkedList<int>list;

			// Add 100 items to the list
			for (int i = 0; i < 100; ++i)
			{
				list.addFront(i);
				Assert::AreEqual(i + 1, list.getCount(), L"sizeAdd Count Incorrect", LINE_INFO());
				Assert::AreEqual(i + 1, list.size(), L"sizeAdd size Incorrect", LINE_INFO());
			}
			Assert::IsNotNull(list.getHead(), L"size Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"size Tail Incorrect", LINE_INFO());
			Assert::AreEqual(100, DoublyLinkedListNode<int>::getNbrOfNodes(), L"size getNbrOfNodes Incorrect", LINE_INFO());

			// Remove 100 items from the list
			for (int i = 99; i >= 0; --i)
			{
				int item = list.removeFront();
				Assert::AreEqual(item, i, L"sizeRemove Item Incorrect", LINE_INFO());
				Assert::AreEqual(i, list.getCount(), L"sizeRemove Count Incorrect", LINE_INFO());
				Assert::AreEqual(i, list.size(), L"sizeRemove size Incorrect", LINE_INFO());
			}
			Assert::IsNull(list.getHead(), L"size Head Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail(), L"size Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"size getNbrOfNodes Incorrect", LINE_INFO());
		}
	};

	TEST_CLASS(AssignmentOperatorTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// AssignmentOperator Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AssignmentOperator_Empty)
		{
			DoublyLinkedList<int>origList;
			DoublyLinkedList<int>newList = origList;

			Assert::AreEqual(0, newList.getCount(), L"AssignmentOperatorEmpty Count Incorrect", LINE_INFO());
			Assert::IsNull(newList.getHead(), L"AssignmentOperatorEmpty Head Incorrect", LINE_INFO());
			Assert::IsNull(newList.getTail(), L"AssignmentOperatorEmpty Tail Incorrect", LINE_INFO());
			Assert::IsNull(origList.getHead(), L"AssignmentOperatorEmpty Head Incorrect", LINE_INFO());
			Assert::IsNull(origList.getTail(), L"AssignmentOperatorEmpty Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperatorEmpty getNbrOfNodes Incorrect", LINE_INFO());
		}

		TEST_METHOD(AssignmentOperator_SingleItem)
		{
			DoublyLinkedList<int>origList;
			origList.addFront(1);
			DoublyLinkedList<int>newList = origList;

			Assert::AreEqual(1, newList.getCount(), L"AssignmentOperatorSingleItem Count Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());
			Assert::AreEqual(2, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperatorSingleItem getNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperatorSingleItem Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperatorSingleItem Output Incorrect", LINE_INFO());
			}

			{
				// Remove last item
				int item = newList.removeFront();
				Assert::AreEqual(1, item, L"AssignmentOperatorSingleItem Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperatorSingleItem getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperatorSingleItem Output Incorrect", LINE_INFO());
				Assert::IsNull(newList.getHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
				Assert::IsNull(newList.getTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(AssignmentOperator_MultipleItems)
		{
			DoublyLinkedList<int>origList;
			origList.addFront(1);
			origList.addFront(2);
			origList.addFront(3);
			origList.addFront(4);
			origList.addFront(5);

			DoublyLinkedList<int>newList = origList;

			Assert::AreEqual(5, newList.getCount(), L"AssignmentOperator Count Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreEqual(10, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove from one of the lists
				int item = newList.removeBack();
				Assert::AreEqual(1, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(9, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(5, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(8, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3->2....2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeBack();
				Assert::AreEqual(2, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(7, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3....3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(4, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(6, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "3....3";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(3, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
				Assert::IsNull(newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::IsNull(newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(AssignmentOperator_OverwriteExisting)
		{
			DoublyLinkedList<int>origList;
			DoublyLinkedList<int>newList;
			for (int i = 1; i < 6; ++i)
			{
				origList.addFront(i);
				newList.addBack(i);
			}

			newList = origList;

			Assert::AreEqual(5, newList.getCount(), L"AssignmentOperator Count Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::IsNotNull(newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreEqual(10, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove from one of the lists
				int item = newList.removeBack();
				Assert::AreEqual(1, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(9, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(5, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(8, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3->2....2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeBack();
				Assert::AreEqual(2, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(7, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3....3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(4, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(6, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "3....3";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				int item = newList.removeFront();
				Assert::AreEqual(3, item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperator getNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getHead(), (int)newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.getTail(), (int)newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
				Assert::IsNull(newList.getHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::IsNull(newList.getTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(AssignmentOperator_Self)
		{
			DoublyLinkedList<int>list;
			list.addFront(1);
			list.addFront(2);
			list.addFront(3);
			list.addFront(4);
			list.addFront(5);

			list = list;

			const DoublyLinkedListNode<int>* const headNext = list.getHead()->getNext();
			const DoublyLinkedListNode<int>* const tailPrev = list.getTail()->getPrev();
			Assert::AreEqual(5, list.getCount(), L"AssignmentOperatorSelf Count Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getHead(), L"AssignmentOperatorSelf Head Incorrect", LINE_INFO());
			Assert::IsNotNull(list.getTail(), L"AssignmentOperatorSelf Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<int>::getNbrOfNodes(), L"AssignmentOperatorSelf getNbrOfNodes Incorrect", LINE_INFO());
			Assert::IsNull(list.getHead()->getPrev(), L"AssignmentOperatorSelf Head->Prev Incorrect", LINE_INFO());
			Assert::IsNull(list.getTail()->getNext(), L"AssignmentOperatorSelf Tail->Next Incorrect", LINE_INFO());
			Assert::AreEqual((int)headNext, (int)list.getHead()->getNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual((int)tailPrev, (int)list.getTail()->getPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
		}
	};

	TEST_CLASS(InsertionOperatorTests)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Setup for each test method
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_INITIALIZE(Setup)
		{
			DoublyLinkedListNode<int>::resetNbrOfNodes();
		}

		////////////////////////////////////////////////////////////////////////////////
		// Insertion Operator Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(Insertion)
		{
			DoublyLinkedList<int>origList;
			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"Insertion Operator Incorrect", LINE_INFO());
			}

			for (int i = 1; i < 6; ++i)
			{
				origList.addFront(i);
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"Insertion Operator Incorrect", LINE_INFO());
			}
		}
	};
}
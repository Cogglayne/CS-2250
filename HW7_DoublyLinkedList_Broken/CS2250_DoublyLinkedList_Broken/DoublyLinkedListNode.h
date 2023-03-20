#include <iostream>

using namespace std;

#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H

class DoublyLinkedListNode
{
public:
	// Constructors
	DoublyLinkedListNode(void);       // Default
	DoublyLinkedListNode(const DoublyLinkedListNode& node);    // Copy
	DoublyLinkedListNode(int data);
	DoublyLinkedListNode(int data, DoublyLinkedListNode* prev, DoublyLinkedListNode* next);

	// Destructor
	~DoublyLinkedListNode(void);

	// Accessors/Inspectors
	int getData() const;
	DoublyLinkedListNode* getNext() const;
	DoublyLinkedListNode* getPrev() const;

	// Mutators/Manipulators
	void setData(int data);
	void setNext(DoublyLinkedListNode* next);
	void setPrev(DoublyLinkedListNode* prev);

	DoublyLinkedListNode& operator=(const DoublyLinkedListNode& list);
	friend ostream& operator<<(ostream& sout, const DoublyLinkedListNode& list);

	///////////////////////////////////////////////
	// DO NOT ALTER THESE METHODS
	///////////////////////////////////////////////
	// Accessors for TESTING ONLY
	static int getNbrOfNodes();
	static void resetNbrOfNodes();
	///////////////////////////////////////////////
	// END OF DO NOT ALTER
	///////////////////////////////////////////////

private:
	int m_data;             // node's item
	DoublyLinkedListNode* m_next; // next in list
	DoublyLinkedListNode* m_prev;

	///////////////////////////////////////////////
	// DO NOT ALTER THIS DATA
	///////////////////////////////////////////////
	// Static members for TESTING ONLY
	static int nbrOfNodes;
	///////////////////////////////////////////////
	// END OF DO NOT ALTER
	///////////////////////////////////////////////
};

#endif
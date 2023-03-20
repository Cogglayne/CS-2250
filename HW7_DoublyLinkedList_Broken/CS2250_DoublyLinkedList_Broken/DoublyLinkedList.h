#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedListNode.h"

class DoublyLinkedList
{
public:
	// Constructors & Destructor
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& list);
	~DoublyLinkedList();

	// Add methods
	void addFront(int item);
	void addBack(int item);

	// Remove methods
	int  removeFront();
	int  removeBack();
	bool removeItem(int item);

	// Facilitator methods
	bool search(int item) const;
	int  size() const;
	void printFullNodes() const;

	// Operators
	DoublyLinkedList& operator=(const DoublyLinkedList& rhsList);
	friend ostream& operator<<(ostream& sout, const DoublyLinkedList& list);

	//////////////////////////////////////////////////////////////////////////////
	// DO NOT MODIFY THESE METHODS
	//////////////////////////////////////////////////////////////////////////////
	// Accessors for TESTING ONLY
	const DoublyLinkedListNode* const & getHead() const;
	const DoublyLinkedListNode* const & getTail() const;
	int getCount() const;
	//////////////////////////////////////////////////////////////////////////////
	// END OF DO NOT MODIFY
	//////////////////////////////////////////////////////////////////////////////

private:
	DoublyLinkedListNode* searchNodes(int item) const;

	DoublyLinkedListNode* m_head;   // first node in list
	DoublyLinkedListNode* m_tail;   // last node in list
	int m_count;                    // number of nodes in list
};

#endif

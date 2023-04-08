#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedListNode.h"

template <class T>
class DoublyLinkedList;

template <class T>
ostream& operator<<(ostream& sout, const DoublyLinkedList<T>& list);

template <class T>
class DoublyLinkedList
{
public:
	// Constructors & Destructor
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>& list);
	~DoublyLinkedList();

	// Add methods
	void addFront(T item);
	void addBack(T item);

	// Remove methods
	T  removeFront();
	T  removeBack();
	bool removeItem(T item);

	// Facilitator methods
	bool search(T item) const;
	int  size() const;
	void printFullNodes() const;

	// Operators
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhsList);
	friend ostream& operator<< <>(ostream& sout, const DoublyLinkedList& list);

	//////////////////////////////////////////////////////////////////////////////
	// DO NOT MODIFY THESE METHODS
	//////////////////////////////////////////////////////////////////////////////
	// Accessors for TESTING ONLY
	const DoublyLinkedListNode<T>* const & getHead() const;
	const DoublyLinkedListNode<T>* const & getTail() const;
	int getCount() const;
	//////////////////////////////////////////////////////////////////////////////
	// END OF DO NOT MODIFY
	//////////////////////////////////////////////////////////////////////////////

private:
	DoublyLinkedListNode<T>* searchNodes(T item) const;

	DoublyLinkedListNode<T>* m_head;   // first node in list
	DoublyLinkedListNode<T>* m_tail;   // last node in list
	int m_count;                    // number of nodes in list
};

#include "DoublyLinkedList.cpp"

#endif

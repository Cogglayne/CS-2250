#include <iostream>

using namespace std;

#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H

template <class T>
class DoublyLinkedListNode;

template <class T>
ostream& operator<<(ostream& sout, const DoublyLinkedListNode<T>& list);

template <class T>
class DoublyLinkedListNode
{
public:
	// Constructors
	DoublyLinkedListNode(void);       // Default
	DoublyLinkedListNode(const DoublyLinkedListNode<T>& node);    // Copy
	DoublyLinkedListNode(T data);
	DoublyLinkedListNode(T data, DoublyLinkedListNode<T>* prev, DoublyLinkedListNode<T>* next);

	// Destructor
	~DoublyLinkedListNode(void);

	// Accessors/Inspectors
	T getData() const;
	DoublyLinkedListNode<T>* getNext() const;
	DoublyLinkedListNode<T>* getPrev() const;

	// Mutators/Manipulators
	void setData(T data);
	void setNext(DoublyLinkedListNode<T>* next);
	void setPrev(DoublyLinkedListNode<T>* prev);

	DoublyLinkedListNode<T>& operator=(const DoublyLinkedListNode<T>& list);
	friend ostream& operator<< <>(ostream& sout, const DoublyLinkedListNode<T>& list);

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
	T m_data;             // node's item
	DoublyLinkedListNode<T>* m_next; // next in list
	DoublyLinkedListNode<T>* m_prev;

	///////////////////////////////////////////////
	// DO NOT ALTER THIS DATA
	///////////////////////////////////////////////
	// Static members for TESTING ONLY
	static int nbrOfNodes;
	///////////////////////////////////////////////
	// END OF DO NOT ALTER
	///////////////////////////////////////////////
};

#include "DoublyLinkedListNode.cpp"

#endif
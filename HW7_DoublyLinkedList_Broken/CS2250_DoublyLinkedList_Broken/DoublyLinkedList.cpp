#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include "DoublyLinkedList.h"

//////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THESE METHODS
//////////////////////////////////////////////////////////////////////////////
// Accessors for TESTING ONLY

// GetHead - returns the head as a constant pointer to constant data, 
// allowing the calling function to verify that the elements of the list
// are correct without altering the list in any way
template <class T>
const DoublyLinkedListNode<T>* const & DoublyLinkedList<T>::getHead() const
{
    return m_head;
}

// GetTail - returns the tail as a constant pointer to constant data, 
// allowing the calling function to verify that the elements of the list
// are correct without altering the list in any way
template <class T>
const DoublyLinkedListNode<T>* const & DoublyLinkedList<T>::getTail() const
{
    return m_tail;
}

template <class T>
// GetCount - returns the count as an int to verify its value
int DoublyLinkedList<T>::getCount() const
{
    return m_count;
}
//////////////////////////////////////////////////////////////////////////////
// END OF DO NOT MODIFY
//////////////////////////////////////////////////////////////////////////////

// Default Constructor
// Initializes first and last pointers to nullptr (empty list)
// Sets number of nodes to zero
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    m_count = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

// Copy Constructor
// Iterates through the parameter list, adding each node to
// the "this" list, in order
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list)
{
    // intialize to empty list
    m_count = 0;
    m_head = nullptr;
    m_tail = nullptr;

    DoublyLinkedListNode<T>* curr = list.m_head;

    // copies from the other list if the other list is not empty
    while (curr != nullptr)
    {
        addBack(curr->getData());
        curr = curr->getNext();
    }
}

// Destructor
// Destroys any remaining nodes in the list
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DoublyLinkedListNode<T>* curr = m_head;

    // while there are still nodes
    while (curr != nullptr)
    {
        // get next node
        DoublyLinkedListNode<T>* next = curr->getNext();

        // delete current node
        delete curr;

        // set the current node to the next node
        curr = next;
    }

    // set head and tail to nullptr
    m_head = nullptr;
    m_tail = nullptr;
}

// AddFront - adds the item to the front of the list
template <class T>
void DoublyLinkedList<T>::addFront( T item )
{
    if (m_head == nullptr)
    {
        // Set the head and tail to point to only node
        m_head = new DoublyLinkedListNode<T>(item);
        m_tail = m_head;
    }
    else
    {
        // Create a new node
        DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>(item);

        // Connect the new node to the front of the list
        newNode->setNext(m_head);
        m_head->setPrev(newNode);

        // Set the head to point to new node
        m_head = newNode;
    }

    ++m_count;
}

// AddBack - adds the item to the back of the list
template <class T>
void DoublyLinkedList<T>::addBack( T item )
{
    if (m_tail == nullptr)
    {
        // Set the head and tail to point to only node
        m_tail = new DoublyLinkedListNode<T>(item);
        m_head = m_tail;
    }
    else
    {
        // Create a new node
        DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>(item);

        // Connect the new node to the back of the list
        newNode->setPrev(m_tail);
        m_tail->setNext(newNode);

        // Set the tail to point to new node
        m_tail = newNode;
    }

    ++m_count;
}

// RemoveFront - removes the first item in the list
// Returns the value stored in the first item in the list
// Displays an error if the list is empty
template <class T>
T DoublyLinkedList<T>::removeFront()
{
    // If there are no items in the list
    if (m_head == nullptr)
    {
		throw string("ERROR:  Cannot remove from an empty list");
	}
    // If there at least one item
    else if(m_head == m_tail)
    {
        // Store data to be removed
        T data = m_head->getData();

        // delete the only node
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        --m_count;

        return data;
    }
    // more than one item
    else
    {
        // Store data to be removed
        T data = m_head->getData();

        // create a pointer to the node being removed
        DoublyLinkedListNode<T>* curr = m_head;

        // set head to next node
        m_head = curr->getNext();

        // fix new head's node pointer
        m_head->setPrev(nullptr);

        // delete old head node
        delete curr;

        --m_count;
        
        return data;
    }
}

// RemoveBack - removes the last item in the list
// Returns the value stored in the last item in the list
// Displays an error if the list is empty
template <class T>
T DoublyLinkedList<T>::removeBack()
{
    // If there are no items in the list
    if (m_tail == nullptr)
    {
		throw string("ERROR:  Cannot remove from an empty list");
	}
    // If there at least one item
    else if (m_head == m_tail)
    {
        // Store data to be removed
        T data = m_head->getData();

        // delete the only node
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        --m_count;

        return data;
    }
    // more than one item
    else
    {
        // Store data to be removed
        T data = m_tail->getData();

        // create a pointer to the node being removed
        DoublyLinkedListNode<T>* curr = m_tail;

        // set head to next node
        m_tail = curr->getPrev();

        // fix new head's node pointer
        m_tail->setNext(nullptr);

        // delete old head node
        delete curr;

        --m_count;

        return data;
    }
}

// RemoveItem - removes first match to the parameter
// Returns true if the item was found and removed, false otherwise
template <class T>
bool DoublyLinkedList<T>::removeItem(T item)
{
    DoublyLinkedListNode<T>* curr = searchNodes(item);

    // If item was not found or list is empty
    if (curr == nullptr)
    {
        return false;
    }
    // remove at front
    else if (curr == m_head)
    {
        removeFront();
    }
    // remove at end
    else if (curr == m_tail)
    {
        removeBack();
    }
    // remove in the middle
    else
    {
        curr->getNext()->setPrev(curr->getPrev());
        curr->getPrev()->setNext(curr->getNext());
        
        delete curr;

        --m_count;
    }

    return true;
}

// Search - searches for the parameter
// Returns true if the item is found, false otherwise
template <class T>
bool DoublyLinkedList<T>::search(T item) const
{
    DoublyLinkedListNode<T>* curr = searchNodes(item);

    if (curr != nullptr)
    {
        return true;
    }

    return false;
}

// SearchNodes - searches for the parameter and returns its node
// Returns nullptr if the item was not found
template <class T>
DoublyLinkedListNode<T>* DoublyLinkedList<T>::searchNodes(T item) const
{
    // if there are no nodes nullptr is returned
    if (m_count == 0)
    {
        return nullptr;
    }

    DoublyLinkedListNode<T>* curr = m_head;

    // Iterate through the list of nodes
    while (curr != nullptr)
    {
        // If this node's data matches the parameter
        // return it
        if (curr->getData() == item)
            return curr;

        // got to next node
        curr = curr->getNext();
    }

    // Item was not found, return nullptr
    return nullptr;
}

// Size - returns the number of items in the list
template <class T>
int DoublyLinkedList<T>::size() const
{
    return m_count;
}

////////////////////////////////////////////////////////////////////////////////////
// THERE ARE NO INTENTIONAL ERRORS TO ANY METHODS BELOW THIS LINE
// USE THESE TO HELP YOU DEBUG
// ASSUMING YOUR LIST IS SET UP CORRECTLY, THESE WILL WORK
////////////////////////////////////////////////////////////////////////////////////

// Method for debugging the list, prints as many nodes
// as it can find up to the count (prevents infinite
// looping from pointer errors!).  Displays memory
// location and node values
template <class T>
void DoublyLinkedList<T>::printFullNodes() const
{
	cout << "Head: " << m_head << endl;

	int cnt = 0;
	DoublyLinkedListNode<T>* curr = m_head;
	while (curr != nullptr && cnt++ <= m_count)
	{
		cout << "Node: " << curr << " " << *curr << endl;
		curr = curr->getNext();
	}
	cout << "Tail: " << m_tail << endl;
}

// operator<< displays the list in a reasonable format
// Displays the nodes forward and backward (to check both
// directions of pointers)
template <class T>
ostream& operator<<(ostream& sout, const DoublyLinkedList<T>& list)
{
	DoublyLinkedListNode<T>* curr = list.m_head;

	// If the list is empty, display an appropriate message
	if (curr == nullptr)
	{
		sout << "EMPTY LIST";
		return sout;
	}

	// Display the first node
	sout << curr->getData();
	curr = curr->getNext();

	// While there are more nodes
	while (curr != nullptr)
	{
		// Display an arrow (pointer!) and the next node
		sout << "->" << curr->getData();
		curr = curr->getNext();
	}

	// Do it backwards!
	curr = list.m_tail;
	sout << "....";

	// If there are no nodes, display an appropriate message
	if (curr == nullptr)
	{
		sout << "EMPTY LIST";
		return sout;
	}

	// Display the last node
	sout << curr->getData();
	curr = curr->getPrev();

	// While there are more nodes, display them
	while (curr != nullptr)
	{
		// Display an arrow (pointer!) and the next node
		sout << "->" << curr->getData();
		curr = curr->getPrev();
	}

	// Return the stream
	return sout;
}

template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhsList)
{
	// If this is NOT the same object as rs
	if (this != &rhsList)
	{
		while (m_count > 0)
		{
			removeFront();
		}
		// Iterator for parameter list, start at first node
		DoublyLinkedListNode<T>* curr = rhsList.m_head;

		// While there are still nodes left
		while (curr != nullptr)
		{
			// Add the current node
			addBack(curr->getData());

			// Go to the next node
			curr = curr->getNext();
		}
	}

	return *this;
}

#endif
#include "HTArray.h"

	//default constructor
HTArray::HTArray()
{
	capacity = DEFAULT_CAP;
	numOfElements = 0;
	ht = new LinkedList*[capacity];			// This creates an array of pointers that point to
											// objects of the LinkedList class. The pointer ht
											// points to the array.

	// create a linked list for each index
	for (int i = 0; i < capacity; ++i)
	{
		LinkedList *ptrList = new LinkedList;
		ht[i] = ptrList;
	}
}

//overloaded constructor
HTArray::HTArray(int newCapacity)
{
	capacity = newCapacity;
	numOfElements = 0;
	ht = new LinkedList*[capacity];

	for (int i = 0; i < capacity; ++i)
	{
		LinkedList *ptrList = new LinkedList;
		ht[i] = ptrList;
	}
}

//hashValue
int HTArray::hashValue(int key) const
{
	return (key % capacity);
}

//addElement
void HTArray::addElement(int num)
{
	int indx = hashValue(num);
	ht[indx]->insertBack(num);
	++numOfElements;
}

//getNumOfElements
int HTArray::getNumOfElements() const
{
	return numOfElements;
}

//searchKey
bool HTArray::searchKey(int key) const
{
	if (numOfElements == 0)
		cerr << "There are no elements in the hash table.";
	else
	{
		int indx = hashValue(key);
		return ht[indx]->search(key);
	}
	return false;
}

//printHashTable
void HTArray::printHashTable() const
{
	for (int i = 0; i < capacity; ++i)
	{
		cout << "IDX " << i << ": ";
		ht[i]->printList();
		cout << endl;
	}
	cout << endl;
}

//destructor
HTArray::~HTArray()
{
	for (int i = 0; i < capacity; ++i)
	{
		ht[i]->~LinkedList();
	}
	delete[] ht;
}

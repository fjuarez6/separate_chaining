#ifndef HTARRAY_H
#define HTARRAY_H

#include "LinkedList.h"

#include <iostream>
using namespace std;

const int DEFAULT_CAP = 10;

class HTArray
{
public:
    HTArray( );


	//overloaded constructor
	HTArray(int newCapacity);

	//hashValue
	int hashValue(int key) const;

	//addElement
	void addElement(int num);

	//getNumOfElements
	int getNumOfElements() const;

	//searchKey
	bool searchKey(int key) const;

	//printHashTable
	void printHashTable() const;

	//destructor
	~HTArray();

private:
    LinkedList **ht;		//a pointer that points to a hash table of pointers
							//   pointing to linked lists
    int capacity;			//capacity of the hash table
    int numOfElements;		//total number of elements in the hash table

};

#endif
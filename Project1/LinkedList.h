#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include <string>		//Need to include for NULL			
using namespace std;

class Node
{
public:
	Node(){}
    Node(int theData, Node *theLink) : data(theData), link(theLink){}
    Node* getLink( ) const { return link; }
	int getData( ) const { return data; }
    void setData(int theData) { data = theData; }
    void setLink(Node *theLink) { link = theLink; }
	~Node(){}
private:
    int data;		
    Node *link;	//pointer that points to next node
};


class LinkedList
{
public:

	//default constructor
	LinkedList();

	//insertBack
	void insertBack(int num);

	//getFirst
	Node* getFirst() const;

	//search
	bool search(int num) const;

	//printList
	void printList() const;

	//destructor
	~LinkedList();

private:
	Node *first; // pointer to point to the first node in the list
	Node *back;  // pointer to point to the last node in the list
	int count;	 // keeps track of number of nodes in the list
};

#endif
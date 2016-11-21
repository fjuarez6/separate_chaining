#include "LinkedList.h"

//default constructor
LinkedList::LinkedList()
{
	first = nullptr;
	back = nullptr;
	count = 0;
}

//insertBack
void LinkedList::insertBack(int num)
{
	if (count == 0)
	{
		first = new Node(num, nullptr);
		back = first;
	}
	else
	{
		back->setLink(new Node(num, nullptr));
		back = back->getLink();
	}
	++count;
}

//getFirst
Node* LinkedList::getFirst() const
{
	return first;
}

//search
bool LinkedList::search(int num) const
{
	if (count == 0)
		cerr << "List is empty.";
	else
	{
		bool found = false;
		Node *temp = first;

		while (temp != nullptr && !found)
		{
			if (temp->getData() == num)
			{
				found = true;
				return found;
			}
			else
				temp = temp->getLink();
		}
	}
	return false;
}

//printList
void LinkedList::printList() const
{
	Node *temp = first;

	while (temp != nullptr)
	{
		cout << temp->getData() << " ";
		temp = temp->getLink();
	}
}

//destructor
LinkedList::~LinkedList()
{
	Node *temp;
	while (first != nullptr)
	{
		temp = first;
		first = first->getLink();
		delete temp;
		temp = nullptr;
	}
}


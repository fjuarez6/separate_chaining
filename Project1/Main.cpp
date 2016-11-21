#include "HTArray.h"

#include <iostream>
using namespace std;

void searchKey(const HTArray& ht, int key);

int main()
{
	HTArray ht;
	ht.addElement(5);
	ht.addElement(7);
	ht.addElement(45);
	ht.addElement(20);
	ht.addElement(25);

	ht.printHashTable();

	searchKey(ht, 20);
	searchKey(ht, 25);
	searchKey(ht, 45);
	searchKey(ht, 7);
	searchKey(ht, 5);
	searchKey(ht, 100);

	cout << endl;
	system("Pause");
	return 0;
}

void searchKey(const HTArray& ht, int key)
{
	if (ht.searchKey(key))
		cout << "Key " << key << " found." << endl;
	else
		cout << "Key " << key << " not found." << endl;
}
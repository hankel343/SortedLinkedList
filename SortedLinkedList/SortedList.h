#ifndef SORTED_H
#define SORTED_H
#include <cstdlib>
#include <new>
#include <iostream>
#include "ItemType.h"

class EmptyList {};

struct Node
{
	ItemType iData;
	Node* pNext;
};

class SortedList
{
private:
	Node* pList;
	int nLength;
	Node* pCurrentPos;

public:
	SortedList();
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	void MakeEmpty();
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();
	void Display();
	~SortedList();
};

#endif SORTED_H
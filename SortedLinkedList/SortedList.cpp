#include "SortedList.h"

SortedList::SortedList()
{
	pList = NULL;
	nLength = 0;
	pCurrentPos = NULL;
}

bool SortedList::IsEmpty() const
{
	return (pList == NULL);
}

bool SortedList::IsFull() const
{
	try
	{
		Node* pTemp = new Node;
		delete pTemp;
		return false;
	} catch (std::bad_alloc exception) {
		return true;
	}
}

int SortedList::GetLength() const
{
	return nLength;
}

void SortedList::MakeEmpty()
{
	Node* pTemp;
	while (pList != NULL)
	{
		pTemp = pList;
		pList = pList->pNext;
		delete pTemp;
	}
}

ItemType SortedList::GetItem(ItemType item, bool& found)
{
	Node* pTemp = pList;
	found = false;

	while (pTemp != NULL)
	{
		switch (pTemp->iData.ComparedTo(item))
		{
		case EQUAL:		found = true;
						return pTemp->iData;

		default:		pTemp = pTemp->pNext;
						break;
		}
	}

	return item;	//If item is not found in the list, the original item 
					//is returned and the found flag is still set to false.
}

void SortedList::PutItem(ItemType item)
{
	if (IsFull()); //IsFull() throws an exception if the list is full.

	//Allocate memory for the new node:
	Node* pNewNode = new Node;
	pNewNode->iData = item;
	pNewNode->pNext = NULL;

	//Allocate memory for list traversal pointers:
	Node* pLoc = pList;
	Node* pPrevLoc = NULL;

	bool bMoreToSearch = (pLoc != NULL);
	while (bMoreToSearch)
	{
		switch (item.ComparedTo(pLoc->iData))
		{
		case LESS:		bMoreToSearch = false;
						break; 

		default:		pPrevLoc = pLoc;
						pLoc = pLoc->pNext;
						bMoreToSearch = (pLoc != NULL);
						break;
		}
	}

	if (pPrevLoc == NULL) {	//If list was empty to begin with:
		pNewNode->pNext = pList;
		pList = pNewNode;
	} else {	//If list already contained elements:
		pPrevLoc->pNext = pNewNode; //Previous node now points to new node.
		pNewNode->pNext = pLoc;		//New node make connection to the next node.
	}

	nLength++;
}

void SortedList::DeleteItem(ItemType item)
{
	if (IsEmpty() == true)
		throw EmptyList();

	//Create list traversal pointers:
	Node* location = pList;
	Node* tempLocation;

	if (item.ComparedTo(pList->iData) == EQUAL)
	{
		tempLocation = location;
		pList = pList->pNext;
	} else {
		while ((item.ComparedTo(location->pNext->iData) != EQUAL))
			location = location->pNext;
		tempLocation = location->pNext;
		location->pNext = (location->pNext)->pNext;
	}

	delete tempLocation;
	nLength--;
}

void SortedList::ResetList()
{
	pCurrentPos = pList; //Return current position pointer to the beginning of the list.
}

ItemType SortedList::GetNextItem()
{
	pCurrentPos = pCurrentPos->pNext;
	return pCurrentPos->iData;
}

void SortedList::Display()
{
	Node* pTemp = pList;
	while (pTemp != NULL)
	{
		std::cout << pTemp->iData.Get() << " ";
		pTemp = pTemp->pNext;
	}
}

SortedList::~SortedList()
{
	MakeEmpty();
}

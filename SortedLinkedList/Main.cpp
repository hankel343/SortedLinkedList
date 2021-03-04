#include <iostream>
#include "SortedList.h"

using namespace std;

int main()
{
	SortedList list;
	ItemType iTemp;
	ItemType iReturnedItem;
	bool found;

	int nums[] = { 2, 1, 0, -7, 5, 5, 15 };

	for (int i = 0; i < 7; i++)
	{
		iTemp.Set(nums[i]);
		list.PutItem(iTemp);
	}

	cout << "Full list: \n";
	list.Display();

	cout << "\n\nDeleting 2 from the list:\n";
	iTemp.Set(2);
	list.DeleteItem(iTemp);
	list.Display();

	cout << "\n\nGetting an item.\n";
	iTemp.Set(16);
	iReturnedItem = list.GetItem(iTemp, found);
	if (found) {
		cout << iReturnedItem.Get() << " was found in the list.\n";
	} else {
		cout << iTemp.Get() << " was not found in the list.\n";
	}




	return 0;
}
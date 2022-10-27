//------------------------------------------------------------------------------
// app.cpp : LinkedList class demo
//------------------------------------------------------------------------------
#include <iostream>

#include "LinkedList.h"

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	// local LinkedList class instance declaration allocates stack memory
	LinkedList myList;

	// add some list items, each one becomes the new list head

	myList.addItem(1);
	myList.addItem(2);
	myList.addItem(3);
	myList.addItem(4);
	myList.addItem(5);

	bool deleted;
	
	deleted = myList.deleteItem(3);

	deleted = myList.deleteItem(1);

	// display each list item

	//-----------------------------------------------------------------------------
	// even though it's overkill here since we just added 5 Nodes to the list,
	// it's _always a good idea to check list status before walking the list
	//-----------------------------------------------------------------------------
	if (myList.isEmpty()) {
		return 0;
	}

	// reset list position pointer to list head
	//-----------------------------------------------------------------------------
	// You have to do this because 
	//		a) each .putItem() call changes myList's Position pointer, and
	//		b) the .viewItem() call we need next uses that same Position pointer.
	// 
	// This list design could be easier to use...what might "easier" look like?
	//-----------------------------------------------------------------------------
	myList.gotoHead();

	do {
		std::cout << myList.viewItem() << '\n';
	} while (myList.gotoNext());
	//-----------------------------------------------------------------------------
	// iterate() advances the Position pointer to the next list item
	//-----------------------------------------------------------------------------

	// release heap memory
	myList.makeEmpty();

	// good c++itizen
	return 0;
}
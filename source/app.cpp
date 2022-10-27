//------------------------------------------------------------------------------
// app.cpp : LinkedList class demo
//------------------------------------------------------------------------------
#include <iostream>

#include "LinkedList.h"

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	LinkedList myList;

	myList.putItem(1);
	myList.putItem(2);
	myList.putItem(3);
	myList.putItem(4);
	myList.putItem(5);

	myList.MakeEmpty();

	return 0;
}
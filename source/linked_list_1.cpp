#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList myList;

	myList.putItem(1);
	myList.putItem(2);
	myList.putItem(3);
	myList.putItem(4);
	myList.putItem(5);
	myList.MakeEmpty();

	return 0;
}
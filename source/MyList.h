#pragma once
#include <iostream>

class MyList
{
private:
	static const int StartSize = 10;
	int *listArray;
	int maxSize;
	int size;

public:
	MyList();
	void putItem(int);
	void deleteItem(int);
	int searchItem(int);//returns -99 when not found
	void clearList();
	bool isFull();
	int getLength();
	void viewList();

	~MyList();
};


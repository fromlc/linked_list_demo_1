#include "MyList.h"

MyList::MyList()
{
	listArray = new int[StartSize];
	maxSize = StartSize;
	size = 0;
}

void MyList::putItem(int n)
{
	if(!isFull())
	{ 
		listArray[size] = n;
		size++;
	}

}

void MyList::deleteItem(int n)
{
	int position = searchItem(n);

	if (position != -99)
	{
		for (int i = position; i < size-1; ++i)
		{
			listArray[i] = listArray[i + 1];
			//std::cout << std::endl;
			//viewList();

		}
		size--;
	}

}

int MyList::searchItem(int n)
{
	for (int i = 0; i < size; ++i)
	{
		if (listArray[i] == n)
		{
			return i;
		}
	}
	return -99;
}

void MyList::clearList()
{
	size = 0;
}

bool MyList::isFull()
{
	if(size<maxSize)
		return false;

	return true;
}

int MyList::getLength()
{
	return size;
}

void MyList::viewList()
{

	if (size < 1)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
		for (int i = 0; i < size; ++i)
		{
			std::cout << listArray[i] << " ";
		}
}

MyList::~MyList()
{
	delete listArray;
}

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

		if (size == 0)
		{
			listArray[size] = n;
			size++;
		}
		else
		{
			bool found = false;
			for (int i = 0; i < size && found == false; ++i)
			{
				if (n < listArray[i])
				{
					for (int j = size; j > i; --j)
						listArray[j] = listArray[j - 1];
					listArray[i] = n;
					size++;
					found = true;
				}
			}

			if (found == false)
			{
				listArray[size] = n;
				size++;
			}

		}


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
